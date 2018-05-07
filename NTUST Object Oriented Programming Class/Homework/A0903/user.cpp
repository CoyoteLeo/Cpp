#include<iostream>
#include<cctype>
#include<string>
#include"user.h"
using namespace std;

namespace {
	string username = "";
	bool isValid() {
		if (username.size() != 8)
			return false;
		bool valid = true;
		for (unsigned int i = 0; i<username.size(); i++) {
			if (!isalpha(username[i])) {
				valid = false;
				break;
			}
		}
		return valid;
	}
}

void Authenticate::inputUserName()
{
	do
	{
		cout << "Enter your username (8 letters only)" << endl;
		cin >> username;
	} while (!isValid());
}

string Authenticate::getUserName()
{
	return username;
}