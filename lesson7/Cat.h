#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Animal.h"
class Cat : public Animal
{
	void MakeSound() const override;
	string getType() const;
	friend ostream& operator<<(ostream& os, const Cat& obj);
	~Cat() override;
};

