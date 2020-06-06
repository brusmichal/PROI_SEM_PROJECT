#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H


void pause() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string dummy;
    std::cout << "Press any key to continue . . .";
    std::getline(std::cin, dummy);
}

void clear(){};

#endif