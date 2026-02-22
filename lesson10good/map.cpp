#include <iostream>
#include <map>
#include <vector>

int main()
{
    std::map<std::string, std::vector<int>> map;
    map["AA"]={89,95,97};
    map["BB"]={92,75,74};
    map["CC"]={64,97,52};
    map.insert({"DD", {95,95,99}});
    map.at("AA")={99,99,100};
    auto x=map.at("AA");
    for(auto i = 0; i<size(x); i++){
        std::cout << x[i] << std::endl;
    }
    for(auto &[name,grades]: map){
        std::cout << name<< std::endl;
        for(auto grade: grades){
            std::cout << grade << std::endl;
    }
    map["AA"].push_back(90);
    map.erase("BB");
    auto x=map.find("CC");
    if(x!=map.end())
        std::cout << "found CC"<< std::endl;
    }
    map.clear();

    return 0;
}
