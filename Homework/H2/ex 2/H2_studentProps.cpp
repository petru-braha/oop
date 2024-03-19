#include "H2_studentFct.h"
#include <iostream>
void student::setName()
{
	char temp[250] = { 0 };
	std::cout << "the student, "; 
	std::cin.getline(temp, 250);
	strcpy_s(this->name, temp);
}
char* student::getName()
{
	return this->name;
}

void student::setMTH()
{
	std::cout << "math grade: ";
	std::cin >> this->marks[mathematics];
}
float student::getMTH()
{
	return this->marks[mathematics];
}

void student::setENG()
{
	std::cout << "english grade: ";
	std::cin >> this->marks[english];
}
float student::getENG() 
{
	return this->marks[english];
}

void student::setHST()
{
	std::cout << "history grade: ";
	std::cin >> this->marks[history];
}
float student::getHST()
{
	return this->marks[history];
}

float student::average_grade()
{
	float s = 0;
	for (int i = 0; i < 3; i++)
		s += this->marks[i];
	return s / 3;
}