#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	while (!cin.eof()) {
		while (cin >> a >> b >> n)
		{
			cout << a / b << ".";
			for (int i = 0; i < n; i++) {
				a %= b;
				a *= 10;
				cout << a / b;
			}
			cout << endl;
		}
	}
}