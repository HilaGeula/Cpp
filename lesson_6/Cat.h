#pragma once
#include "Animal.h"
class Cat : public Animal
{
	void MakeSound() const override;
	char* getType() const;
	~Cat() override;
};

