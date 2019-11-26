#include <iostream>
#include "Windows.h"

using namespace std;

void menu() {
	cout << "\n--Menu--:" << endl;
	cout << "\t1 - Print the whole timetables grid upto 12x12" << endl;
	cout << "\t2 - Print a row of the timestable grid" << endl;
	cout << "\t3 - Print the number from a given row and column" << endl;
	cout << "\t4 - Print part of the grid for a given number of rows and columns" << endl;
	cout << "\t-1 - Exit the program" << endl;
}

bool checkExit() {
	bool quit;
	char yOrN;
	cout << "Are you sure? y/n: ";
	cin >> yOrN;
	yOrN == 'y' || yOrN == 'Y' ? quit = true : quit = false;
	return quit;
}

int getChoice() {
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}

void printWholeGrid(int timestables[12][12]) {
	cout << endl;
	for (int i = 0; i < 12; i++) {
		cout << "|";
		for (int j = 0; j < 12; j++) {
			if (timestables[i][j] < 10) {
				cout << timestables[i][j] << "  |";
			}
			else if (timestables[i][j] < 100) {
				cout << timestables[i][j] << " |";
			}
			else {
				cout << timestables[i][j] << "|";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void printRow(int timestables[12][12]) {
	int row;
	cout << endl;
	cout << "Which row would you like?: ";
	cin >> row;
	row -= 1;
	cout << endl;
	for (int i = 0; i < 12; i++) {
		if (timestables[row][i] < 10) {
			cout << timestables[row][i] << "  |";
		}
		else if (timestables[row][i] < 100) {
			cout << timestables[row][i] << " |";
		}
		else {
			cout << timestables[row][i] << "|";
		}
	}
	cout << endl;
}

void printCell(int timestables[12][12]) {
	int row, column;
	cout << "Enter the first number: ";
	cin >> row;
	cout << endl;
	cout << "Enter the second number: ";
	cin >> column;
	cout << endl << "The number at " << row << ", " << column << " is " << timestables[row - 1][column - 1] << endl;
}

void printCluster(int timestables[12][12]) {
	int row, column;
	cout << "Enter the row to stop at: ";
	cin >> row; 
	cout << endl;
	cout << "Enter the column to stop at: ";
	cin >> column;
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (timestables[i][j] < 10) {
				cout << timestables[i][j] << "  |";
			}
			else if (timestables[i][j] < 100) {
				cout << timestables[i][j] << " |";
			}
			else {
				cout << timestables[i][j] << "|";
			}
		}
		cout << endl;
	}
}

int main(){
	// THE PROGRAMS ARE IN THE WRONG PROJECTS BUT I AINT SWITCHIN EM
	//setup timestable grid
	int timestables[12][12];
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			timestables[i][j] = (i+1)*(j+1);
		}
	}
	
	bool endProgram = false;
	int choice;
	while (!endProgram) {
		menu();
		choice = getChoice();
		switch (choice) {
		case -1:
			endProgram = checkExit();
			break;
		case 1:
			printWholeGrid(timestables);
			break;
		case 2:
			printRow(timestables);
			break;
		case 3:
			printCell(timestables);
			break;
		case 4:
			printCluster(timestables);
			break;
		default:
			cout << "Invalid Option";
		}
	}
	cout << endl << "Exiting...";
	Sleep(500);
	return 0;
}