#pragma once
#include "Animal.h"
class Dog : public Animal
{
	void MakeSound() const override;
	char* getType() const;
	~Dog() override;
};

