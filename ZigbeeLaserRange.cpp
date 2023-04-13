#include "stdafx.h"
#include "ZigbeeLaserRange.h"

ZigbeeLaserRange::ZigbeeLaserRange(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QStringList serialNamePort;
    this->setWindowTitle("Laser Ranging Control");
    serialPort = new QSerialPort(this); //创建一个串口对象，需要delete

    /*搜索可用串口*/
    for each (const  QSerialPortInfo &Portinfo  in QSerialPortInfo::availablePorts())
    {
        ui.PortSelect->addItem( Portinfo.portName());
    }
    
    
}

ZigbeeLaserRange::~ZigbeeLaserRange()
{
    delete serialPort;
}

void ZigbeeLaserRange::on_OpenPortButton_clicked()
{

}

