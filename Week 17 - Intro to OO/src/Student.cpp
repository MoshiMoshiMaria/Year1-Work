#include "Student.h"
#include <string>


Student::Student(int id, std::string name, unsigned short int age)
{
	setId(id);
	setName(name);
	setAge(age);

}

Student::Student() {
	setId(-1);
	setName("Default");
	setAge(0);
}


Student::~Student()
{
}
void Student::setId(int value) {
	Student::id = value;
}

void Student::setName(std::string value) {
	Student::name = value;
}

void Student::setAge(unsigned short int value) {
	Student::age = value;
}

void Student::setCourse(std::string value) {
	Student::course = value;
}

void Student::coutAttr() {
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
}

int Student::getId() {
	return Student::id;
}

std::string Student::getName(){
	return Student::name;
}

unsigned short int Student::getAge() {
	return Student::age;
}

std::string Student::getCourse() {
	return Student::course;
}
