#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Animal.h"
class Dog : public Animal
{
	void MakeSound() const override;
	string getType() const;
	friend ostream& operator<<(ostream& os, const Dog& obj);
	~Dog() override;
};

