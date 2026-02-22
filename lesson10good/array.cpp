#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> ages1, ages2;
    ages1.fill(10);
    ages2.fill(13);
    
    for(int i = 0; i < 5; i++){
        std::cout << ages1.at(i) << std::endl;
        std::cout << ages2.at(i) << std::endl;
    }
    
    ages1.swap(ages2);
    
        for(int i = 0; i < 5; i++){
        std::cout << ages1.at(i) << std::endl;
        std::cout << ages2.at(i) << std::endl;
    }
    
    std::cout << size(ages1) << std::endl;
    
    ages1[2]=3;
            for(int i = 0; i < 5; i++){
        std::cout << ages1.at(i) << std::endl;
    }
    return 0;
}
