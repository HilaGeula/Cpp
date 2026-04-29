/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <memory> 
#include <string>
#include <vector>

// Part 1
template <typename T> 
class ArrContainer {
    std::shared_ptr<T[]> data; 
    size_t size;               

public:
    ArrContainer(size_t s) : size(s) {
        data = std::shared_ptr<T[]>(new T[size]);
        std::cout << "Container allocated with " << size << " elements.\n";
    }

    ~ArrContainer() {
        std::cout << "Container destroyed.\n";
    }

    T& operator[](size_t index) {
        return data[index];
    }
};

// Part 2
class Course {
public:
    std::string name;
    int hours;
    double price;
    double passGrade;

    Course() : name(""), hours(0), price(0.0), passGrade(0.0) {}
    
    Course(std::string n, int h, double p, double pg) 
        : name(n), hours(h), price(p), passGrade(pg) {}
};

void printUseCountByValue(std::shared_ptr<Course[]> ptr) {
    std::cout << " Inside function (value): Use Count = " << ptr.use_count() << "\n";
}

void printUseCountByRef(const std::shared_ptr<Course[]>& ptr) {
    std::cout << " Inside function (ref): Use Count = " << ptr.use_count() << "\n";
}

// Part 3
class Student {
public:
    std::string name;
    int id;
    Student(std::string n, int i) : name(n), id(i) {}
};



int main() {
    // Part 1
    ArrContainer<int> intArr(5); 
    intArr[0] = 10;
    ArrContainer<std::string> strArr(2); 
    strArr[0] = "Hello";
    std::cout << "Int[0]: " << intArr[0] << ", Str[0]: " << strArr[0] << "\n";

    // Part 2
    std::shared_ptr<Course[]> courses(new Course[2]);

    for(int i = 0; i < 2; i++) {
        courses[i] = Course("Course_" + std::to_string(i), 40 + i, 500.0, 60.0);
    }

    std::cout << "Initial Use Count: " << courses.use_count() << "\n";

    printUseCountByValue(courses);
    std::cout << "After function (value): " << courses.use_count() << " (Decreased because local copy was destroyed)\n";

    printUseCountByRef(courses);
    std::cout << "After function (ref): " << courses.use_count() << "\n";

    // Part 3 
    std::unique_ptr<Student> s1(new Student("Ayala", 101));
    auto s3(new Student("Ayali", 102));
    //s1=s3;

    std::cout << "Before Move: Student name = " << s1->name << "\n";

    std::unique_ptr<Student> s2 = std::move(s1);
    
    if (s1 == nullptr) {
        std::cout << "After Move: s1 is now null (empty).\n";
    }
    if (s2 != nullptr) {
        std::cout << "After Move: s2 now owns the student: " << s2->name << " (ID: " << s2->id << ")\n";
    }

    return 0;
}
