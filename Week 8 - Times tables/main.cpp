#include <iostream>

using namespace std;

int main()
{
	// THE PROGRAMS ARE IN THE WRONG PROJECTS BUT I AINT SWITCHIN EM
	int twelveTimesTable[12];
	for (int index = 0; index < 12; index++) {
	twelveTimesTable[index] = 12 * (index+1);
	}
	int iNumber;
	cout << "The program will print the twelve timestable up to a given number (max 12)" << endl;
	cout << "Which number should i stop at?: ";
	cin >> iNumber;
	cout << endl;
	for (int index = 0; index < iNumber; index++) {
	cout << twelveTimesTable[index] << endl;
	}
	system("pause");
	return 0;
	return 0;
}