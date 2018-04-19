#include<iostream>
#include<string>
using namespace std;

int main() {
	long long a, b, intPart, mod;
	int n;
	string floatPart;
	while (cin >> a >> b >> n) {
		floatPart = "";
		intPart = a / b;
		mod = (a % b) * 10;
		for (int i = 0; i < n; i++) {
			if (mod < b) {
				floatPart += '0';
				mod *= 10;
			}
			else {
				int temp = mod / b;
				floatPart += (char)(mod / b + 48);
				mod = mod % b * 10;

			}
		}
		cout << intPart << '.' << floatPart << endl;
	}


	return 0;
}