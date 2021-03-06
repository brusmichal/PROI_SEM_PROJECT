#include "VehicleRental.hpp"

std::ifstream in;
std::ofstream out;

template <typename T>

void VehicleRental::Add(T instance) {};

template <>
void VehicleRental::Add <Truck>(Truck vehicle) {
    TruckList.push_back(vehicle);
    Stack.Push("Dodano ciezarowke " + vehicle.numberplate + " do listy.");
};

template <>
void VehicleRental::Add <Car>(Car vehicle) {
    CarList.push_back(vehicle);
    Stack.Push("Dodano samochod osobowy " + vehicle.numberplate + " do listy.");
};

template <>
void VehicleRental::Add <Customer>(Customer customer) {
    CustomerList.push_back(customer);
    Stack.Push("Dodano klienta " + std::to_string(customer.pesel) + " do listy.");
};

//-----------------------------------------------------------

template <typename T>

typename std::vector<T>::iterator VehicleRental::Find(const T& value) {
    return {};
};

template<>
std::vector<Car>::iterator VehicleRental::Find <Car>(const Car& vehicle) {

    std::vector<Car>::iterator position;
    auto it = std::find(CarList.begin(), CarList.end(), vehicle);

    if (it == CarList.end())
        throw "Vehicle not found";
    else
    {
        position = it;
        return position;
    }
};

template<>
std::vector<Truck>::iterator VehicleRental::Find <Truck>(const Truck& vehicle) {

    std::vector<Truck>::iterator position;
    auto it = std::find(TruckList.begin(), TruckList.end(), vehicle);

    if (it == TruckList.end())
        throw "Vehicle not found";
    else
    {
        position = it;
        return position;
    }
};

template<>
std::vector<Customer>::iterator VehicleRental::Find <Customer>(const Customer& customer) {
    std::vector<Customer>::iterator position;
    auto it = std::find(CustomerList.begin(), CustomerList.end(), customer);

    if (it == CustomerList.end())
        throw "Customer not found";
    else
    {
        position = it;
        return position;
    }
};


//------------------------------------------------------------

template <typename T>

void VehicleRental::Delete(T& instance) {};

template <>
void VehicleRental::Delete <Truck>(Truck& vehicle) {
    Stack.Push("Usunieto ciezarowke " + vehicle.numberplate + " z listy.");
    TruckList.erase(Find(vehicle));
    
};

template <>
void VehicleRental::Delete <Car>(Car& vehicle) {
    Stack.Push("Usunieto samoched osobowy " + vehicle.numberplate + " z listy.");
    CarList.erase(Find(vehicle));
};

template <>
void VehicleRental::Delete <Customer>(Customer& customer) {
    Stack.Push("Usunieto klienta " + std::to_string(customer.pesel) + " z listy.");
    CustomerList.erase(Find(customer));
};

//---------------------------------------------------------------
template <typename T>
void VehicleRental::Rent(T& vehicle, Customer& customer)
{
    std::cout << "Blad" << std::endl;
};

template<>
void VehicleRental::Rent<Car>(Car& vehicle, Customer& customer)
{
    try
    {
        if (vehicle.canRent()) {
            vehicle.Rent();
            customer.rent_vehicle(vehicle);
            Stack.Push("Klient " + std::to_string(customer.pesel) + " wypozyczy?? samochod osobowy " + vehicle.numberplate);
        }
        else {
            std::cout << "Nie mozna teraz wypozyczyc auta!" << std::endl;
            pause();
        }
    }
    catch (std::string exnum)
    {
        std::cout << "Wyjatek" << exnum << std::endl;
    }
};
template<>
void VehicleRental::Rent<Truck>(Truck& vehicle, Customer& customer)
{
    try
    {
        if (vehicle.canRent()) {
            if (customer.driving_licence_type == 'C') {
                vehicle.Rent();
                customer.rent_vehicle(vehicle);
                Stack.Push("Klient " + std::to_string(customer.pesel) + " wypozyczy?? ciezarowke " + vehicle.numberplate);
                std::cout << "Pojazd wypozyczony" << std::endl;
            }
            else
            {
                std::cout << "Zla kategoria prawajazdy" << std::endl;
                pause();
            }
        }
        else {
            std::cout << "Nie mozna teraz wypozyczyc auta!" << std::endl;
            pause();
        }
    }
    catch (std::string exnum)
    {
        std::cout << "Wyjatek" << exnum << std::endl;
    }
};

void VehicleRental::Payment(Customer& customer, int money) {
    try
    {
        customer.pay(money);
        Stack.Push("Klientowi naliczono " + std::to_string(money) + " z?? op??aty za wypozyczenie.");
    }
    catch (std::string exnum)
    {
        std::cout << "Wyjatek" << exnum << std::endl;
    }
}

void VehicleRental::Return(Customer& customer)
{
    try
    {
        bool isTruck = 1;
        for (int i = 0; i < CarList.size(); i++)
        {
            if (CarList[i].numberplate == customer.rented_vehicle.numberplate)
            {
                CarList[i].Return();
                isTruck = 0;
                break;
            }
        }
        if (isTruck) {
            for (int i = 0; i < TruckList.size(); i++)
            {
                if (TruckList[i].numberplate == customer.rented_vehicle.numberplate)
                {
                    TruckList[i].Return();
                    break;
                }
            }
        }
        customer.return_vehicle();
        Stack.Push("Klient " + std::to_string(customer.pesel) + " zwroci?? pojazd");
    }
    catch (std::string msg)
    {
        std::cout << msg;
    }
}

//-------------------------------------------------------------

void VehicleRental::LoadData() {
    std::string name, c, vehi;
    int b, cost, cond, f;
    bool isR, isW;
    long long pesel;
    char drive;
    in.open("Cars.txt");
    while (in >> name >> b >> c >> cost >> cond >> f >> isR >> isW) {
        Car autko(name, b, c, cost, cond, f, isR, isW);
        CarList.push_back(autko);
    }
    in.close();
    in.open("Trucks.txt");
    while (in >> name >> b >> c >> cost >> cond >> f >> isR >> isW) {
        Truck autko(name, b, c, cost, cond, f, isR, isW);
        TruckList.push_back(autko);
    }
    in.close();
    in.open("Customers.txt");
    bool isCar = 0;
    bool isTruck = 1;
    while (in >> name >> c >> pesel >> drive >> vehi >> b) {
        Car autko1;
        Truck autko2;
        if (vehi != "BS00000") {
            isTruck = 1;
            for (int j = 0; j < CarList.size(); ++j) {
                if (CarList[j].numberplate == vehi) {
                    autko1 = CarList[j];
                    isTruck = 0;
                }
            }
            if (isTruck) {
                for (int j = 0; j < TruckList.size(); ++j) {
                    if (TruckList[j].numberplate == vehi) autko2 = TruckList[j];
                }
            }
            isCar = (!isTruck);
        }
        Customer klient;
        if (isCar) {
            Customer kli(name, c, pesel, drive, autko1, b);
            klient = kli;
        }
        else {
            Customer kli(name, c, pesel, drive, autko2, b);
            klient = kli;
        }
        CustomerList.push_back(klient);
    }
    in.close();
}

void VehicleRental::ExportData() {
    out.open("Cars.txt");
    for (int i = 0; i < CarList.size(); ++i) {
        out << CarList[i].name << " " << CarList[i].dateProduction
            << " " << CarList[i].numberplate << " " << CarList[i].costOfRenting
            << " " << CarList[i].numberOfSeats << " " << CarList[i].condition << " "
            << CarList[i].isRent << " " << CarList[i].isWork << std::endl;
    }
    out.close();
    out.open("Trucks.txt");
    for (int i = 0; i < TruckList.size(); ++i) {
        out << TruckList[i].name << " " << TruckList[i].dateProduction
            << " " << TruckList[i].numberplate << " " << TruckList[i].costOfRenting
            << " " << TruckList[i].capacity << " " << TruckList[i].condition << " "
            << TruckList[i].isRent << " " << TruckList[i].isWork << std::endl;
    }
    out.close();
    out.open("Customers.txt");
    for (int i = 0; i < CustomerList.size(); ++i) {
        out << CustomerList[i].name << " " << CustomerList[i].surname << " "
            << CustomerList[i].pesel << " " << CustomerList[i].driving_licence_type << " "
            << CustomerList[i].rented_vehicle.numberplate << " " << CustomerList[i].debt << std::endl;
    }
    out.close();
}

template <typename T>
void ShowInfo(T instance) {};

template <>
void ShowInfo <Customer>(Customer customer) {
    std::cout << customer << std::endl;
};

template <>
void ShowInfo <Car>(Car vehicle) {
    std::cout << vehicle << std::endl;
};

template <>
void ShowInfo <Truck>(Truck vehicle) {
    std::cout << vehicle << std::endl;
};



void VehicleRental::ShowVehicleList(VehicleTypes type_v) {
    if (type_v == all_v) {
        for (int i = 0; i < CarList.size(); i++) {
            std::cout<<std::endl;
            ShowInfo(CarList[i]);
        }
        for (int i = 0; i < TruckList.size(); i++){
            std::cout<<std::endl;
            ShowInfo(TruckList[i]);
        };
    }

    else if (type_v == free_v) {
        for (int i = 0; i < CarList.size(); i++)
            if (!CarList[i].isRent){
                std::cout<<std::endl;
                ShowInfo(CarList[i]);
            }
        for (int i = 0; i < TruckList.size(); i++)
            if (!TruckList[i].isRent){
                std::cout<<std::endl;
                ShowInfo(TruckList[i]);
            }
    }
    
    else if (type_v == rented) {
        for (int i = 0; i < CarList.size(); i++)
            if (CarList[i].isRent){
                std::cout<<std::endl;
                ShowInfo(CarList[i]);
            }
        for (int i = 0; i < TruckList.size(); i++)
            if (TruckList[i].isRent){
                std::cout<<std::endl;
                ShowInfo(TruckList[i]);
            }

    }
    
    else if (type_v == car_t)
        for (int i = 0; i < CarList.size(); i++){
            std::cout<<std::endl;
            ShowInfo(CarList[i]);
        }
            
    else
        for (int i = 0; i < TruckList.size(); i++){
            std::cout<<std::endl;
            ShowInfo(TruckList[i]);
        }
}


void VehicleRental::ShowCustomerList(CustomerTypes type_c) {
    if (type_c == all_c)
        for (int i = 0; i < CustomerList.size(); i++){
            std::cout<<std::endl;
            ShowInfo(CustomerList[i]);
        }
    else
        for (int i = 0; i < CustomerList.size(); i++)
            if (CustomerList[i].debt > 0){
                std::cout<<std::endl;
                ShowInfo(CustomerList[i]);
            }
}

void VehicleRental :: ShowOperationsHistory(){
    Stack.Read();
    pause();
}
