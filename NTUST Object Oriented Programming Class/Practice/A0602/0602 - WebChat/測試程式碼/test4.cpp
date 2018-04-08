#include <iostream>
#include <cstdlib>
#include <vector>
#include "User.h"
#define assert(a, b) {if ((a) != (b)) std::cout << "!!!!!!!!!! error !!!!!!!!!!" << std::endl;}
/*
此程式應該輸出以下內容
vvvvvvvvvv test4 vvvvvvvvvv
should be 5 -> 5
Name: AAA, IP: unknown, Port: unknown
Name: BBB, IP: 1.1.1.1, Port: unknown
Name: CCC, IP: 2.2.2.2, Port: unknown
Name: DDD, IP: 3.3.3.3, Port: 3
Name: EEE, IP: 4.4.4.4, Port: 4

vvvvvvvvvv test1 vvvvvvvvvv
Active User: 5
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Gerardo, IP: 7.91.205.21, Port: 8080
Name: Austyn, IP: 58.222.104.177, Port: unknown
Name: Troy, IP: unknown, Port: unknown
vvvvvvvvvv test3 vvvvvvvvvv
Active User: 5
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Austyn, IP: 58.222.104.177, Port: unknown
Name: Troy, IP: unknown, Port: unknown
vvvvvvvvvv test2 vvvvvvvvvv
Active User: 4
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Gerardo, IP: 7.91.205.21, Port: 8080
Name: Troy, IP: unknown, Port: unknown
*/
int main() {
	std::cout << "vvvvvvvvvv test4 vvvvvvvvvv" << std::endl;
	{
		std::vector<User> users;
		users.push_back(User("AAA"));
		users.push_back(User("BBB", 16843009));
		users.push_back(User("CCC", 2, 2, 2, 2));
		users.push_back(User("DDD", 50529027, 3));
		users.push_back(User("EEE", 4, 4, 4, 4, 4));
		std::cout << "should be 5 -> " << User::userCount << std::endl;
		for (int i = 0; i < users.size(); i++) {
			std::cout << users[i] << std::endl;
		}
		assert(User::userCount, 5);
		users.pop_back();
		assert(User::userCount, 4);
		users.pop_back();
		assert(User::userCount, 3);
		users.push_back(User("ZZZ"));
		assert(User::userCount, 4);
		User *p;
		{
			User a("ZZZ");
			assert(User::userCount, 5);
			p = new User("AAA");
			assert(User::userCount, 6);
		}
		assert(User::userCount, 5);
		delete p;
		assert(User::userCount, 4);
	}
	std::cout << std::endl;

	std::cout << "vvvvvvvvvv test1 vvvvvvvvvv" << std::endl;
	{
		User users[] = {
			{ "Enrique", 127, 0, 0, 1, 443 },
			{ "Gerardo", 123456789, 8080 },
			{ "Austyn", 987654321 },
			{ "Troy" },
		};
		std::cout << "Active User: " << User::userCount << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << users[i] << std::endl;
		}
	}

	std::cout << "vvvvvvvvvv test3 vvvvvvvvvv" << std::endl;
	{
		std::vector<User> users;
		users.push_back(User("Enrique", 127, 0, 0, 1, 443));
		users.push_back(User("Enrique", 127, 0, 0, 1, 443));
		users.push_back(User("Gerardo", 123456789, 8080));
		users.pop_back();
		users.push_back(User("Austyn", 987654321));
		users.push_back(User("Troy"));
		std::cout << "Active User: " << User::userCount << std::endl;
		for (int i = 0; i < users.size(); i++) {
			std::cout << users[i] << std::endl;
		}
	}

	std::cout << "vvvvvvvvvv test2 vvvvvvvvvv" << std::endl;
	{
		std::vector<User*> users;
		users.push_back(new User("Enrique", 127, 0, 0, 1, 443));
		users.push_back(new User("Gerardo", 123456789, 8080));
		users.push_back(new User("Austyn", 987654321));
		delete users[users.size() - 1];
		users.pop_back();
		users.push_back(new User("Troy"));
		std::cout << "Active User: " << User::userCount << std::endl;
		for (int i = 0; i < users.size(); i++) {
			std::cout << *users[i] << std::endl;
		}
	}

	system("pause");
	return 0;
}
