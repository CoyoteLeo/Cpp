// Name: FGX
// Date: 2018/04/08
// Last Update: 2018/04/08
// Problem statement: This program reads scene statement, and interacts with user by jumping into a specific scene according to the option user select.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Intent: To read a scene section from data string.
// Pre: Pass a data string and target scene code.
// Post: Return the scene section as an iss object for getline.
istringstream ReadScene(const string &data, const string &scene) {
	size_t start = data.find("\n", data.find("\n" + scene + "\n") + 1) + 1; // find the match one-line scene code and start from the next line (*note the case when it is the first section)
	size_t end = data.find("\n#", start + 1); // find where the next scene sction starts = this scene ends + 1 blank line (*note the case when it is the last section)
	return istringstream(data.substr(start, end - start)); // from (start) to (end - 1)
}

int main() {
	ifstream in("script.txt"); // data file
	string str(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str()); // read file into string
	istringstream iss = ReadScene(str, "#0");
	while (true) {
		string line;
		vector<string> options; // store the scene code for each options in order
		while (getline(iss, line)) {
			if (line[0] == '-') { // option statements
				size_t pos = line.find("#");
				cout << "(" << options.size() + 1 << ") " << line.substr(1, pos - 1) << endl; // print a sequence and then the content
				options.push_back(line.substr(pos)); // add options
			}
			else { // narration statements
				cout << line << endl; // print all
			}
		}
		if (options.size() != 0) {
			size_t next; // which to select
			cin >> next; 
			iss = ReadScene(str, options[next - 1]); // read the next scene
		}
		else { // no option = end scene
			system("pause");
			return 0;
		}
	}
}