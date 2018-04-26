#include<iostream>
#include<string>
using namespace std;

int main() {
	int w, h;
	int x1, y1, x2, y2, c1, c2, r;
	char fill;
	string cmd;
	cin >> w >> h;

	char** board = new char*[h];  // dynamic array
	for (int i = 0; i < h; ++i) 
		board[i] = new char[w];

	while (cin >> cmd) {
		if (cmd == "RECT") {
			cin >> x1 >> y1 >> x2 >> y2 >> fill;
			if (x2 < 0)
				x2 = 0;
			if (y2 < 0)
				y2 = 0;
			// draw from left-up corner
			for (int i = y2; i <= y1 && i<h; i++) {
				for (int j = x2; j <= x1 && j<w; j++) {
					board[i][j] = fill;
				}
			}
		}
		else if (cmd == "CIRCLE") {
			cin >> c1 >> c2 >> r >> fill;
			// draw from left-up corner
			for (int i = (c2 - r>0? c2 - r :0); i <= c2 + r && i<h; i++) {
				for (int j = (c1 - r>0? c1 - r:0); j <= c1 + r && j<w; j++) {
					if ((i - c2)*(i - c2) + (j - c1)*(j - c1) <= r * r) // the dot is in the circlr or not
						board[i][j] = fill;
				}
			}
		}
		else if (cmd == "DRAW") {
			// draw for left-up corner
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cout << board[i][j];
				}
				cout << endl;
			}
		}
	}
	// release the space of the dynamic array
	for (int i = 0; i < h; ++i) {
		delete[] board[i];
	}
	delete[] board;
	board = NULL;
	system("pause");
	return 0;
}