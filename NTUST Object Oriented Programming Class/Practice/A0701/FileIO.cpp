#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

typedef struct option
{
    string content;
    string next;
} option;

class Scene
{
   public:
    string id;
    string narration;
    vector<option> options;
    Scene(string inputId)
    {
        id = inputId;
    }
    void setNarration(string inputNarration)
    {
        narration = inputNarration;
    }
    void setOption(option inputOption)
    {
        options.push_back(inputOption);
    }
};

int main()
{
    ifstream in("script.txt");                                                         // data file
    string str(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str());  // read file into string
    vector<Scene> record;
    int pos, start = 0;
    pos = str.find('\n', start);
    do
    {
        if (str[start] == '#')
        {
            Scene temp = Scene(str.substr(start, pos - start));
            start = pos + 1;
            pos = str.find('\n', start);
            string nar;
            do
            {
                if (str[start] == '-' || str[start] == '\n' || str[start] == '\000')
                    break;
                nar += str.substr(start, pos - start + 1);
                start = pos + 1;
                pos = str.find('\n', start);
            } while (pos != string::npos);
            nar.erase(nar.length() - 1, 1);
            temp.setNarration(nar);
            do
            {
                if (str[start] != '-' || str[start] == '\n' || str[start] == '\000')
                    break;
                string s = str.substr(start, pos - start);
                option opt;
                opt.content = s.substr(1, s.find('#') - 2);
                opt.next = s.substr(s.find('#'), s.length() - opt.content.length());
                temp.setOption(opt);
                start = pos + 1;
                pos = str.find('\n', start);
            } while (pos != string::npos);
            record.push_back(temp);
        }
        if (pos == string::npos)
            break;
        start = pos + 1;
        pos = str.find('\n', start);
    } while (pos != string::npos);

    int now = 0, ans;
    string tempId;
    while (true)
    {
        cout << record[now].narration << endl;
        if (record[now].options.size() > 1)
        {
            for (unsigned int i = 0; i < record[now].options.size(); i++)
                cout << '(' << i + 1 << ") " << record[now].options[i].content << endl;
            cin >> ans;
            tempId = record[now].options[ans-1].next;
            for (unsigned int i = 0; i < record.size(); i++)
            {
                if (tempId == record[i].id)
                {
                    now = i;
                    break;
                }
            }
        }
        else
            break;
    }
    system("pause");
}