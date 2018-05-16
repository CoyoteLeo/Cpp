// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: ����User�����
#include "User.h"

// �����ثe���h��User(��l��)
int User::userCount = 0;

// �ϥΦW�٤γs�u��T�إ�User
User::User(std::string name, unsigned int ipAddress, unsigned short port): name(name), connection(ipAddress, port) {
	userCount++;
}

// �ϥΦW�٤Υt�@�سs�u��T�榡�إ�User
User::User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port): name(name), connection(ipField1, ipField2, ipField3, ipField4, port) {
	userCount++;
}

// �ϥΥt�@��User�إ�User
User::User(const User &a): name(a.name), connection(a.connection) {
	userCount++;
}

// ��User�P���ɩI�s
User::~User() {
	userCount--;
}

// ��������i�H�����ϥ�<<��X��ostream
std::ostream& operator<<(std::ostream& outputStream, const User& user) {
	outputStream << "Name: " << user.name << ", " << user.connection;
	return outputStream;
}
