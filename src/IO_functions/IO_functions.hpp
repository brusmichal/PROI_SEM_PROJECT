#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H
#include <iostream>
#include <limits>

static void pause() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string dummy;
    std::cout << "Press any key to continue . . .";
    std::getline(std::cin, dummy);
}

static void clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

static long long enter_number()
{
    using std::cin;
    using std::cout;
    using std::endl;
    long long number;
    while (1)
    {

        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "cos zle wprowadziles " << endl;
        }
        else
            break;
        cout << "sprobuj ponownie: ";
    }
    return number;
}

static char enter_char()
{
    using std::cin;
    using std::cout;
    using std::endl;
    std::string znak;
    while (1)
    {
        cin >> znak;
        if (znak != "B" && znak != "C")
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "cos zle wprowadziles " << endl;
        }
        else
            break;
        cout << "sprobuj ponownie: ";
    }
    char znak2;
    znak2 = znak[0];
    return znak2;
}
#endif