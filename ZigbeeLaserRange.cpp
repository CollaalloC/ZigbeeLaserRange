#include "stdafx.h"
#include "ZigbeeLaserRange.h"

ZigbeeLaserRange::ZigbeeLaserRange(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QStringList serialNamePort;
    this->setWindowTitle("Laser Ranging Control");
    serialPort = new QSerialPort(this); //new创建一个串口对象

    /*搜索可用串口*/
    for each (const  QSerialPortInfo &Portinfo  in QSerialPortInfo::availablePorts())
    {
        ui.portSelect->addItem( Portinfo.portName());
    }
    
}

ZigbeeLaserRange::~ZigbeeLaserRange()
{
    delete serialPort; //释放serialPort内存
}

void ZigbeeLaserRange::openPortButtonClicked()
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
        ui.baudSelect->addItem(QString::number(BaudRate));
    }
    for each (QSerialPort::DataBits DataBits in DataBitsArray)
    {
        ui.dataBitSelect->addItem(QString::number(DataBits));
    }
    for each (QSerialPort::StopBits StopBits in StopBitsArray)
    {
        ui.stopBitSelect->addItem(QString::number(StopBits));
    }
    for each (QSerialPort::Parity Parity in ParityArray)
    {
        ui.paritBitSelect->addItem(QString::number(Parity));
    }

    /*设置串口参数变量*/

    baudrate = BaudRateArray[ui.baudSelect->currentIndex()];
    databit = DataBitsArray[ui.dataBitSelect->currentIndex()];
    stopbit = StopBitsArray[ui.stopBitSelect->currentIndex()];
   
    /*设置串口*/
    serialPort->setPortName(ui.portSelect->currentText());
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

void ZigbeeLaserRange::closePortButtonClicked()
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

void ZigbeeLaserRange::scanPortButtonClicked()
{
	/*搜索可用串口*/
    if (QSerialPortInfo::availablePorts().size() == 0)
    {
        ui.textBrowser->append("No Port Available!");
    }
    else {
        for each (const  QSerialPortInfo & Portinfo  in QSerialPortInfo::availablePorts())
        {
            ui.portSelect->addItem(Portinfo.portName());
        }
    }

   
}

// 停止测量
void ZigbeeLaserRange::stopMeasurementButtonClicked()
{
    // TODO: 在此处添加实现代码.
}


// 设置配置按钮，点击时新建界面，在界面中配置参数
void ZigbeeLaserRange::setConfigButtonClicked()
{
    // TODO: 在此处添加实现代码.
}


// 快速连续测量按钮
void ZigbeeLaserRange::rapidSequentialButtonClicked()
{
    // TODO: 在此处添加实现代码.
}


// 手动连续测量
void ZigbeeLaserRange::manualSequentialButtionClicked()
{
    // TODO: 在此处添加实现代码.
}


// 手动单次测量
void ZigbeeLaserRange::manualOneTimeClicked()
{
    // TODO: 在此处添加实现代码.
}


// 激光开
void ZigbeeLaserRange::laserONClicked()
{
    // TODO: 在此处添加实现代码.
}


// 激光关
void ZigbeeLaserRange::laserOFFClicked()
{
    // TODO: 在此处添加实现代码.
}


// 打印参数信息
void ZigbeeLaserRange::getConfigButtonClicked()
{
    // TODO: 在此处添加实现代码.
}


// 自动连续测量
void ZigbeeLaserRange::autoSequentialButtonClicked()
{
    // TODO: 在此处添加实现代码.
}


// 自动单次测量
void ZigbeeLaserRange::autoOneTimeButton()
{
    // TODO: 在此处添加实现代码.
}
