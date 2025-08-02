/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *setIDBtn;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSlider *setposSlider;
    QSpinBox *writeValue;
    QLabel *label_2;
    QSlider *currentposSlider;
    QSpinBox *writeReg;
    QPushButton *readByteBtn;
    QSpinBox *setposSpin;
    QSpinBox *regSpinbox;
    QCheckBox *enableTorque;
    QLabel *labelPos;
    QPushButton *writeByteBtn;
    QLabel *labelReadByte;
    QSpinBox *setIdEdit;
    QSpinBox *currentID;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *serialPortCombo;
    QPushButton *btnRefreshPorts;
    QPushButton *btnDefParams;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/icon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        setIDBtn = new QPushButton(centralWidget);
        setIDBtn->setObjectName("setIDBtn");

        gridLayout->addWidget(setIDBtn, 7, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        setposSlider = new QSlider(centralWidget);
        setposSlider->setObjectName("setposSlider");
        setposSlider->setMaximum(1023);
        setposSlider->setTracking(false);
        setposSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(setposSlider, 2, 1, 1, 1);

        writeValue = new QSpinBox(centralWidget);
        writeValue->setObjectName("writeValue");
        writeValue->setMaximum(255);

        gridLayout->addWidget(writeValue, 6, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        currentposSlider = new QSlider(centralWidget);
        currentposSlider->setObjectName("currentposSlider");
        currentposSlider->setEnabled(false);
        currentposSlider->setMinimum(-1);
        currentposSlider->setMaximum(1023);
        currentposSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(currentposSlider, 3, 1, 1, 1);

        writeReg = new QSpinBox(centralWidget);
        writeReg->setObjectName("writeReg");

        gridLayout->addWidget(writeReg, 6, 0, 1, 1);

        readByteBtn = new QPushButton(centralWidget);
        readByteBtn->setObjectName("readByteBtn");

        gridLayout->addWidget(readByteBtn, 5, 3, 1, 1);

        setposSpin = new QSpinBox(centralWidget);
        setposSpin->setObjectName("setposSpin");
        setposSpin->setMaximum(1023);

        gridLayout->addWidget(setposSpin, 2, 3, 1, 1);

        regSpinbox = new QSpinBox(centralWidget);
        regSpinbox->setObjectName("regSpinbox");

        gridLayout->addWidget(regSpinbox, 5, 0, 1, 1);

        enableTorque = new QCheckBox(centralWidget);
        enableTorque->setObjectName("enableTorque");

        gridLayout->addWidget(enableTorque, 4, 1, 1, 1);

        labelPos = new QLabel(centralWidget);
        labelPos->setObjectName("labelPos");

        gridLayout->addWidget(labelPos, 3, 3, 1, 1);

        writeByteBtn = new QPushButton(centralWidget);
        writeByteBtn->setObjectName("writeByteBtn");

        gridLayout->addWidget(writeByteBtn, 6, 3, 1, 1);

        labelReadByte = new QLabel(centralWidget);
        labelReadByte->setObjectName("labelReadByte");

        gridLayout->addWidget(labelReadByte, 5, 1, 1, 1);

        setIdEdit = new QSpinBox(centralWidget);
        setIdEdit->setObjectName("setIdEdit");
        setIdEdit->setMinimum(1);

        gridLayout->addWidget(setIdEdit, 7, 1, 1, 1);

        currentID = new QSpinBox(centralWidget);
        currentID->setObjectName("currentID");
        currentID->setMinimum(1);

        gridLayout->addWidget(currentID, 0, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        serialPortCombo = new QComboBox(centralWidget);
        serialPortCombo->setObjectName("serialPortCombo");

        gridLayout->addWidget(serialPortCombo, 1, 1, 1, 1);

        btnRefreshPorts = new QPushButton(centralWidget);
        btnRefreshPorts->setObjectName("btnRefreshPorts");

        gridLayout->addWidget(btnRefreshPorts, 1, 3, 1, 1);

        btnDefParams = new QPushButton(centralWidget);
        btnDefParams->setObjectName("btnDefParams");

        gridLayout->addWidget(btnDefParams, 9, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Feetech Servo GUI", nullptr));
        setIDBtn->setText(QCoreApplication::translate("MainWindow", "Set ID", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Set Pos", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Current Pos", nullptr));
        readByteBtn->setText(QCoreApplication::translate("MainWindow", "Read Byte", nullptr));
        enableTorque->setText(QCoreApplication::translate("MainWindow", "Torque Enabled", nullptr));
        labelPos->setText(QString());
        writeByteBtn->setText(QCoreApplication::translate("MainWindow", "Write Byte", nullptr));
        labelReadByte->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Current ID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Serial Port", nullptr));
        btnRefreshPorts->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        btnDefParams->setText(QCoreApplication::translate("MainWindow", "Set default params", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
