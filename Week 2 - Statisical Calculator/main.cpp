#include <iostream>
#include <cmath>

using namespace std;


int main() {
	//Welcome message
	cout << "Mean and Standard Deviation Program" << endl << endl;

	//Get 6 numbers
	float num1, num2, num3, num4, num5, num6;
	cout << "Please enter 6 numbers" << endl << endl;
	cout << "First Number: ";
	cin >> num1;
	cout << endl;
	cout << "Second Number: ";
	cin >> num2;
	cout << endl;
	cout << "Third Number: ";
	cin >> num3;
	cout << endl;
	cout << "Fourth Number: ";
	cin >> num4;
	cout << endl;
	cout << "Fifth Number: ";
	cin >> num5;
	cout << endl;
	cout << "Sixth Number: ";
	cin >> num6;
	cout << endl;

	//Workout and print mean
	float total = num1 + num2 + num3 + num4 + num5 + num6;
	float mean = total / 6.0;

	cout << "The mean is: " << mean << endl;

	//Workout and print standard deviation
	//For each number, take away the mean and sqaure it
	//Add the value to a total
	//Times the total by 1/n-1 (0.2 or 1/5 in this case)
	//Then square root that
	float stanDeviation;
	total = 0;
	total += pow(num1 - mean, 2);
	total += pow(num2 - mean, 2);
	total += pow(num3 - mean, 2);
	total += pow(num4 - mean, 2);
	total += pow(num5 - mean, 2);
	total += pow(num6 - mean, 2);

	total *= 0.2;
	
	stanDeviation = sqrt(total);
	
	cout << "The standard deviation is: " << stanDeviation << endl;
	
	//Find the MIN and MAX values of the 6 numbers
	float min = num1;//Assume min value
	float max = num1;//Assume max value

	//FINDING THE MIN
	min < num2 ? min = min : min = num2;
	min < num3 ? min = min : min = num3;
	min < num4 ? min = min : min = num4;
	min < num5 ? min = min : min = num5;
	min < num6 ? min = min : min = num6;

	//FINDING THE MAX
	max < num2 ? max = num2 : max = max;
	max < num3 ? max = num3 : max = max;
	max < num4 ? max = num4 : max = max;
	max < num5 ? max = num5 : max = max;
	max < num6 ? max = num6 : max = max;

	
	//Print the MIN, MAX and Range
	cout << "Min is: " << min << endl;
	cout << "Max is: " << max << endl;
	cout << "Range is: " << max - min << endl;

	//Pause before exiting
	system("pause");
	//Return 0 to end main();
	return 0;
}