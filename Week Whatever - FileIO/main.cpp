#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ofstream outFile;
	outFile.open("output.txt", ios::out);
	outFile << "First Line" << endl;
	outFile << "Second Line" << endl;
	outFile.close();

	ifstream inFile;
	string currentLine;

	string word1;
	string word2;
	istringstream iss;

	inFile.open("output.txt", ios::in);
	while (getline(inFile, currentLine)) {
		iss.clear();
		iss.str(currentLine);
		iss >> word1 >> word2;
		cout << "1: " << word1 << endl;
		cout << "2: " << word2 << endl;
		cout << endl;
	}
	inFile.close();
	system("pause");


	return 0;
}