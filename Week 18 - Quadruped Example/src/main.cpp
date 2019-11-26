#include <iostream>
#include "Cat.h"
#include "Dog.h"

using namespace std;


int main()
{
	Cat Sanjay;
	Dog Danjay;

	cout << "Sanjay sez: ";
	Sanjay.speak();
	cout << endl;

	cout << "Dan sez: ";
	Danjay.speak();
	cout << endl;

	system("pause");
	return 0;

}