#pragma once
class TimeOfDay
{
private:
	int id;
	unsigned short int hour;
	unsigned short int minute;
	unsigned short int second;

public:
	TimeOfDay();
	~TimeOfDay();

	void setHour(unsigned short int value);
	void setMinute(unsigned short int value);
	void setSecond(unsigned short int value);

	int getHour();
	int getMinute();
	int getSecond();

	void coutTime();

	void compareTime(TimeOfDay time1, TimeOfDay time2);
};

