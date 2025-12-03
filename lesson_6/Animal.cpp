#include "Animal.h"
#include <iostream>

char* Animal::getType() const {
	char* type = new char[15];
	strcpy_s(type, 15, "unknown animal");
	return type;
}

Animal::~Animal() {};