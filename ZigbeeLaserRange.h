#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ZigbeeLaserRange.h"
#include <QSerialPort>
#include <QSerialPortInfo>


class ZigbeeLaserRange : public QMainWindow
{
    Q_OBJECT

public:
    ZigbeeLaserRange(QWidget *parent = nullptr);
    ~ZigbeeLaserRange();

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
       // �ֶ���������
       void manualSequentialButtionClicked();
       // �ֶ����β���
       void manualOneTimeClicked();
       // ���⿪
       void laserONClicked();
       // �����
       void laserOFFClicked();
       // ��ӡ������Ϣ
       void getConfigButtonClicked();
       // �Զ���������
       void autoSequentialButtonClicked();
       // �Զ����β���
       void autoOneTimeButton();
private:
    Ui::ZigbeeLaserRangeClass ui;
    QSerialPort* serialPort;

};
