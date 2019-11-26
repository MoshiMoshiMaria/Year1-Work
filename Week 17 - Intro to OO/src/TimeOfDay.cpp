#include "TimeOfDay.h"
#include <iostream>


TimeOfDay::TimeOfDay()
{
	setHour(0);
	setMinute(0);
	setSecond(0);
}


TimeOfDay::~TimeOfDay()
{
}

void TimeOfDay::setHour(unsigned short int value) {
	hour = value;
}

void TimeOfDay::setMinute(unsigned short int value) {
	minute = value;
}

void TimeOfDay::setSecond(unsigned short int value) {
second = value;
}

int TimeOfDay::getHour() {
	return hour;
}

int TimeOfDay::getMinute() {
	return minute;
}

int TimeOfDay::getSecond() {
	return second;
}

void TimeOfDay::coutTime() {
	std::cout << hour << ":" << minute << ":" << second;
}

void TimeOfDay::compareTime(TimeOfDay time1, TimeOfDay time2) {
	TimeOfDay Smaller;

	time1.getHour() < time2.getHour() ? Smaller = time1 : Smaller = time2;
	time2.getHour() < time1.getHour() ? Smaller = time2 : Smaller = time1;

	if (time1.getHour() == time2.getHour()) {

		time1.getMinute() < time2.getMinute() ? Smaller = time1 : Smaller = time2;
		time2.getMinute() < time1.getMinute() ? Smaller = time2 : Smaller = time1;
	}

	if (time1.getMinute() == time2.getMinute()) {
		time1.getSecond() < time2.getSecond() ? Smaller = time1 : Smaller = time2;
		time2.getSecond() < time1.getSecond() ? Smaller = time2 : Smaller = time1;
	}

	std::cout << "The lesser time is ";
	Smaller.coutTime();
	std::cout << std::endl;
}