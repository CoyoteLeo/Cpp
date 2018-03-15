// Name: L
// Date: March 10th, 2018
// Last Update: March 10th, 2018
// Problem statement: This C++ program computes derivative.
#include <iostream>

int size, newSize;

// print the coefficients
void Print(int* coefficients)
{
	for (int i = 0; i < newSize; i++)
	{
		std::cout << coefficients[i] << " ";
	}
	std::cout << std::endl;
}

void Differential(int* coefficients)
{
	for (int i = 0; i < newSize; i++)
	{
		coefficients[i] = coefficients[i] * (newSize - 1 - i);
	}
	newSize--;
}

void Differential(int* coefficients, int times) 
{
	// initialize
	int* newCoeff = new int[size];
	for (int i = 0; i < size; i++)
	{
		newCoeff[i] = coefficients[i];
	}

	for (int i = 0; i < times; i++)
	{
		Differential(newCoeff);
	}

	Print(newCoeff);
	newSize = size;
}

int main()
{
	int times;
	while (std::cin >> size >> times)
	{
		// initialize
		int* coefficients = new int[size] {0};
		for (int i = 0; i < size; i++)
		{
			std::cin >> coefficients[i];
		}
		newSize = size;

		// method 1 differential
		Differential(coefficients, times);

		// method 2 differential
		for (int i = 0; i < times; i++)
		{
			Differential(coefficients);
			Print(coefficients);
		}
		
		// free memory
		delete[] coefficients;
	}
	system("pause");
	return 0;
}