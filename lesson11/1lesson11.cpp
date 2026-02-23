/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Input: [";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << (i == numbers.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0,
        [](int total, int n) {
            if (n % 2 == 0) {
                return total + (n * n);
            } else {
                return total; 
            }
        }
    );

    std::cout << "Output: " << sum_of_squares << std::endl;

    return 0;
}