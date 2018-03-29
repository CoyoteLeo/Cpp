// Name: Shen
// Date: 2018/3/28
// Last Update: 2018/3/28
/*C++ program to create student class, read and print N student's details
(Example of array of objects).*/

#include <iostream>
#include <string>  //if you want to "cin" data into string variable
#include <iomanip> //for setw
using std::cin;
using std::cout;
using std::string;//for declare string variable
using namespace std;

#define MAX 10

class student
{
private:
	char  name[30];
	int   stdNo;
	int   total;
	float perc;
public:
	//member function to get student's details
	void setDetails(void);
	//member function to print student's details
	void getDetails(void);
};

// Intent: Enter student's data.
// Pre: none.
// Post: Set all the data of the object.
//member function definition, outside of the class
void student::setDetails(void) {
	//cout << "Enter name: ";
	cin >> name;
	//cout << "Enter number: ";
	cin >> stdNo;
	//cout << "Enter total scores outof 300: ";
	cin >> total;
	
	perc = (float)total / 300 * 100;
}

// Intent: Show student's data.
// Pre: Do setDetails() first !
// Post: Output all the data of the object.
//member function definition, outside of the class
void student::getDetails(void) {
	cout << "Student details:"<<endl;
	cout <<  "Name:" << name << endl;
	cout << "Student Number:" << stdNo << endl;
	if (total > 300)
	{
		cout << "Total:" << total << endl;
		cout << "Total scores should be under 300!" << endl;
	}
	else 
		cout << "Total:" << total << endl; 
	cout << "Percentage:" << perc << endl ;
}

int main()
{
	student std[MAX];       //array of objects creation
	int numberOfStudents;

	cout << "Enter total number of students: ";
	cin >> numberOfStudents;

	for (int i  = 0; i< numberOfStudents; i++) {
		cout << "Enter details of student " << i + 1 << ":\n";
		std[i].setDetails();
	}

	cout << endl;

	for (int i = 0; i < numberOfStudents; i ++) {
		cout << "Details of student " << (i + 1) << ":\n";
		std[i].getDetails();
		cout << endl;
	}

	system("pause");
	return 0;
}