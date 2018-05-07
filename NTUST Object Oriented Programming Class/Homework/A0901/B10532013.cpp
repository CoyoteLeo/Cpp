#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<locale>
#include<algorithm>
using namespace std;

int main() {
	fstream f("words.txt");
	map<string,bool> words;
	map<string,bool> compare;
	vector<string> lower;
	string input, longest;
	int max = 0, len, size;
	bool find, same;
	while (f >> input) {
		words[input]=false;
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		lower.push_back(input);
		compare[input]=false;
	}
	size = lower.size();
	for (int r = 0; r < size; ++r) {
		input = lower[r];
		find = false;
		if (input.size()>max) {
			string temp(input.rbegin(),input.rend());
			find=compare.count(temp);
			if(find){
				max=input.size();
				longest=input;
			}
		}
	}
	cout << longest << endl;
	system("pause");
	return 0;
}