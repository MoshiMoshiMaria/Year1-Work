#include "Quadruped.h"



Quadruped::Quadruped()
{
}


Quadruped::~Quadruped()
{
}

void Quadruped::raiseLeg(int legIndex) {
	if (legIndex < numOfLegs && legIndex > -1) {
		legs[legIndex].raise();
	}
}

void Quadruped::lowerLeg(int legIndex) {
	if (legIndex < numOfLegs && legIndex > -1) {
		legs[legIndex].lower();
	}
}

void Quadruped::speak() {
	std::cout << noise;
}
