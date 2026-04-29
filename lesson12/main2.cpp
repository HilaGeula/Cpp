/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

class Student {
public:
    std::string name;
    int age;
    double grade;

    Student(std::string n, int a, double g) : name(n), age(a), grade(g) {}

    void print() const {
        std::cout << "Name: " << std::left << std::setw(8) << name 
                  << " Age: " << age << " Grade: " << grade << std::endl;
    }
};

void readStudentsByValue(std::shared_ptr<std::ifstream> file, std::vector<Student>& vec) {
    std::cout << " [Value] Inside function, use_count: " << file.use_count() << std::endl;
    
    std::string name;
    int age;
    double grade;
    while (*file >> name >> age >> grade) {
        vec.emplace_back(name, age, grade);
    }
}

void printUseCountRef(const std::shared_ptr<std::ifstream>& file) {
    std::cout << " [Reference] Inside function, use_count: " << file.use_count() << std::endl;
}

int main() {
    std::ofstream outfile("students.txt");
    outfile << "Chedva 20 88.5\nChana 22 91.0\nSara 19 77.25\n";
    outfile.close();

    auto fileDeleter = [](std::ifstream* f) {
        std::cout << "File closed" << std::endl; 
        f->close();
        delete f;   
    };

    std::shared_ptr<std::ifstream> filePtr(new std::ifstream("students.txt"), fileDeleter);

    if (!filePtr->is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<Student> students;

    std::cout << "Main, initial use_count: " << filePtr.use_count() << std::endl;
    
    readStudentsByValue(filePtr, students);
    
    std::cout << "Main, after value function, use_count: " << filePtr.use_count() << std::endl;

    printUseCountRef(filePtr);
    std::cout << "Main, after reference function, use_count: " << filePtr.use_count() << std::endl;

    std::cout << "\nStudent Data:\n";
    for (const auto& s : students) {
        s.print();
    }

    return 0;
}
