#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H
#include <iostream>
#include <limits>

void pause() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string dummy;
    std::cout << "Press any key to continue . . .";
    std::getline(std::cin, dummy);
}

void clear(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

#endif