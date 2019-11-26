#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void drawBarMiddle(int lengthOfBar) {
	for (int i = 0; i < lengthOfBar; i++) {
		cout << '-';
	}
	cout << endl;
}

void drawBarTop(int lengthOfBar) {
	for (int i = 0; i < lengthOfBar; i++) {
		cout << "_";
	}
	cout << endl;
}

//this one not printing correctly yet so just use middle for now
void drawBarBottom(int lengthOfBar) {
	for (int i = 0; i < lengthOfBar; i++) {
		cout << "¯"; // \u0305
	}
	cout << endl;
}



//these may not have need functions but it makes for easier code reading
string drawWhiteSpace() {;
	return "  ";
}
//these may not have need functions but it makes for easier code reading
string drawBlackSpace() {
	return "**";
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

void drawChessboard(int xLength, int yLength) {
	drawBarMiddle(xLength * 2 + 2);
	for (int y = 0; y < yLength; y++) {
		string row = "|";
		for (int x = 0; x < xLength; x++) {
			if (isWhiteSpace(x, y)) {
				row += drawWhiteSpace();
			}
			else {
				row += drawBlackSpace();
			}
		}
		cout << row << "|" << endl;
	}
	drawBarMiddle(xLength*2+2);

}

void timestableGrid(int highestNumber) { // Table alignment gets a bit scuffed after 47 (screen width issue)
	cout << "Timestables grid upto " << highestNumber << "x" << highestNumber <<":" << endl;
	drawBarMiddle(highestNumber * 5 + 1);
	for (int i = 1; i < highestNumber+1; i++) {
		for (int j = 1; j < highestNumber+1; j++) {
			int number = i * j;
			if (number < 10) {
				cout << "|" << number << "   ";
			}
			else if (number < 100) {
				cout << "|" << number << "  ";
			}
			else if (number < 1000) {
				cout << "|" << number << " ";
			}
			else {
				cout << "|" << number;
			}
		}
		cout << "|" << endl;
	}
	drawBarMiddle((highestNumber) * 5 + 1);
}

int main()
{	

	//Timetables stuff
	cout << "TIMETABLES" << endl << endl;
	timestableGrid(12);
	system("pause");
	int highestNumber;
	cout << endl;
	cout << "Table alignment gets scuffed after 47" << endl;
	cout << "Enter a number: ";
	cin >> highestNumber;
	cout << endl;
	timestableGrid(highestNumber);
	cout << endl;
	system("pause");

	//reset the console
	system("cls");

	//Chessboard studd
	cout << "CHESSBOARDS" << endl << endl;
	cout << "8x8 Chessboard: " << endl;
	drawChessboard(8, 8);
	cout << endl;
	cout << "20x20 Chessboard:" << endl;
	drawChessboard(20, 20);
	cout << endl;
	system("pause");
	int columns, rows;
	cout << endl;
	cout << "Enter the number of columns: ";
	cin >> columns;
	cout << endl;
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << endl;
	cout << columns << "x" << rows << " Chessboard:" << endl;
	drawChessboard(columns, rows);
	system("pause");

	//END of program
	return 0;
}