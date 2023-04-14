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

void ZigbeeLaserRange::OpenPortButtonClicked()
{
    /*串口参数数组*/
    QSerialPort::BaudRate BaudRateArray[5] = { QSerialPort::Baud1200,QSerialPort::Baud2400,QSerialPort::Baud4800,QSerialPort::Baud9600,QSerialPort::Baud115200 };
    QSerialPort::DataBits DataBitsArray[3] = { QSerialPort::Data5,QSerialPort::Data6,QSerialPort::Data7 };
    QSerialPort::StopBits StopBitsArray[2] = { QSerialPort::OneStop,QSerialPort::TwoStop };
    QSerialPort::Parity ParityArray[3] = { QSerialPort::NoParity,QSerialPort::EvenParity,QSerialPort::OddParity };
   
    /*串口参数变量*/
    QSerialPort::BaudRate baudrate;
    QSerialPort::DataBits databit;
    QSerialPort::StopBits stopbit;
    QSerialPort::Parity parity;


    /*添加到combo box选项卡中*/
    for each (QSerialPort::BaudRate BaudRate in BaudRateArray)
    {
        ui.BaudSelect->addItem(QString::number(BaudRate));
    }
    for each (QSerialPort::DataBits DataBits in DataBitsArray)
    {
        ui.DataBitSelect->addItem(QString::number(DataBits));
    }
    for each (QSerialPort::StopBits StopBits in StopBitsArray)
    {
        ui.StopBitSelect->addItem(QString::number(StopBits));
    }
    for each (QSerialPort::Parity Parity in ParityArray)
    {
        ui.ParitBitSelect->addItem(QString::number(Parity));
    }

    /*设置串口参数变量*/

    baudrate = BaudRateArray[ui.BaudSelect->currentIndex()];
    databit = DataBitsArray[ui.DataBitSelect->currentIndex()];
    stopbit = StopBitsArray[ui.StopBitSelect->currentIndex()];
   
    /*设置串口*/
    serialPort->setPortName(ui.PortSelect->currentText());
    serialPort->setBaudRate(baudrate);
    serialPort->setDataBits(databit);
    serialPort->setStopBits(stopbit);
    serialPort->setParity(QSerialPort::NoParity);

    /*打开串口提示*/
    if (serialPort->open(QIODevice::ReadWrite))
    {
		ui.textBrowser->append("Open Port Success!");
	}
    else
    {
		ui.textBrowser->append("Open Port Failed!");
	}
}

void ZigbeeLaserRange::ClosePortButtonClicked()
{
    serialPort->close();
    /*关闭串口提示*/
    if (serialPort->isOpen())
    {
		ui.textBrowser->append("Close Port Failed!");
	}
    else
    {
		ui.textBrowser->append("Close Port Success!");
	}
}

void ZigbeeLaserRange::ScanPortButtonClicked()
{
	/*搜索可用串口*/
    if (QSerialPortInfo::availablePorts().size() == 0)
    {
        ui.textBrowser->append("No Port Available!");
    }
    else {
        for each (const  QSerialPortInfo & Portinfo  in QSerialPortInfo::availablePorts())
        {
            ui.PortSelect->addItem(Portinfo.portName());
        }
    }

   
}