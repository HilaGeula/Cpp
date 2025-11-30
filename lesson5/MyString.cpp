#include <iostream>
#include "MyString.h"

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
		strcpy_s(data, size + 1, other.data);
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

//lesson5
char& MyString::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

const char& MyString::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

bool MyString::operator==(const MyString& other) const
{
	return (size == other.size) && (strcmp(data, other.data) == 0);
}

MyString::operator bool() const
{
	return data && data[0] != '\0';
}


MyString MyString::operator+(const MyString& other) const {
	MyString newStr;
	newStr.size = size + other.size;
	if (newStr.size > maxLen) {
		throw std::length_error("Combined string exceeds maximum length");
	}
	newStr.data = new char[newStr.size + 1];
	strcpy_s(newStr.data, newStr.size + 1, data);
	strcat_s(newStr.data, newStr.size + 1, other.data);
	return newStr;
}

MyString MyString::operator-(int num) const
{
	MyString result;
	if(num>size)
		throw std::out_of_range("Num out of bounds");
	size_t newSize = strlen(data) - num + 1;
	result.size = newSize;
	result.data[newSize] = '\0';
	return result;
}