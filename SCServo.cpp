/*
 * SCServo.cpp
 * Ӳ��ͨ�Žӿ�
 * ����: 2016.8.9
 * ����: ̷����
 */


#include "SCServo.h"

#include <QDebug>

SCServo::SCServo()
{
	IOTimeOut = 2;
    pSerial.setBaudRate(1000000);
}

int SCServo::readSCS(unsigned char *nDat, int nLen)
{
    int readSize = 0;

    readSize += pSerial.read((char*)nDat + readSize, nLen - readSize);

    while (readSize < nLen) {
        if(!pSerial.waitForReadyRead(1))
            return 0;
        readSize += pSerial.read((char*)nDat + readSize, nLen - readSize);
    }

    return readSize;
}

int SCServo::writeSCS(unsigned char *nDat, int nLen)
{
    int n = pSerial.write((char*)nDat, nLen);
    pSerial.waitForBytesWritten();
    return n;
}

int SCServo::writeSCS(unsigned char bDat)
{
    int n = pSerial.write((char*)&bDat, 1);
    pSerial.waitForBytesWritten();
    return n;
}

void SCServo::flushSCS()
{
    pSerial.readAll();
}

bool SCServo::setSerialPort(const QString& portName)
{
    closeSerial();
    pSerial.setPortName(portName);
    bool success = pSerial.open(QIODevice::ReadWrite);
    qDebug() << "Serial port" << portName << "isOpen:" << success;
    return success;
}

void SCServo::closeSerial()
{
    if (pSerial.isOpen()) {
        pSerial.close();
    }
}

bool SCServo::isConnected() const
{
    return pSerial.isOpen();
}
