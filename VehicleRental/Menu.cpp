#include <iostream>
#include "VehicleRental.hpp"

Vehicle enter_vehicle()
{
    std::string name, drugi;
    int jeden, dwa;
    using std::cout;
    using std::cin;
    cout << "Podaj nazwe "; cin >> name;
    cout << "Podaj rok produkcji "; cin >> jeden;
    cout << "Podaj nr rejestracyjny "; cin >> drugi;
    cout << "Podaj koszt wypozyczenia "; cin >> dwa;
    Vehicle autko(name, jeden, drugi, dwa);
    return autko;
}

Customer enter_customer()
{
    std::string name, drugi;
    long long jeden;
    char dwa;
    using std::cout;
    using std::cin;
    cout << "Podaj imie "; cin >> name;
    cout << "Podaj nazwisko "; cin >> drugi;
    cout << "Podaj pesel "; cin >> jeden;
    cout << "Podaj typ prowojazd "; cin >> dwa;
    Customer ktos(name, drugi, jeden, dwa);
    return ktos;
}

void VehicleRental::Menu()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int x = 8;
    while (x > 0 && x < 9) {
        system("cls");
        cout << "Witaj co chcesz zrobic: \n1.Dodaj pojazd  \n2.Dodaj klienta\n";
        cout << "Wybor:" << std::endl;
        std::cin >> x;
        system("cls");
        switch (x)
        {
        case 1:
            Add(enter_vehicle());
            cout << "Dodano pojazd";
        case 2:
            Add(enter_customer());
        case 0:
            break;
        }

    }
}

