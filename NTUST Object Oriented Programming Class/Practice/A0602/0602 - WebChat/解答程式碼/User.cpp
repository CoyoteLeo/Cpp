// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: 紀錄User的資料
#include "User.h"

// 紀錄目前有多少User(初始化)
int User::userCount = 0;

// 使用名稱及連線資訊建立User
User::User(std::string name, unsigned int ipAddress, unsigned short port): name(name), connection(ipAddress, port) {
	userCount++;
}

// 使用名稱及另一種連線資訊格式建立User
User::User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port): name(name), connection(ipField1, ipField2, ipField3, ipField4, port) {
	userCount++;
}

// 使用另一個User建立User
User::User(const User &a): name(a.name), connection(a.connection) {
	userCount++;
}

// 當User銷毀時呼叫
User::~User() {
	userCount--;
}

// 讓此物件可以直接使用<<輸出到ostream
std::ostream& operator<<(std::ostream& outputStream, const User& user) {
	outputStream << "Name: " << user.name << ", " << user.connection;
	return outputStream;
}
