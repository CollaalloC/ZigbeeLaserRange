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
    //串口参数结构体
    LaserConfig::SerialPortConfig serialPortConfig;
   

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

       // 手动单次测量
       void manualOneTimeButtonClicked();
       // 激光开
       void laserONClicked();
       // 激光关
       void laserOFFClicked();
       // 打印参数信息
       void getConfigButtonClicked();
       // 自动连续测量
       void autoSequentialButtonClicked();
       // 自动单次测量
       void autoOneTimeButtonClicked();
       // 清空显示屏
       void clearButtonClicked();
       // 读取串口数据
       void readData();

       void connectButtonClicked();
       // 控制方式为有线
       void enableSerialButtonClicked();
       // 控制方式为无线
       void enableNetButtonClicked();

public:
    ZigbeeLaserRange(QWidget* parent = nullptr);
    ~ZigbeeLaserRange();


};
