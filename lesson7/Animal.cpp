#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;

string Animal::getType() const {
	return "unknown animal";
}

ostream& operator<<(ostream& os, const Animal& obj)
{
	os << "Animal Value: " << obj.getType();
	return os;
}

Animal::~Animal() {};