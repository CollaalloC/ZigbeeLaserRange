#pragma once
#include <QSerialPort>
#include <QSerialPortInfo>


namespace LaserConfig {
		//���ڲ����ṹ��
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
			//ƫ��������λΪmm����Χ��-3000~3000
			int offSet = 0;
			//���̣���λmm����Χ50~80000,Ĭ��80000mm(80m)
			int range=80000;
			//�����ʣ�9600/19200/38400/115200 ,Ĭ��115200
			int baud = 115200;
			//�ӻ��豸��ַ,��Χ1~247
			int address = 1;
			//�����ʣ���λhz��֧��10/20hz��Ĭ��20hz���ڿ�����������ģʽ����Ч
			int frequency = 20;
			/*�ϵ��Զ�����*/
			//Э�����ͣ�0=MODBUS RTUЭ�飬1 = ASCIIЭ�飬Ĭ��Ϊ0
			int protocol = 0;
			//�ϵ��Զ�������ʶ 0 = ���Զ���1 = �ϵ��Զ�����������2 = �ϵ��Զ�������������,Ĭ��Ϊ0
			bool autmeas = 0;
			/*�ϵ��Ƿ�򿪼���*/
			//�ϵ��Ƿ�򿪼��� 0 = ���򿪣�1 = �򿪣�Ĭ��Ϊ0
			bool pon_ld = 1;
			/*С����λ��*/
			//0 = 3λС����1 = 4λС��
			bool datatype = 0;

		};


}