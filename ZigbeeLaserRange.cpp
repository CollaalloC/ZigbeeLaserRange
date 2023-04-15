#include "stdafx.h"
#include "ZigbeeLaserRange.h"

ZigbeeLaserRange::ZigbeeLaserRange(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QStringList serialNamePort;
    this->setWindowTitle("Laser Ranging Control");
    //使用new创建一个串口对象
    serialPort = new QSerialPort(this); 

    /*搜索可用串口*/
    for each (const  QSerialPortInfo &Portinfo  in QSerialPortInfo::availablePorts())
    {
        ui.portSelect->addItem( Portinfo.portName());
    }
    //连接串口读取信号与读取槽函数
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));

    /*串口参数下拉框初始化*/

    for each (QSerialPort::BaudRate BaudRate in serialPortConfig.BaudRateArray)
    {
        ui.baudSelect->addItem(QString::number(BaudRate));
    }
    for each (QSerialPort::DataBits DataBits in serialPortConfig.DataBitsArray)
    {
        ui.dataBitSelect->addItem(QString::number(DataBits));
    }
    for each (QSerialPort::StopBits StopBits in serialPortConfig.StopBitsArray)
    {
        ui.stopBitSelect->addItem(QString::number(StopBits));
    }
    for each (QString parityString in serialPortConfig.ParityArrayString)
    {
        ui.paritBitSelect->addItem(parityString);
    }
}

ZigbeeLaserRange::~ZigbeeLaserRange()
{
    delete serialPort; //释放serialPort内存
}

void ZigbeeLaserRange::openPortButtonClicked()
{ 
    /*串口参数变量*/
    QSerialPort::BaudRate baudrate;
    QSerialPort::DataBits databit;
    QSerialPort::StopBits stopbit;
    QSerialPort::Parity parity;


    /*添加到combo box选项卡中*/
    for each (QSerialPort::BaudRate BaudRate in serialPortConfig.BaudRateArray)
    {
        ui.baudSelect->addItem(QString::number(BaudRate));
    }
    for each (QSerialPort::DataBits DataBits in serialPortConfig.DataBitsArray)
    {
        ui.dataBitSelect->addItem(QString::number(DataBits));
    }
    for each (QSerialPort::StopBits StopBits in serialPortConfig.StopBitsArray)
    {
        ui.stopBitSelect->addItem(QString::number(StopBits));
    }
    for each (QString ParityString in serialPortConfig.ParityArrayString)
    {
        ui.paritBitSelect->addItem(ParityString);
    }

    /*设置串口参数变量*/

    baudrate =serialPortConfig.BaudRateArray[ui.baudSelect->currentIndex()];
    databit = serialPortConfig.DataBitsArray[ui.dataBitSelect->currentIndex()];
    stopbit = serialPortConfig.StopBitsArray[ui.stopBitSelect->currentIndex()];
    parity = serialPortConfig.ParityArray[ui.paritBitSelect->currentIndex()];//注意这里应为数数组，而不是String 数组
   
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
void ZigbeeLaserRange::autoOneTimeButtonClicked()
{
    

}
