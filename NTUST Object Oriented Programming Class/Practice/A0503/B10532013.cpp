#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class student
{
   public:
    void setDetails()
    {
        cin >> name >> num >> grade;
    }
    void getDetails()
    {
        cout << "Student details:" << endl;
        cout << "Name:" << name << endl;
        cout << "Student Number:" << num << endl;
        cout << "Total:" << grade << endl;
        if (grade > 300)
        {
            cout << "Total scores should be under 300!" << endl;
        }
        cout << "Percentage:" << (float)grade / 3 << endl;
    }

   private:
    string name;
    int num;
    int grade;
};
/*
Please implement your class "student" and functions here.
*/
int main()
{
    student std[MAX];  // array of objects creation
    int numberOfStudents;

    cout << "Enter total number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Enter details of student " << i + 1 << ":\n";
        std[i].setDetails();
    }

    cout << endl;

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Details of student " << (i + 1) << ":\n";
        std[i].getDetails();
        cout << endl;
    }

    system("pause");
    return 0;
}