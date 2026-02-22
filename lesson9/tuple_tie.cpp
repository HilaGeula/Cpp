#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> func(int id, double gpa, std::string name){
    std::tuple<int, double, std::string> myTuple(id, gpa, name);
    return myTuple;
}

int main()
{
    int id;
    double gpa;
    std::string name;

    std::tie(id, gpa, name) = func(123, 99.9, "You");
    
    std::cout << "Integer: " << id << std::endl;
    std::cout << "Double: " << gpa << std::endl;
    std::cout << "String: " << name << std::endl;
    
    auto[id2, gpa2, name2] = func(456, 90.7, "Everyone");
    
    std::cout << "Integer: " << id2 << std::endl;
    std::cout << "Double: " << gpa2 << std::endl;
    std::cout << "String: " << name2 << std::endl;

    return 0;
}