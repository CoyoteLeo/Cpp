#include <fstream>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    fstream f("name.txt");
    set<string> record;
    string line;
    getline(f, line);
    while (!f.eof())
    {
        record.insert(line);
        getline(f, line);
    }
    for (set<string>::iterator i = record.begin(); i != record.end(); i++)
        cout << *i << endl;
    f.close();
    return 0;
}