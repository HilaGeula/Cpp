#include "Dog.h"
#include <iostream>
#include <string>
using namespace std;

void Dog::MakeSound() const
{
	std::cout << "Woof!" << std::endl;
}

string Dog::getType() const
{
	return "Dog";
}

ostream& operator<<(ostream& os, const Dog& obj)
{
	os << "Dog Value: " << obj.getType();
	return os;
}

Dog::~Dog() {};