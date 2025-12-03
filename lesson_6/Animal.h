#pragma once
class Animal
{
	public:
		virtual void MakeSound() const = 0;
		char* getType() const;
		virtual ~Animal();
};
