#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

bool isDelim(char character, vector<char> delims) {
	for (int i = 0; i < delims.size(); i++) {
		if (character == delims[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	string usersInput;
	cout << "Type a sentence: ";
	getline(cin, usersInput);
	cout << endl;

	vector<string> splitSentence(0);

	vector<char> delims(1);
	delims[0] = ' ';

	ifstream inFile;
	inFile.open("delims.txt", ios::in);
	string currentLine;
	char currentChar;
	istringstream iss;
	while (getline(inFile, currentLine)) {
		iss.clear();
		iss.str(currentLine);
		iss >> currentChar;
		delims.push_back(currentChar);
	}
	inFile.close();


	//v1
	int subStringStart = 0;
	for (int letterIndex = 0; letterIndex < usersInput.length(); letterIndex++) {
		if (isDelim(usersInput[letterIndex], delims)) {
			splitSentence.push_back(usersInput.substr(subStringStart, (letterIndex - subStringStart)));
			subStringStart = letterIndex + 1;
		}
		else if (usersInput.length() - letterIndex == 1) {
			splitSentence.push_back(usersInput.substr(subStringStart, (letterIndex - subStringStart) + 1));
		}
	}
	for (int word = 0; word < splitSentence.size(); word++) {
		cout << splitSentence[word] << endl;
	}

	system("pause");
	return 0;
}
