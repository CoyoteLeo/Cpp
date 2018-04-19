#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main() {
	string line, temp;
	bool end = true;
	stringstream ss;
	vector<string> record;
	fstream f("Error.txt"), output("Correct.txt", ios::out);
	getline(f, line);
	while (!f.eof()) {
		record.push_back(line);
		getline(f, line);
	}
	for (unsigned int index_ = 0; index_<record.size(); index_++) {
		ss = stringstream(record[index_]);
		while (ss >> temp) {
			if (end)
			{
				output << (char)toupper(temp[0]);
				end = false;
			}
			else {
				output << (char)tolower(temp[0]);
				if (temp[temp.size() - 1] == '.')
					end = true;
			}
			for (unsigned int i = 1; i<temp.size(); i++)
			{
				output << (char)tolower(temp[i]);
			}
			if (index_ == record.size() - 1 && ss.eof())
				break;
			output << " ";
		}
		output << endl;
	}
	system("pause");
	return 0;
}