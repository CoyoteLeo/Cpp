#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    vector<int> record;
    int num;
    fstream file;
    file.open("grade.txt");
    while (file >> num)
        record.push_back(num);
    file.close();
    file.open("grade.Output", fstream::out);
    sort(record.begin(), record.end());
    for (int i = 1, last = record[0], count = 1; i < record.size(); i++)
    {
        if (record[i] != last)
        {
            while (record[i] != last + 1)
            {
                file << count << " grade(s) of " << last << endl;
                cout << count << " grade(s) of " << last << endl;
                count = 0;
                last++;
            }
            file << count << " grade(s) of " << last << endl;
            cout << count << " grade(s) of " << last << endl;
            count = 0;
            last = record[i];
        }
        count++;
        if (i + 1 == record.size())
            cout << count << " grade(s) of " << last << endl;
    }
    file.close();
    system("pause");
    return 0;
}