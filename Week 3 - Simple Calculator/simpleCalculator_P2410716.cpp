// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Include Libraries
//#include "pch.h"
#include <iostream>
#include "Windows.h"

//Only std namespace will be used
using namespace std;

void menu() {
	cout << endl;
	cout << "What would you like to do?: " << endl;
	cout << "\t1: Add two numbers" << endl;
	cout << "\t2: Sub two numbers" << endl;
	cout << "\t3: Multiply two numbers" << endl;
	cout << "\t4: Divide two numbers" << endl;
	cout << "\t5: MOD two numbers" << endl;
	cout << "\t6: Find the mean of N numbers" << endl;
	cout << "\t-1: Exit the program" << endl;
	cout << endl;
}//END FUNCTION

void getNumberInputs(float& number1, float& number2) {
	float number;
	cout << "Enter the first number: ";
	cin >> number;
	cout << endl;
	number1 = number;
	cout << "Enter the second number: ";
	cin >> number;
	cout << endl;
	number2 = number;

}//END FUNCTION

int getChoice() {
	int choice;
	cout << endl << "Option: ";
	cin >> choice;
	return choice;
}//END FUNCTION

bool checkExit(bool endLoop) {
		//If input is -1, confirm their choice
		char confirm;
		cout << "Are you sure? y/n: ";
		cin >> confirm;
		//If they input y or Y then the loop breaks
		confirm == 'Y' || confirm == 'y' ? endLoop = true : endLoop = false;
		return endLoop;
}//END FUCTION

float add(float number1, float number2) {
	return number1 + number2;
}
float sub(float number1, float number2) {
	return number1 - number2;
}
float mult(float number1, float number2) {
	return number1 * number2;
}
float div(float number1, float number2) {
	return number1 / number2;
}
float MOD(int number1, int number2) {
	return number1 % number2;
}
void mean() {
	int amountOfNumbers;
	cout << "How many numbers are there?(max 100): ";
	cin >> amountOfNumbers;
	cout << endl;
	//create an array with plenty of spaces
	float numberList[100];
	//get the right amount of numbers using a FOR loop
	for (int i = 0; i < amountOfNumbers; i++) {
		cout << "Enter number " << i + 1 << ": ";
		cin >> numberList[i]; //put the input into the array
		cout << endl;
	}
	//set up a value for the total
	float total;
	total = 0;
	//part one of the display message
	cout << "The mean of ";
	//loop through each number till we have them all
	for (int j = 0; j < amountOfNumbers; j++) {
		//add the number to the total
		total += numberList[j];
		//print the number on the display line
		if (j != amountOfNumbers - 1) {
			cout << numberList[j] << ", "; //if it's not the last number, add a comma afterwards
		}
		else {
			cout << numberList[j] << " is ";//if it's the last number, dont put a comma, put 'is' instead
		}
	}
	cout << total / (float)amountOfNumbers << endl; //Add the mean to the display bar
}


void performOperation(int choice) {
	float number1, number2;
	//The user does not want to quit, so see what they want to do and do it
	switch (choice) {
		//float number1, number2;
	case 1:
		getNumberInputs(number1, number2);
		//If input is 1, add the numbers and output the result
		cout << endl;
		cout << number1 << " + " << number2 << " = " << add(number1,number2) << endl;
		break;//BREAK SWITCH
	case 2:
		getNumberInputs(number1, number2);
		//If input is 2, subtract the numbers and output the result
		cout << endl;
		cout << number1 << " - " << number2 << " = " << sub(number1,number2) << endl;
		break;//BREAK SWITCH
	case 3:
		getNumberInputs(number1, number2);
		//If input is 3, multiply the numbers and output the result
		cout << endl;
		cout << number1 << " x " << number2 << " = " << mult(number1,number2) << endl;
		break;//BREAK SWITCH
	case 4:
		getNumberInputs(number1, number2);
		//If input is 4, divide the numbers and output the result
		cout << endl;
		//If statement to prevent division by zero errors
		if (number2 != 0.0) {
			cout << number1 << " / " << number2 << " = " << div(number1,number2) << endl;
		}//END IF
		else {
			cout << "Division by Zero is not allowed" << endl;
		}//END ELSE
		break;//BREAK SWITCH
	case 5:
		getNumberInputs(number1,number2);
		//If input is 5, MOD the numbers and output the result
		cout << endl;
		cout << number1 << " MOD " << number2 << " = " << MOD((int)number1,(int)number2) << endl;
		break;//BREAK SWITCH
	case 6:
		//If input is 6, get an amount of numbers for the mean
		mean();
		break;//BREAK SWITCH
	default:
		cout << "Invalid Option";
		cout << endl;
	}//END SWITCH
}//END FUNCTION




int main() {
	//Welcome Message
	cout << "Calculator Program" << endl << endl;
	cout << "Enter numbers when prompted" << endl;
	cout << "Entering a char or a string will break it, so that's on you" << endl;
	cout << endl;

	//Set up loop condition
	bool endLoop = false;
	//Begin Loop
	while (!endLoop) {
		//Print Menu
		menu();

		//Set up input variable and get input
		int choice;
		choice = getChoice();
		
		//Check if choice is -1 (quit the program)
		switch (choice) {
		case -1:
			endLoop = checkExit(endLoop);
		default:
			performOperation(choice);
		}//END SWITCH
	}//END WHILE

	//After loop ends, print goodbye message
	cout << endl << "Exiting program..." << endl;
	Sleep(500);//Sleep is only here for a bit of flair
	return 0;//return 0 to end main()
}//END MAIN