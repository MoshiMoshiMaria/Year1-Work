#pragma once
#include <string>
#include <iostream>
#include "Leg.h"

class Quadruped
{
protected:
	static const int numOfLegs = 4;
	Leg legs[numOfLegs];
	std::string noise;
public:
	Quadruped();
	~Quadruped();
	void raiseLeg(int legIndex);
	void lowerLeg(int legIndex);
	void speak();

};

