#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]) {
	string in(argv[1]), out(argv[2]);
	ifstream i(in, ios::binary);
	ofstream o(out, ios::binary);
	if (!i.fail()) {
		o << i.rdbuf();
	}
	i.close();
	o.close();
	return 0;
}