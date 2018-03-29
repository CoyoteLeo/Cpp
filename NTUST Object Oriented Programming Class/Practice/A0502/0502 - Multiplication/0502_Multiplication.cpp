// Name: L
// Date: March 24th, 2018
// Last Update: March 24th, 2018
// Problem statement: This C++ program computes multiplication.
#include <iostream>

int size, newSize;

struct term
{
	int coef;	//«Y¼Æ
	int exp;	//¦¸¤è
};
typedef struct term Term;

// poly1 * poly2 = sum
void mulpoly(Term *poly1, Term *poly2, Term *sum) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			sum[i + j].coef = (poly1[i].coef)*(poly2[j].coef) + sum[i + j].coef;
			sum[i + j].exp = i + j;
		}
	}
}

void write(Term *poly, int coef, int exp) {
	poly[exp].coef = coef;
	poly[exp].exp = exp;
}

int main()
{
	int a, b, c, d;
	while (std::cin >> a >> b >> c >> d)
	{
		Term poly1[30] = { 0 }, poly2[30] = { 0 }, sum[30] = { 0 };
		write(poly1, a, 2);
		write(poly1, b, 1);
		write(poly1, c, 0);
		write(sum, a, 2);
		write(sum, b, 1);
		write(sum, c, 0);

		// calculate
		for (int i = 0; i< d - 1; i++) {
			// initialize
			for (int j = 0; j < 20; j++) {
				sum[j].exp = 0;
				sum[j].coef = 0;
			}
			// multiplication
			if (i != 0) mulpoly(poly1, poly2, sum);
			else mulpoly(poly1, poly1, sum);
			// copy
			for (int j = 0; j<20; j++) {
				poly2[j].exp = sum[j].exp;
				poly2[j].coef = sum[j].coef;
			}
		}
		// print the answer
		for (int i = 2 * d; i >= 0; i--)
			std::cout << sum[i].coef << " ";
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}