/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <set>
#include <iostream>

int main()
{
std::set < std::string> names;
names.insert("sara");
names.insert("as");
names.insert("sa");
names.insert("ee");
names.insert("mm");
// std::cout << size(names) << std::endl;

names.insert("sara");
names.insert("as");
names.insert("sa");
names.insert("ee");
names.insert("mm");
// std::cout << size(names) << std::endl;

// std::cout << names.count("mm") << std::endl;

int x=names.find("as");
if(x!= names.end()){
    std::cout << "found" << std::endl;
}

for( int i=names.begin();i!=names.end();i++){
    std::cout << *i << std::endl;
}

names.erase("as");
std::cout << size(names) << std::endl;

    return 0;
}     