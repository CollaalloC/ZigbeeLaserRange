#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ZigbeeLaserRange.h"
#include <QSerialPort>
#include <QSerialPortInfo>


class ZigbeeLaserRange : public QMainWindow
{
    Q_OBJECT

private:
    Ui::ZigbeeLaserRangeClass ui;
    QSerialPort* serialPort;
    //���ڲ����ṹ��
    struct SerialPortConfig
    {
        QSerialPort::BaudRate BaudRateArray[5] = { QSerialPort::Baud1200, QSerialPort::Baud2400, QSerialPort::Baud4800, QSerialPort::Baud9600, QSerialPort::Baud115200 };
        QSerialPort::DataBits DataBitsArray[4] = { QSerialPort::Data5, QSerialPort::Data6, QSerialPort::Data7, QSerialPort::Data8 };
        QSerialPort::StopBits StopBitsArray[2] = { QSerialPort::OneStop, QSerialPort::TwoStop };
        QSerialPort::Parity ParityArray[3] = { QSerialPort::NoParity, QSerialPort::EvenParity, QSerialPort::OddParity };
        QString ParityArrayString[3] = { "NoParity", "EvenParity", "OddParity" };
    }serialPortConfig;
   

private slots:
       //�򿪴��ڰ�ť�����ʱ�򿪴���
       void openPortButtonClicked();
       // �رմ��ڰ�ť�����ʱ�رմ���
       void closePortButtonClicked();
       // ɨ��˿ڰ�ť�����ʱɨ��˿�
       void scanPortButtonClicked();
       // ֹͣ����
       void stopMeasurementButtonClicked();
       // �������ð�ť�����ʱ�½����棬�ڽ��������ò���
       void setConfigButtonClicked();
       // ��������������ť
       void rapidSequentialButtonClicked();

       // �ֶ����β���
       void manualOneTimeButtonClicked();
       // ���⿪
       void laserONClicked();
       // �����
       void laserOFFClicked();
       // ��ӡ������Ϣ
       void getConfigButtonClicked();
       // �Զ���������
       void autoSequentialButtonClicked();
       // �Զ����β���
       void autoOneTimeButtonClicked();
       // �����ʾ��
       void clearButtonClicked();
       // ��ȡ��������
       void readData();


public:
    ZigbeeLaserRange(QWidget* parent = nullptr);
    ~ZigbeeLaserRange();
    //���ڲ�������ṹ��
};
