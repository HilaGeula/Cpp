/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <array>
#include <iostream>

int main()
{
   std::array<int,5> ages1,ages2;
   ages1.fill(13);
   ages2.fill(10);
  for(int i=0;i<5;i++){
     std::cout<<ages1.at(i)<<std::endl;
    //  std::cout<<ages2.at(i)<<std::endl;
  }
   
   ages1.swap(ages2);
   for(int i=0;i<5;i++){
     std::cout << ages1.at(i) << std::endl;
    //  std::cout << ages2.at(i) << std::endl;
   }
   std::cout << size() << std::endl;
   ages1[2]=3;
   for(int i=0;i<5;i++)
     std::cout << ages1.at(i) << std::endl

    return 0;
}     