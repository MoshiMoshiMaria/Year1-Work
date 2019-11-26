#include "Cat.h"
#include <iostream>



Cat::Cat()
{
	noise = "Meow";
}


Cat::~Cat()
{
}

void Cat::speak() {
	std::cout << "Meow";
}