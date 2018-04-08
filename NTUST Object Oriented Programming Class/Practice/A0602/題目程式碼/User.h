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
