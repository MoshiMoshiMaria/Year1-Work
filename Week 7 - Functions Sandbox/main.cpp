#include <iostream>
#include "math.h"

using namespace std;

const float pi = 3.14159;

float doubleNumber(float number) {
	return number * 2.0;
}

void trig1(float angle, float hypotenuse, float& adjacent, float& opposite) {
	adjacent = cosf(angle)*hypotenuse;
	opposite = sinf(angle)*hypotenuse;
}

int main() {
	float adjacent;
	float opposite;

	float hypotenuse = 25;
	float angle = 30;

	angle *= pi / 180;

	trig1(angle, hypotenuse, adjacent, opposite);
	
	cout << "Adjacent: " << adjacent << endl;
	cout << "Opposite: " << opposite << endl;

	system("pause");
	return 0;
}