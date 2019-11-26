#include <string>
#include <iostream>

#pragma once
class Student
{
private:
	int id;
	std::string name;
	unsigned short int age;
	std::string course;

public:
	Student(int id, std::string name, unsigned short int age);
	Student();
	~Student();

	void setId(int value);

	void setName(std::string value);

	void setAge(unsigned short int value);

	void setCourse(std::string value);

	void coutAttr();

	int getId();

	std::string getName();

	int getAge();

	std::string getCourse();

};

