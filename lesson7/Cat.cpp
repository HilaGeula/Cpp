#include "Cat.h"
#include <iostream>
#include <string>
using namespace std;

void Cat::MakeSound() const
{
	std::cout << "Meow!" << std::endl;
}

string Cat::getType() const
{
	return "Cat";
}

ostream& operator<<(ostream& os, const Cat& obj)
{
	os << "Cat Value: " << obj.getType();
	return os;
}

Cat::~Cat() {};