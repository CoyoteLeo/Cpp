#include<iostream>
using namespace std;

namespace Authenticate {
	string username;
	string getUserName() {
		return username;
	}
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
	void inputUserName() {
		do {
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}
}
namespace {
	string password;
	string getPassword() {
		return password;
	};
	bool isValid() {
		bool result = false;
		for (unsigned int i = 0; i < password.size(); i++) {
			if ((!isalpha(password[i]))) {
				result = true;
			}
		}
		return result && password.size()>7;
	}
	void inputPassword() {
		do {
			cout << "Enter your password (at least 8 characters " << "and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}
}

using namespace Authenticate;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: "
		<< getPassword() << endl;
	return 0;
}