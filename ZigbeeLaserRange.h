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
       void OpenPortButtonClicked();
       void ClosePortButtonClicked();
       void ScanPortButtonClicked();
private:
    Ui::ZigbeeLaserRangeClass ui;
    QSerialPort* serialPort;
};
