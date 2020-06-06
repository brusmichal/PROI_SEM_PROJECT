#include "../VehicleRental/VehicleRental.hpp"


using std::cout;
using std::cin;
using std::endl;

Car enter_car()
{
    std::string name, drugi;
    int jeden, dwa, trzy;

    cout << "Podaj nazwe "; cin >> name;
    cout << "Podaj rok produkcji "; jeden=enter_number();
    cout << "Podaj nr rejestracyjny "; cin >> drugi;
    cout << "Podaj koszt wypozyczenia "; dwa=enter_number();
    cout << "Podaj liczbe siedzeń "; trzy = enter_number();
    Car autko(name, jeden, drugi, dwa, trzy);
    return autko;
}

Truck enter_truck()
{
    std::string name, drugi;
    int jeden, dwa, trzy;

    cout << "Podaj nazwe "; cin >> name;
    cout << "Podaj rok produkcji "; jeden = enter_number();
    cout << "Podaj nr rejestracyjny "; cin >> drugi;
    cout << "Podaj koszt wypozyczenia "; dwa = enter_number();
    cout << "Podaj pojemnosc bagznika "; trzy = enter_number();
    Truck autko(name, jeden, drugi, dwa, trzy);
    return autko;
}

Customer enter_customer()
{
    std::string name, drugi;
    long long jeden;
    char typ;

    cout << "Podaj imie "; cin >> name;
    cout << "Podaj nazwisko "; cin >> drugi;
    cout << "Podaj pesel "; jeden = enter_number();
    cout << "Podaj typ prowojazd "; typ=enter_char();
    Customer ktos(name, drugi, jeden, typ);
    return ktos;
}
/*------------------------------------------------------------------------------------------------*/
void VehicleRental::menu_customer(int numer)
{
    long long pesel;
    int ile, wybor;
    bool ifDelete = 0;

    int x = 8;
    while (x > 0 && x < 9) {
        clear();
        cout << CustomerList[numer] << endl;
        cout << "Co chcesz zrobic: \n1.Wypozycz pojazd  \n2.Oplac \n3.Zwroc pojazd\n4.Usun klienta\n0.Wroc\n";
        cout << "Wybor: ";
        x = enter_number();
        clear();
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
            cout << "Ktory pojazd wypozyczyc? "; wybor = enter_number();
            if (wybor < CarList.size() + TruckList.size() && wybor >= 0) {
                if (wybor > end) Rent(TruckList[wybor - (end + 1)], CustomerList[numer]);
                else Rent(CarList[wybor], CustomerList[numer]);
            }
            else {
                cout << "Wpisano numer spoza listy! Prosze takich rzeczy nie robic!" << endl;
                pause();
            }
            break;
        case 2:
            cout << CustomerList[numer] << endl;
            cout << "Oplac \nPodaj kwote "; ile = enter_number();
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
            a = enter_number();
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
        pause();
    }
}
/*-----------------------------------------------------------------------------------------*/
void VehicleRental::menu_vehicle(int numer, bool isTruck)
{
    int ile, wybor, a;
    bool ifDelete = 0;

    int x = 8;
    while (x > 0 && x < 9) {
        clear();
        if (isTruck) cout << TruckList[numer] << endl;
        else cout << CarList[numer] << endl;
        cout << "Co chcesz zrobic: \n1.Wypozycz pojazd  \n2.Napraw \n3.Usun z wypozyczalni \n0.Wroc\n";
        cout << "Wybor: ";
        x = enter_number();
        clear();
        switch (x)
        {
        case 1:
            cout << "Osoby mogace wypozyczyc" << endl;
            for (int i = 0; i < CustomerList.size(); ++i)
                if (CustomerList[i].rented_vehicle.numberplate=="BS00000") cout << i << " " << CustomerList[i] << endl;
            cout << "Kto chce wypozyczyc wypozyczyc? "; wybor = enter_number();
            if (isTruck) Rent(TruckList[numer], CustomerList[wybor]);
            else Rent(CarList[numer], CustomerList[wybor]);
            pause();
            break;
        case 2:
            if (isTruck) TruckList[numer].Repair();
            else CarList[numer].Repair();
            pause();
            break;
        case 3:
            bool isRent;
            if (isTruck) isRent = TruckList[numer].isRent;
            else isRent = CarList[numer].isRent;
            if (isRent) {
                cout << "Nie mozna usunac wypozyczonego pojazdu!" << endl;
                pause();
            }
            else {
                cout << "Czy na pewno chcesz usunac pojazd?" << endl;
                cout << "0 - NIE" << endl;
                cout << "1 - TAK" << endl;
                a = enter_number();
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
        pause();
    }
    if (ifDelete && !isTruck) {
        Delete(CarList[numer]);
        cout << "Pojazd zostal usuniety" << endl;
        pause();
    }
}
/*------------------------------------------------------------------------------------------------*/
void VehicleRental::menu_show()
{

    int x = 1;
    while (x > 0 && x < 3) {
        clear();
        cout << "Co pokazac: \n1.Lista klientow  \n2.Lista pojazdow \n0.Wroc\n";
        cout << "Wybor: ";
        x = enter_number();
        switch (x)
        {
        case 1:
            int a;
            CustomerTypes type_c;
            cout << "Klienci: \n1.Wszyscy  \n2.Zadluzeni \n0.Wroc\n";
            cout << "Wybor: ";
            a = enter_number();
            clear();
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
            pause();
            break;
        case 2:
            int b;
            VehicleTypes type_v;
            cout << "Pojazdy: \n1.Wszystkie  \n2.Wolne \n3.Wypozyczone \n4.Samochody Osobowe \n5.Samochody Ciezarowe \n";
            cout << "Wybor: ";
            b = enter_number();
            clear();
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
            pause();
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

    int x = 8;
    LoadData();
    pause();
    while (x != 0) {
        clear();
        int numer = -1;
        cout<<endl;
        cout << "Wypozyczalnia pojazdow.\n" "Witaj co chcesz zrobic:\n\n1.Dodaj pojazd osobowy \n2.Dodaj pojazd ciezarowy \n3.Dodaj klienta\n4.Panel klienta\n5.Panel samochodu\n6.Pokaz\n7.Historia Operacji\n0.wyjdz\n";
        cout<<endl;
        cout << "Wybor: ";
        x = enter_number();
        clear();
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
            cout << "Podaj pesel "; pesel = enter_number();
            for (int i = 0; i < CustomerList.size(); ++i)
                if (CustomerList[i].pesel == pesel)
                {
                    numer = i;
                    break;
                }
            if (numer >= 0) menu_customer(numer);
            else {
                cout << "Brak klienta o danym peselu" << endl;
                pause();
            }
            break;
        case 5:
            cout << "Podaj nr rejestracyjny "; nr = enter_number();
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
                pause();
            }
            break;
        case 6:
            menu_show();
            break;
        case 7:
            ShowOperationsHistory();
            break;
        case 0:
            break;
        }
    
    
    cout<<endl;
    }
    
    ExportData();
}