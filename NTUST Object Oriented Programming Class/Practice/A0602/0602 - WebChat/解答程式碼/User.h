// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: ����User�����
#pragma once
#include <iostream>
#include <string>
#include "Connection.h"

class User {
public:
	// �����ثe���h��User
	static int userCount;
	// User���W��
	std::string name;
	// User���s�u��T
	Connection connection;

	// �ϥΦW�٤γs�u��T�إ�User
	User(std::string name, unsigned int ipAddress = 0, unsigned short port = 0);
	// �ϥΦW�٤Υt�@�سs�u��T�榡�إ�User
	User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port = 0);
	// �ϥΥt�@��User�إ�User
	User(const User &a);
	// ��User�P���ɩI�s
	~User();
	// ��������i�H�����ϥ�<<��X��ostream
	friend std::ostream& operator<<(std::ostream& outputStream, const User& user);
};
