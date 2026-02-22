/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <map>
#include <vector>
#include <iostream>

int main()
{
std::map<std::string, std::vector<int>>map;
map["bb"] = {98,99,100};
map["cc"] = {89,78,90};
map["dd"] = {67,78,89};
map.insert({"aa",{67,89,99}});
map.at("cc") = {99,90,98};
auto x=map.at("cc");
for(int i;i<size(x);i++){
  std::cout << x<< std::endl;
}

for(auto & [name,grades]: map){
    std::cout << name <<": " <<std::endl;
    for(auto grad: grades){
        std::cout << grad << ","<< std::endl;
    }
}

map["bb"].push_back(90);
map.erase("aa");
auto x=map.find("cc");
if (x!=map.end()){
    std::cout << "found" << std::endl;
}
map.clear();



    return 0;
}     