#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QtGlobal>
#include <QMessageBox>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    refreshSerialPorts();

    qDebug() << "P_CW_DEAD" << servo.readByte(getID(), P_CW_DEAD);
    qDebug() << "P_CCW_DEAD" << servo.readByte(getID(), P_CCW_DEAD);

    qDebug() << "P_MAX_TORQUE_L" << servo.readWord(getID(), P_MAX_TORQUE_L);

    for(int i = 28; i < 40; i++) {
        qDebug() << "read" << i << servo.readByte(getID(), i);
    }



    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this] {
        auto pos = servo.ReadPos(getID());
        ui->currentposSlider->setValue(pos);
        ui->labelPos->setText(QString::number(pos));
    });
    timer->start(100);

    connect(ui->setposSlider, &QSlider::valueChanged, this, [this](int value) {
        servo.WritePos(getID(), value, 500);
    });

    connect(ui->setposSpin, &QSpinBox::editingFinished, this, [this]() {
        servo.WritePos(getID(), ui->setposSpin->value(), 500);
    });

    connect(ui->enableTorque, &QCheckBox::toggled, this, [this](bool enabled) {
       servo.EnableTorque(getID(), enabled? 1 : 0);
    });

    connect(ui->readByteBtn, &QPushButton::clicked, this, [this] {
       ui->labelReadByte->setText(QString::number(servo.readByte(getID(), ui->regSpinbox->value())));
    });

    connect(ui->regSpinbox, &QSpinBox::editingFinished, this, [this] {
       ui->labelReadByte->setText(QString::number(servo.readByte(getID(), ui->regSpinbox->value())));
    });

    connect(ui->regSpinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [this] {
        ui->labelReadByte->clear();
    });

    connect(ui->writeByteBtn, &QPushButton::clicked, this, [this] {
       servo.writeByte(getID(), ui->writeReg->value(), ui->writeValue->value());
    });

    connect(ui->setIDBtn, &QPushButton::clicked, this, [this] {
          if (QMessageBox::warning(this, "Set ID", "Really change servo ID?",
                                    QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
            servo.writeByte(getID(), P_LOCK, 0);
            servo.writeByte(getID(), P_ID, ui->setIdEdit->value());
            servo.writeByte(getID(), P_LOCK, 1);
          }
    });

    connect(ui->btnDefParams, &QPushButton::clicked, this, [this] {
        servo.writeByte(getID(), P_CCW_DEAD, 0);
        servo.writeByte(getID(), P_CW_DEAD, 0);

        servo.writeByte(getID(), P_COMPLIANCE_P, 25); // P
        servo.writeByte(getID(), P_COMPLIANCE_I, 25); // I

        servo.writeWord(getID(), P_INTEGRAL_LIMIT_L, 70); // max Isum

        servo.writeByte(getID(), 30, 5);
        servo.writeByte(getID(), 31, 5);
        servo.writeByte(getID(), 32, 5);
    });

    connect(ui->btnRefreshPorts, &QPushButton::clicked, this, &MainWindow::refreshSerialPorts);
    connect(ui->serialPortCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::connectToSelectedPort);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getID()
{
    return ui->currentID->value();
}

void MainWindow::refreshSerialPorts()
{
    ui->serialPortCombo->clear();
    
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        QString portName = info.portName();
        
#ifdef Q_OS_MACOS
        if (portName.startsWith("cu.") || portName.startsWith("tty.")) {
            ui->serialPortCombo->addItem("/dev/" + portName, "/dev/" + portName);
        }
#else
        if (portName.startsWith("ttyUSB") || portName.startsWith("ttyACM")) {
            ui->serialPortCombo->addItem("/dev/" + portName, "/dev/" + portName);
        }
#endif
    }
    
    int servoPortIndex = ui->serialPortCombo->findData("/dev/cu.usbmodem5A680113791");
    if (servoPortIndex >= 0) {
        ui->serialPortCombo->setCurrentIndex(servoPortIndex);
        connectToSelectedPort();
    }
}

void MainWindow::connectToSelectedPort()
{
    QString selectedPort = ui->serialPortCombo->currentData().toString();
    if (!selectedPort.isEmpty()) {
        if (servo.setSerialPort(selectedPort)) {
            statusBar()->showMessage("Connected to " + selectedPort, 2000);
        } else {
            statusBar()->showMessage("Failed to connect to " + selectedPort, 2000);
        }
    }
}
