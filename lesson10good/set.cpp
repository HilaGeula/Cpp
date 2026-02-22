#include <iostream>
#include <set>

int main()
{
    
    std::set<std::string> names;
    
        names.insert("AA");
        names.insert("BB");
        names.insert("CC");
        names.insert("DD");
        names.insert("EE");
    std::cout << size(names) << std::endl;
        names.insert("BB");
        names.insert("CC");
        names.insert("DD");
        names.insert("EE");
    std::cout << size(names) << std::endl;
    std::cout <<names.count("DD") << std::endl;
    std::cout <<names.count("SS") << std::endl;
    auto x= names.find("AA");
    if(x!=names.end())
        std::cout <<"found" << std::endl;

    for(auto i = names.begin(); i!= names.end(); i++){
        std::cout << *i << std::endl;
    }
    names.erase("AA");
    std::cout << size(names) << std::endl;
    

    return 0;
}
