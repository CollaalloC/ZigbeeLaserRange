#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ZigbeeLaserRange.h"
#include "Config.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <Qtcpserver>
#include <Qtcpsocket>


class ZigbeeLaserRange : public QMainWindow
{
    Q_OBJECT

private:
    Ui::ZigbeeLaserRangeClass ui;
    QSerialPort* serialPort;
    //���ڲ����ṹ��
    LaserConfig::SerialPortConfig serialPortConfig;
   

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

       void connectButtonClicked();
       // ���Ʒ�ʽΪ����
       void enableSerialButtonClicked();
       // ���Ʒ�ʽΪ����
       void enableNetButtonClicked();

public:
    ZigbeeLaserRange(QWidget* parent = nullptr);
    ~ZigbeeLaserRange();


};
