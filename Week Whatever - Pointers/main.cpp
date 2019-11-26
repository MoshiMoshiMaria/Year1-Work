#include <iostream>

using namespace std;
//LOOK AT POINTERS SLIDES FOR CALLOC AND FREE() INFORMATION

int main() {
	int myNum = 5;
	int * pp;
	pp = &myNum;
	*pp = 10;
	cout << myNum << endl;
	system("pause");
	system("cls");


	int *startLocation = (int *) calloc(144, sizeof(int));
	int * pStart = startLocation;
	int counter = 0;
	for (int x = 1; x < 13; x++) {
		for (int y = 1; y < 13; y++) {
			*pStart= x*y;
			pStart++;

		}
	}
	counter = 0;
	pStart = startLocation;
	for (int x = 0; x < 144; x++) {
		if (counter <= 10) {
			cout << *(pStart + x) << "\t";
			counter++;
		}
		else {
			cout << *(pStart + x) << endl;
			counter = 0;
		}
	}
	free(startLocation);
	cout << endl;
	system("pause");
}