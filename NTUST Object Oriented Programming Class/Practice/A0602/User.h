#pragma once
#include <iostream>
#include <string>
#include "Connection.h"

class User
{
public:
	static int userCount;
	User(const User& user);
	User(std::string name);
	User(std::string name, unsigned int ipAddress);
	User(std::string name, unsigned int ipAddress, unsigned short port);
	User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3,
		unsigned char ipField4);
	User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3,
		unsigned char ipField4, unsigned short port);
	~User();
	User& operator=(const User& user);

private:
	std::string name;
	Connection connection;

	friend std::ostream& operator<<(std::ostream& os, const User& user);
};