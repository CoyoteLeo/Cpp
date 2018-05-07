#include<iostream>
#include<cctype>
#include<string>
#include"password.h"
using namespace std;

namespace {
	string password = "";
	bool isValid() {
		bool result = false;
		for (unsigned int i = 0; i < password.size(); i++) {
			if ((!isalpha(password[i]))) {
				result = true;
			}
		}
		return result && password.size()>7;
	}
}

void Authenticate::inputPassword()
{
	do
	{
		cout << "Enter your password (at least 8 characters " <<
			"and at least one non‐letter)" << endl;
		cin >> password;
	} while (!isValid());
}
string Authenticate::getPassword()
{
	return password;
}