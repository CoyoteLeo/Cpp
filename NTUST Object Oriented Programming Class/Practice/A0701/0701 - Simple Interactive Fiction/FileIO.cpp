#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
	ifstream in("script.txt"); // data file
	string str(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str()); // read file into string	
}