#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class MyString {
private:
    char* data;
    int size;
    static const int maxLen = 100;
    static int instanceCount;
public:
    // 1
    MyString();

    // 2
    MyString(const char* s, int size);

    // 3
    MyString(const MyString& other);

    // 4
    MyString& operator=(const MyString& other);

    // 5
    MyString(MyString&& obj) noexcept;

    // 6
    MyString& operator=(MyString&& other) noexcept;

    // 7
    ~MyString();

    // 8
    const char* getData() const;

    // 9
    void setData(const char* new_data, int size);

    // 10
    static int getInstanceCount();


    //lesson5
    char& operator[](int index);             
    const char& operator[](int index) const;

    bool operator==(const MyString& other) const;

    operator bool() const;

    MyString operator+(const MyString& other) const;

    MyString operator-(int num) const;
};