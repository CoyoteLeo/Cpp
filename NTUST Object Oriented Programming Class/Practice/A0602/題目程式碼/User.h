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
