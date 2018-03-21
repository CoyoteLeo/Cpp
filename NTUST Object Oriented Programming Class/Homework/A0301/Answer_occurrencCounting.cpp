#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string FILE_NAME = "intArray.txt";
const std::string OUTPUT_FILE_NAME = "outIntArray.txt";

struct NumberTimes
{
    int number;
    int count;
};

int main()
{
    std::fstream in;
    std::fstream out;
    in.open(FILE_NAME, std::ios::in);
    out.open(OUTPUT_FILE_NAME, std::ios::out);
    if (!in)
    {
        std::cout << "Input File isn't open!" << std::endl;
        return 0;
    }
    if (!out)
    {
        std::cout << "Input File isn't open!" << std::endl;
        return 0;
    }
    int temp = 0;
    NumberTimes temp_num{0, 1};
    std::vector<NumberTimes> numberData;
    while (in >> temp)
    {
        temp_num.number = temp;
        for (int i = 0; i < numberData.size(); i++)
        {
            if (numberData[i].number < temp_num.number)
            {
                numberData.insert(numberData.begin() + i, temp_num);
                break;
            }
            else if (numberData[i].number > temp_num.number)
            {
                if (i == numberData.size() - 1)
                {
                    numberData.push_back(temp_num);
                    break;
                }
                continue;
            }
            else
            {
                numberData[i].count++;
                break;
            }
        }
        if (numberData.size() == 0)
            numberData.push_back(temp_num);
    }
    out << "N\tcount" << std::endl;
    for (int i = 0; i < numberData.size(); i++)
    {
        out << numberData[i].number << "\t" << numberData[i].count << std::endl;
    }
    in.close();
    out.close();
    return 0;
}