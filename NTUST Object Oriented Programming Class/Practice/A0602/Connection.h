// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: ����User���s�u��T
#pragma once
#include <iostream>

class Connection {
public:
	// �ϥΤ@��32bit����ƪ�ܤ@��IP�A�p2130706433���127.0.0.1�A�p����J�h�w�]��0
	Connection(unsigned int ipAddress, unsigned short port);
	// �ϥΥ|��8bit����ƪ�ܤ@��IP�A�p127, 0, 0, 1���127.0.0.1
	Connection(unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port);
	// ��������i�H�����ϥ�<<��X��ostream
	friend std::ostream& operator<<(std::ostream& outputStream, const Connection& connection);
private:
	// �s�u�ϥΪ�IP�A0���unknown
	unsigned int ipAddress;
	// �s�u�ϥΪ�port�A0���unknown
	unsigned short port;
};

Connection::Connection(unsigned int ipAddress, unsigned short port)
{
    this->ipAddress = ipAddress;
    this->port = port;
}

// �ϥΥ|��8bit����ƪ�ܤ@��IP�A�p127, 0, 0, 1���127.0.0.1
Connection::Connection(unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4,
                       unsigned short port)
{
    this->ipAddress = (ipField1 << 24) + (ipField2 << 16) + (ipField3 << 8) + ipField4;
    this->port = port;
}

// ��������i�H�����ϥ�<<��X��ostream
std::ostream& operator<<(std::ostream& outputStream, const Connection& connection)
{
    // �pIP�O0�h��Xunknown�A�_�h��X�H�I���j���榡
    if (connection.ipAddress)
    {
        outputStream << "IP: " << (connection.ipAddress >> 24 & 0xff) << "." << (connection.ipAddress >> 16 & 0xff)
                     << "." << (connection.ipAddress >> 8 & 0xff) << "." << (connection.ipAddress & 0xff);
    }
    else
    {
        outputStream << "IP: unknown";
    }

    // �pport�O0�h��Xunknown�A�_�h��X���
    if (connection.port)
    {
        outputStream << ", Port: " << connection.port;
    }
    else
    {
        outputStream << ", Port: unknown";
    }

    return outputStream;
}
