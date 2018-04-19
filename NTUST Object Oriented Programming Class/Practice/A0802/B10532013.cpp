#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
	string key, line;
	ifstream f("Data.txt");
	vector<string> record;
	for (int i = 0; !f.eof(); i++) {
		getline(f, line);
		record.push_back(line);
	}
	bool foundInLine, foundInFile;
	int pos;
	while (cin >> key) {
		foundInFile = false;
		for (unsigned int i = 0; i<record.size(); i++)
		{
			foundInLine  = false;
			pos = record[i].find(key);
			if (pos != string::npos) {
				cout << "The word " << key << " find at line " << i + 1 << ", position:" << pos + 1;
				foundInLine = foundInFile = true;
			}
			pos = record[i].find(key, pos + 1);
			while (pos != string::npos) {
				foundInLine = foundInFile = true;
				cout << ", " << pos + 1;
				pos = record[i].find(key, pos + 1);
			}
			if (foundInLine)
				cout << endl;
		}
		if (!foundInFile)
			cout<<"The word "<<key<<" not exist in this file."<<endl;
	}
	system("pause");
	return 0;
}