// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: 紀錄User的資料
#pragma once
#include <iostream>
#include <string>
#include "Connection.h"

class User {
public:
	// 紀錄目前有多少User
	static int userCount;
	// User的名稱
	std::string name;
	// User的連線資訊
	Connection connection;

	// 使用名稱及連線資訊建立User
	User(std::string name, unsigned int ipAddress = 0, unsigned short port = 0);
	// 使用名稱及另一種連線資訊格式建立User
	User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port = 0);
	// 使用另一個User建立User
	User(const User &a);
	// 當User銷毀時呼叫
	~User();
	// 讓此物件可以直接使用<<輸出到ostream
	friend std::ostream& operator<<(std::ostream& outputStream, const User& user);
};
