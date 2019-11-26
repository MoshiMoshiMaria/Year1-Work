#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string nameAge = "Name 12";
	istringstream dave;	

	string streamedString;
	int integer;
	dave.str(nameAge);
	dave >> streamedString >> integer;
	cout << streamedString << endl;
	cout << integer << endl;
	system("pause");
	return 0;
}