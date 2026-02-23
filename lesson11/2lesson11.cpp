/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string sourceFileName;
    std::string destFileName;

    std::cout << "Enter the source file name: ";
    std::getline(std::cin, sourceFileName);

    std::cout << "Enter the destination file name: ";
    std::getline(std::cin, destFileName);

    std::ifstream sourceFile(sourceFileName);

    if (!sourceFile) {
        std::cerr << "Error: Could not open the source file \"" << sourceFileName << "\"" << std::endl;
        return 1; 
    }

    std::ofstream destFile(destFileName, std::ios::trunc);

    if (!destFile) {
        std::cerr << "Error: Could not create/open the destination file \"" << destFileName << "\"" << std::endl;
        sourceFile.close(); 
        return 1; 
    }

    char ch;
    while (sourceFile.get(ch)) {
        destFile.put(ch);

        if (!destFile) {
            std::cerr << "Error: A write error occurred while copying." << std::endl;
            sourceFile.close();
            destFile.close();
            return 1;
        }
    }

    sourceFile.close();
    destFile.close();

    if (sourceFile.eof()) {
        std::cout << "File successfully copied from \"" << sourceFileName << "\" to \"" << destFileName << "\"" << std::endl;
    } else if (sourceFile.fail()) {
        std::cerr << "Error: An unknown read error occurred during the copy process." << std::endl;
        return 1;
    }

    return 0; 
}