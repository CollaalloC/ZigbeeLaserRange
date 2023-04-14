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
       void openPortButtonClicked();
       void closePortButtonClicked();
       void scanPortButtonClicked();
private:
    Ui::ZigbeeLaserRangeClass ui;
    QSerialPort* serialPort;
};
