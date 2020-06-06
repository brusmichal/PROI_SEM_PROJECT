#include "VehicleRental.hpp"

Car enter_car()
{
    std::string name, drugi;
    int jeden, dwa, trzy;
    using std::cout;
    using std::cin;
    cout << "Podaj nazwe "; cin >> name;
    cout << "Podaj rok produkcji "; cin >> jeden;
    cout << "Podaj nr rejestracyjny "; cin >> drugi;
    cout << "Podaj koszt wypozyczenia "; cin >> dwa;
    cout << "Podaj liczbe siedzeń "; cin >> trzy;
    Car autko(name, jeden, drugi, dwa, trzy);
    return autko;
}

Truck enter_truck()
{
    std::string name, drugi;
    int jeden, dwa, trzy;
    using std::cout;
    using std::cin;
    cout << "Podaj nazwe "; cin >> name;
    cout << "Podaj rok produkcji "; cin >> jeden;
    cout << "Podaj nr rejestracyjny "; cin >> drugi;
    cout << "Podaj koszt wypozyczenia "; cin >> dwa;
    cout << "Podaj pojemnosc bagznika "; cin >> trzy;
    Truck autko(name, jeden, drugi, dwa, trzy);
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
/*------------------------------------------------------------------------------------------------*/
void VehicleRental::menu_customer(int numer)
{
    long long pesel;
    int ile, wybor;
    bool ifDelete = 0;
    using std::cout;
    using std::cin;
    using std::endl;
    int x = 8;
    while (x > 0 && x < 9) {
        system("cls");
        cout << CustomerList[numer] << endl;
        cout << "Co chcesz zrobic: \n1.Wypozycz pojazd  \n2.Oplac \n3.Zwroc pojazd\n4.Usun klienta\n0.Wroc\n";
        cout << "Wybor: ";
        std::cin >> x;
        system("cls");
        switch (x)
        {
        case 1:
            int end;
            cout << CustomerList[numer] << endl;
            cout << "Dostepne samochody" << endl;
            for (int i = 0; i < CarList.size(); ++i) {
                if (CarList[i].canRent()) cout << i << " " << CarList[i] << endl;
                end = i;
            }
            for (int i = 0; i < TruckList.size(); ++i)
                if (TruckList[i].canRent()) cout << end + i + 1 << " " << TruckList[i] << endl;
            cout << "Ktory pojazd wypozyczyc? "; cin >> wybor;
            if (wybor < CarList.size() + TruckList.size() && wybor >= 0) {
                if (wybor > end) Rent(TruckList[wybor - (end + 1)], CustomerList[numer]);
                else Rent(CarList[wybor], CustomerList[numer]);
            }
            else {
                cout << "Wpisano numer spoza listy! Prosze takich rzeczy nie robic!" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << CustomerList[numer] << endl;
            cout << "Oplac \nPodaj kwote "; cin >> ile;
            CustomerList[numer].pay(ile);
            break;
        case 3:
            if (CustomerList[numer].rented_vehicle.numberplate != "BS00000") {
                cout << CustomerList[numer] << endl;
                Return(CustomerList[numer]);
            }
            break;
        case 4:
            int a;
            cout << "Czy na pewno chcesz usunac klienta?" << endl;
            cout << "0 - NIE" << endl;
            cout << "1 - TAK" << endl;
            cin >> a;
            switch (a) {
            case 0:
                break;
            case 1:
                ifDelete = 1;
                x = 0;
                break;
            }
            break;
        case 0:
            break;
        }
    }
    if (ifDelete) {
        if (CustomerList[numer].rented_vehicle.numberplate != "BS00000") Return(CustomerList[numer]);
        Delete(CustomerList[numer]);
        cout << "Klient zostal usuniety" << endl;
        system("pause");
    }
}
/*-----------------------------------------------------------------------------------------*/
void VehicleRental::menu_vehicle(int numer, bool isTruck)
{
    int ile, wybor, a;
    bool ifDelete = 0;
    using std::cout;
    using std::cin;
    using std::endl;
    int x = 8;
    while (x > 0 && x < 9) {
        system("cls");
        if (isTruck) cout << TruckList[numer] << endl;
        else cout << CarList[numer] << endl;
        cout << "Co chcesz zrobic: \n1.Wypozycz pojazd  \n2.Napraw \n3.Usun z wypozyczalni \n0.Wroc\n";
        cout << "Wybor: ";
        std::cin >> x;
        system("cls");
        switch (x)
        {
        case 1:
            cout << "Osoby mogace wypozyczyc" << endl;
            for (int i = 0; i < CustomerList.size(); ++i)
                if (CustomerList[i].rented_vehicle.numberplate=="BS00000") cout << i << " " << CustomerList[i] << endl;
            cout << "Kto chce wypozyczyc wypozyczyc? "; cin >> wybor;
            if (isTruck) Rent(TruckList[numer], CustomerList[wybor]);
            else Rent(CarList[numer], CustomerList[wybor]);
            system("pause");
            break;
        case 2:
            if (isTruck) TruckList[numer].Repair();
            else CarList[numer].Repair();
            system("pause");
            break;
        case 3:
            bool isRent;
            if (isTruck) isRent = TruckList[numer].isRent;
            else isRent = CarList[numer].isRent;
            if (isRent) {
                cout << "Nie mozna usunac wypozyczonego pojazdu!" << endl;
                system("pause");
            }
            else {
                cout << "Czy na pewno chcesz usunac pojazd?" << endl;
                cout << "0 - NIE" << endl;
                cout << "1 - TAK" << endl;
                cin >> a;
                switch (a) {
                case 0:
                    break;
                case 1:
                    ifDelete = 1;
                    x = 0;
                    break;
                }
            }
            break;
        case 0:
            break;

        }

    }
    if (ifDelete && isTruck) {
        Delete(TruckList[numer]);
        cout << "Pojazd zostal usuniety" << endl;
        system("pause");
    }
    if (ifDelete && !isTruck) {
        Delete(CarList[numer]);
        cout << "Pojazd zostal usuniety" << endl;
        system("pause");
    }
}
/*------------------------------------------------------------------------------------------------*/
void VehicleRental::menu_show()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int x = 1;
    while (x > 0 && x < 3) {
        system("cls");
        cout << "Co pokazac: \n1.Lista klientow  \n2.Lista pojazdow \n0.Wroc\n";
        cout << "Wybor: ";
        std::cin >> x;
        switch (x)
        {
        case 1:
            int a;
            CustomerTypes type_c;
            cout << "Klienci: \n1.Wszyscy  \n2.Zadluzeni \n0.Wroc\n";
            cout << "Wybor: ";
            std::cin >> a;
            system("cls");
            switch (a) {
            case 1:
                type_c = all_c;
                cout << "Lista wszytskich klientow" << endl;
                break;
            case 2:
                type_c = in_debt;
                cout << "Lista zadluzonych klientow" << endl;
                break;
            }
            ShowCustomerList(type_c);
            system("pause");
            break;
        case 2:
            int b;
            VehicleTypes type_v;
            cout << "Pojazdy: \n1.Wszystkie  \n2.Wolne \n3.Wypozyczone \n4.Samochody Osobowe \n5.Samochody Ciezarowe \n";
            cout << "Wybor: ";
            std::cin >> b;
            system("cls");
            switch (b) {
            case 1:
                type_v = all_v;
                cout << "Lista wszytskich pojazdow" << endl;
                break;
            case 2:
                type_v = free_v;
                cout << "Lista wolnych pojazdow" << endl;
                break;
            case 3:
                type_v = rented;
                cout << "Lista wypozyczonych pojazdow" << endl;
                break;
            case 4:
                type_v = car_t;
                cout << "Lista samochodow osobowych" << endl;
                break;
            case 5:
                type_v = truck_t;
                cout << "Lista samochodow ciezarowych" << endl;
                break;
            }
            ShowVehicleList(type_v);
            system("pause");
            break;
        case 0:
            break;
        }
    }
}
/*-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------*/
void VehicleRental::Menu()
{
    long long pesel;
    std::string nr;
    bool isTruck = 1;
    using std::cout;
    using std::cin;
    using std::endl;
    int x = 8;
    LoadData();
    system("pause");
    while (x != 0) {
        int numer = -1;
        system("cls");
        cout << "Witaj co chcesz zrobic: \n1.Dodaj pojazd osobowy \n2.Dodaj pojazd ciezarowy \n3.Dodaj klienta\n4.Panel klienta\n5.Panel samochodu\n6.Pokaz\n0.wyjdz\n";
        cout << "Wybor: ";
        std::cin >> x; if (!cin) { cout << "To nie cyfra"; } //sposob sprawdzania czy wpisanej pozycji
        system("cls");
        switch (x)
        {
        case 1:
            Add(enter_car());
            cout << "Dodano pojazd";
            break;
        case 2:
            Add(enter_truck());
            cout << "Dodano pojazd";
            break;
        case 3:
            Add(enter_customer());
            break;
        case 4:
            cout << "Podaj pesel "; cin >> pesel;
            for (int i = 0; i < CustomerList.size(); ++i)
                if (CustomerList[i].pesel == pesel)
                {
                    numer = i;
                    break;
                }
            if (numer >= 0) menu_customer(numer);
            else {
                cout << "Brak klienta o danym peselu" << endl;
                system("pause");
            }
            break;
        case 5:
            cout << "Podaj nr rejestracyjny "; cin >> nr;
            for (int i = 0; i < CarList.size(); ++i)
                if (CarList[i].numberplate == nr)
                {
                    numer = i;
                    isTruck = 0;
                    break;
                }
            for (int i = 0; i < TruckList.size(); ++i)
                if (TruckList[i].numberplate == nr)
                {
                    numer = i;
                    break;
                }
            if (numer >= 0) menu_vehicle(numer, isTruck);
            else {
                cout << "Brak pojazdu o danym nr rejestracyjnym" << endl;
                system("pause");
            }
            break;
        case 6:
            menu_show();
            break;
        case 0:
            break;
        }

    }
    ExportData();
}