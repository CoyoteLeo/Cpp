// Name: LDJ
// Date: 2018/03/11
// Last Update: 2018/03/11
// Problem statement: Number Pyramid
#include <iostream>

// Intent: Compute next pyramid layer recursive, pass by address, no return value.
// Pre: Top layer value and length
// Post: Bottom layer value
void computePyramid(long long data[], int length);

int main() {
	char c;
	int length = 0;
	long long data[60];

	while (std::cin.get(c)) {
		if (c >= '0' && c <= '9') {
			int n = c - '0';
			if (length == 1 && data[0] == 0) {
				data[0] = n;
			} else {
				data[length++] = n;
			}
		}
		else if (length) {
			computePyramid(data, length);
			std::cout << data[0] << std::endl;
			length = 0;
		}
	}

	return 0;
}

void computePyramid(long long data[], int length) {
	if (length <= 1) {
		return;
	} else {
		for (int i = 0; i < length - 1; i++) {
			data[i] += data[i + 1];
		}
		return computePyramid(data, length - 1);
	}
}
