// lesson4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyString.h";
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h";

    //lesson5
    TEST_CASE("operators") {
        MyString s1("Test", 4);
        MyString s2("Test", 4);
        MyString s3("Another", 7);

        // Test operator[]
        CHECK(s1[0] == 'T');
        CHECK_THROWS(s1[8]);

        // Test operator==
        CHECK(s1 == s2);
        CHECK(s1.getData() != s3.getData());

        // Test operator bool()
        CHECK(bool(s1) == true);
        CHECK(bool(MyString()) == false);

        // Test operator+
        MyString s4 = s1 + s2;
        //CHECK(s4.getData() == "TestTest");

        // Test operator-
        //MyString s5 = s1 - s2;
        //CHECK(s4.getData() == "Test");
    }