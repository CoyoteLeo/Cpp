#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
	while(!cin.eof()) {
		ifstream fileInput("Data2.txt");
		int Numline = 0;
		string line;
		string Input; // The word for searching
		bool exist=0;
		cin >> Input;
		if (fileInput.is_open()) {
			while (!fileInput.eof()) {
				int offset;
				int offset2 = 0;
				Numline += 1;
				getline(fileInput, line);
				if ((offset = line.find(Input, 0)) != -1) {
					cout << "The word " << Input << " find at line " << Numline << ", position: " << offset+1;
					offset2 = line.find(Input, offset + Input.size());
					exist = 1;
				}
				
				while (offset2 != offset && offset2 != -1 && offset2!=NULL)
				{
					cout << ", " << offset2+1 ;
					offset = offset2;
					offset2 = line.find(Input, offset += Input.size());
				}
				if (offset2 == -1 && offset != -1)
				{
					cout << endl;
				}
			}
			fileInput.close();
		}
		else cout << "Unable to open file.";
		if (exist == 0)
		{
			cout << "The word " << Input << " not exist in this file"<<endl;
		}
	}
}