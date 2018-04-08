#include "User.h"



int User::userCount = 0;

User::User(const User& user) : connection(0, 0, 0, 0, 0)
{
	if (this != &user)
	{
		this->name = user.name;
		this->connection = user.connection;
		userCount++;
	}
}
User::User(std::string name) : connection(0, 0, 0, 0, 0)
{
	userCount++;
	this->name = name;
}
User::User(std::string name, unsigned int ipAddress) : connection(ipAddress, 0)
{
	userCount++;
	this->name = name;
}
User::User(std::string name, unsigned int ipAddress, unsigned short port) : connection(ipAddress, port)
{
	userCount++;
	this->name = name;
}
User::User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3,
	unsigned char ipField4)
	: connection(ipField1, ipField2, ipField3, ipField4, 0)
{
	userCount++;
	this->name = name;
}
User::User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3,
	unsigned char ipField4, unsigned short port)
	: connection(ipField1, ipField2, ipField3, ipField4, port)
{
	userCount++;
	this->name = name;
}

User::~User()
{
	userCount--;
}

User& User::operator=(const User& user)
{
	if (this != &user)
	{
		this->name = user.name;
		this->connection = user.connection;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << "Name: " << user.name << ", " << user.connection;
	return os;
}
