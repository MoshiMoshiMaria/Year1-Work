#include "Leg.h"



Leg::Leg()
{
}


Leg::~Leg()
{
}

void Leg::raise() {
	isRaised = true;
}

void Leg::lower() {
	isRaised = false;
}
