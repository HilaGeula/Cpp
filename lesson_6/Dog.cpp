#include "Dog.h"
#include <iostream>

void Dog::MakeSound() const
{
	std::cout << "Woof!" << std::endl;
}

char* Dog::getType() const
{
	char* type = new char[3];
	strcpy_s(type, 3, "Dog");
	return type;
}

Dog::~Dog() {};