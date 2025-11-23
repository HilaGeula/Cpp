#include "MyString.h"
#include <iostream>

int MyString::instanceCount = 0;

MyString::MyString() : MyString("", 0)
{
	std::cout << "Default constructor" << std::endl;
}

MyString::MyString(const char* newS, int newSize)
{
	if (newSize > maxLen)
	{
		throw std::length_error("string exceeds maximum length");
	}
	size = newSize;
	data = new char[newSize + 1];
	strcpy_s(data, newSize + 1, newS);
	instanceCount++;

	std::cout << "Main constructor" << std::endl;
}

MyString::MyString(const MyString& other)
{
	size = other.size;
	data = new char[size + 1];
	strcpy_s(data, size + 1, other.data);
	instanceCount++;

	std::cout << "Copy constructor" << std::endl;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		delete[] data;
		size = other.size;
		data = new char[size + 1];

		if (other.data)
		{
			strcpy_s(data, size + 1, other.data);
		}
		else
		{
			data[0] = '\0';
		}

		std::cout << "assignment operator" << std::endl;
	}
	return *this;
}

MyString::MyString(MyString&& obj) noexcept : data(obj.data), size(obj.size)
{
	obj.data = nullptr;
	obj.size = 0;
	instanceCount++;

	std::cout << "Move constructor" << std::endl;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		delete[] data;

		data = other.data;
		size = other.size;

		other.data = nullptr;
		other.size = 0;

		std::cout << "move assignment operator" << std::endl;
	}
	return *this;
}

MyString::~MyString()
{
	delete[] data;
	instanceCount--;

	std::cout << "Destructor" << std::endl;
}

const char* MyString::getData() const
{
	return data;
}

void MyString::setData(const char* newData, int newSize)
{
	if (newSize > maxLen)
	{
		throw std::length_error("string exceeds maximum length");
	}

	delete[] data;
	size = newSize;
	data = new char[size + 1];
	strcpy_s(data, size + 1, newData);
}

int MyString::getInstanceCount()
{
	return instanceCount;
}