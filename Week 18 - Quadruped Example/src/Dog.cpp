#include "Dog.h"
#include <iostream>

Dog::Dog()
{
	noise = "Woof";
}


Dog::~Dog()
{
}

void Dog::speak() {
	std::cout << "Bark";
}