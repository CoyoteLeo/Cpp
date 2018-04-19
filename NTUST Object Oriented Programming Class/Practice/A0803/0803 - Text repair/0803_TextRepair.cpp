#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
		ifstream fileInput("Error.txt");
		int Numline = 0;
		ofstream outfile("Correct.txt");
		string line;
		bool FindStart=0;
		string next="."; // The word for searching
		if (fileInput.is_open()) {
			while (!fileInput.eof()) {
				getline(fileInput, line);
				std::transform(line.begin(), line.end(), line.begin(), ::tolower);
				for (int i = 0; i < line.size(); i++)
				{
					if (FindStart == 0 && line[i]!=' ')
					{
						line[i] = toupper(line[i]);
						FindStart = 1;
					
					}
					if (line[i] == '.') { FindStart = 0; }
				}
				outfile << line << endl;
			}
			fileInput.close();
			outfile.close();
		}
		else cout << "Unable to open file.";
		system("pause");
}