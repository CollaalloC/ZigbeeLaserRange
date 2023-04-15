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
       //打开串口按钮，点击时打开串口
       void openPortButtonClicked();
       // 关闭串口按钮，点击时关闭串口
       void closePortButtonClicked();
       // 扫描端口按钮，点击时扫描端口
       void scanPortButtonClicked();
       // 停止测量
       void stopMeasurementButtonClicked();
       // 设置配置按钮，点击时新建界面，在界面中配置参数
       void setConfigButtonClicked();
       // 快速连续测量按钮
       void rapidSequentialButtonClicked();
       // 手动连续测量
       void manualSequentialButtionClicked();
       // 手动单次测量
       void manualOneTimeClicked();
       // 激光开
       void laserONClicked();
       // 激光关
       void laserOFFClicked();
       // 打印参数信息
       void getConfigButtonClicked();
       // 自动连续测量
       void autoSequentialButtonClicked();
       // 自动单次测量
       void autoOneTimeButton();
private:
    Ui::ZigbeeLaserRangeClass ui;
    QSerialPort* serialPort;

};
