#include <iostream>
#include <vector>



int main()
{
    std::vector<int> v = {0, 0};
    
    for(int i=1; i<6; i++)
    {
        v.push_back(i);
    }
    v.emplace(v.begin()+3, 10);
    v.push_back(20);
    v.erase(v.begin()+2);
    for(int num : v)
    {
        std::cout<< num <<" ";
    }
    for(std::vector<int>::iterator it = v.end()-1; it != v.begin(); --it) {
        std::cout<< *it <<" ";
    }
    
    return 0;
}