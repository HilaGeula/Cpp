#include "Cat.h"
#include <iostream>

void Cat::MakeSound() const
{
	std::cout << "Meow!" << std::endl;
}

char* Cat::getType() const
{
	char* type = new char[3];
	strcpy_s(type, 3, "Cat");
	return type;
}

Cat::~Cat() {};