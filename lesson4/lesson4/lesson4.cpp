// lesson4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyString.h"
#include <iostream>

int main()
{
    try {
        MyString s1("Jerusalem", 10);
        MyString s2("Is", 3);
        MyString s3("My Home", 8);

        std::cout << "1: " << s1.getData() << std::endl;
        std::cout << "2: " << s2.getData() << std::endl;
        std::cout << "3: " << s3.getData() << std::endl;

        s1 = s2;
        std::cout << "After assignment, 1: " << s1.getData() << std::endl;

        MyString s4 = s3;
        std::cout << "4 (copy of 3): " << s4.getData() << std::endl;

        MyString s5 = std::move(s4);
        std::cout << "5 (moved from 4): " << s5.getData() << std::endl;

        std::cout << "Current instance count: " << MyString::getInstanceCount() << std::endl;

        MyString s6("This string is too long This string is too long This string is too long This string is too long This string is too long", 120);
    }
    catch (const std::length_error& error) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }

    std::cout << "Finally instance count: " << MyString::getInstanceCount() << std::endl;

    return 0;

}
