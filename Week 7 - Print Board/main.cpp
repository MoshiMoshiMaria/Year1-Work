#include <iostream>
#include <string>

using namespace std;

//these may not have need functions but it makes for easier code reading
string drawWhiteSpace() {
	;
	return "*";
}
//these may not have need functions but it makes for easier code reading
string drawBlackSpace() {
	return " ";
}

bool isWhiteSpace(int xPos, int yPos) {
	if (yPos % 2 == 0 && xPos % 2 == 0) {
		return true;
	}
	else if (yPos % 2 == 1 && xPos % 2 == 1) {
		return true;
	}
	else {
		return false;
	}
}

void drawChessboard(int xLength, int yLength, int xPos, int yPos) {
	xPos -= 1;
	yPos -= 1;
	for (int y = 0; y < yLength; y++) {
		string row = "";
		for (int x = 0; x < xLength; x++) {
			if (x == xPos && y == yPos) {
				row += "x";
			}
			else {
				if (isWhiteSpace(x, y)) {
					row += drawWhiteSpace();
				}
				else {
					row += drawBlackSpace();
				}
			}
		}
		cout << row << endl;
	}
}

int main()
{
	int xInput, yInput;
	cout << "X coordinate: ";
	cin >> xInput;
	cout << endl;
	cout << "Y coordinate: ";
	cin >> yInput;
	drawChessboard(8, 8, xInput, yInput);
	system("pause");
}