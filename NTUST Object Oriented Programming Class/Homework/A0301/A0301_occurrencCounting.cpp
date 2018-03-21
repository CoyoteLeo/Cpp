#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> record;
    int num;
    fstream file;
    file.open("input.txt");
    while (file >> num)
        record.push_back(num);
    file.close();
    sort(record.begin(), record.end());
    file.open("output.txt", fstream::out);
    for (int i = record.size() - 2, last = record[i + 1], count = 1; i > -1; i--)
    {
        if (record[i] != last)
        {
            file << last << "\t" << count << endl;
            cout << last << "\t" << count << endl;
            count = 0;
            last = record[i];
        }
        count++;
        if (i == 0)
        {
            file << last << "\t" << count << endl;
            cout << last << "\t" << count << endl;
        }
    }
    file.close();
    system("pause");
    return 0;
}