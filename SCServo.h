/*
 * SCServo.h
 * Ӳ��ͨ�Žӿ�
 * ����: 2016.8.25
 * ����: ̷����
 */

#ifndef _SCSERVO_H
#define _SCSERVO_H

#include "SCSProtocol.h"

#include <QSerialPort>

class SCServo : public SCSProtocol
{
public:
	SCServo(void);
        virtual int writeSCS(unsigned char *nDat, int nLen);
        virtual int readSCS(unsigned char *nDat, int nLen);
        virtual int writeSCS(unsigned char bDat);
        virtual void flushSCS();
        bool setSerialPort(const QString& portName);
        void closeSerial();
        bool isConnected() const;
public:
        unsigned long int IOTimeOut;
        QSerialPort pSerial;
};

#endif
