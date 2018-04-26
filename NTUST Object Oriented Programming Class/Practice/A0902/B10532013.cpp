#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// compare char order
bool compare(char m, char n) {
	return (int)m > (int)n;
}

int main() {
	vector<char> body;
	string cmd, eat_string;
	int num;
	char temp;
	while (cin >> cmd) {
		if (cmd == "EAT") {
			cin >> eat_string;
			// insert each char to the beginning
			for (unsigned int i = 0; i < eat_string.size(); i++) {
				body.insert(body.begin(), eat_string[i]);
			}
		}
		else if (cmd == "PULL") {
			cin >> num;
			if (num >= body.size()) {
				// erase all
				body.clear();
			}
			else {
				// erase the range from the end
				body.erase(body.end() - num, body.end());
			}
		}
		else if (cmd == "THROW") {
			cin >> num;
			if (num >= body.size()) {
				// erase all
				body.clear();
			}
			else {
				// erase the range from the beginning
				body.erase(body.begin(), body.begin() + num);
			}
		}
		else if (cmd == "CONSUME") {
			cin >> temp;
			vector<int> t; // record the index which are need to be removed
			for (unsigned int i = 0; i < body.size(); i++) {
				if (body[i] == temp)
					t.push_back(i);
			}
			// pop the index value from end to  beginning which are in t
			for (int i = t.size() - 1; i > -1; i--) {
				body.erase(body.begin() + t[i]);
			}
		}
		else if (cmd == "SORT") {
			sort(body.begin(), body.end(), compare);
		}
		// print the result
		cout << '@';
		for (int i = 0; i < body.size(); i++) {
			cout << '-' << body[i];
		}
		cout << "-*" << endl;
	}
	system("pause");
	return 0;
}