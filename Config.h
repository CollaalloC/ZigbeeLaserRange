#pragma once
#include <QSerialPort>
#include <QSerialPortInfo>


namespace LaserConfig {
		//串口参数结构体
		struct SerialPortConfig
		{
			QSerialPort::BaudRate BaudRateArray[5] = { QSerialPort::Baud1200, QSerialPort::Baud2400, QSerialPort::Baud4800, QSerialPort::Baud9600, QSerialPort::Baud115200 };
			QSerialPort::DataBits DataBitsArray[4] = { QSerialPort::Data5, QSerialPort::Data6, QSerialPort::Data7, QSerialPort::Data8 };
			QSerialPort::StopBits StopBitsArray[2] = { QSerialPort::OneStop, QSerialPort::TwoStop };
			QSerialPort::Parity ParityArray[3] = { QSerialPort::NoParity, QSerialPort::EvenParity, QSerialPort::OddParity };
			QString ParityArrayString[3] = { "NoParity", "EvenParity", "OddParity" };
		};

		struct LaserParametersConfig
		{
			//偏移量，单位为mm，范围在-3000~3000
			int offSet = 0;
			//量程，单位mm，范围50~80000,默认80000mm(80m)
			int range=80000;
			//波特率，9600/19200/38400/115200 ,默认115200
			int baud = 115200;
			//从机设备地址,范围1~247
			int address = 1;
			//采样率，单位hz，支持10/20hz，默认20hz，在快速连续测量模式下有效
			int frequency = 20;
			/*上电自动测量*/
			//协议类型，0=MODBUS RTU协议，1 = ASCII协议，默认为0
			int protocol = 0;
			//上电自动测量标识 0 = 不自动，1 = 上电自动连续测量，2 = 上电自动快速连续测量,默认为0
			bool autmeas = 0;
			/*上电是否打开激光*/
			//上电是否打开激光 0 = 不打开，1 = 打开，默认为0
			bool pon_ld = 1;
			/*小数点位数*/
			//0 = 3位小数，1 = 4位小数
			bool datatype = 0;

		};


}