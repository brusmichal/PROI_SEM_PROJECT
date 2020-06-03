#include "VehicleRental.hpp"

std::ifstream in;
std::ofstream out;

template <typename T>

void VehicleRental::Add(T instance){};

template <>
void VehicleRental::Add <Truck> (Truck vehicle){
    TruckList.push_back(vehicle);
};

template <>
void VehicleRental::Add <Car>(Car vehicle) {
    CarList.push_back(vehicle);
};

template <>
void VehicleRental :: Add <Customer> (Customer customer){
    CustomerList.push_back(customer);
};

//-----------------------------------------------------------

//template <typename T>
//
//typename std::vector<T>::iterator VehicleRental::Find <T>(const T& value) {};
//
//template<>
//std::vector<Car>::iterator VehicleRental::Find <Car>(const Car& vehicle) {
//
//    std::vector<Car>::iterator position;
//    auto it = std::find(CarList.begin(), CarList.end(), vehicle);
//
//    if (it == CarList.end())
//        throw "Vehicle not found";
//    else
//    {
//        position = it;
//        return position;
//    }
//};
//
//template<>
//std::vector<Truck>::iterator VehicleRental::Find <Truck>(const Truck& vehicle) {
//
//    std::vector<Truck>::iterator position;
//    auto it = std::find(TruckList.begin(), TruckList.end(), vehicle);
//
//    if (it == TruckList.end())
//        throw "Vehicle not found";
//    else
//    {
//        position = it;
//        return position;
//    }
//};
//
//template<>
//std::vector<Customer>::iterator VehicleRental::Find <Customer>(const Customer& customer) {
//
//    std::vector<Customer>::iterator position;
//    auto it = std::find(CustomerList.begin(), CustomerList.end(), customer);
//
//    if (it == CustomerList.end())
//        throw "Customer not found";
//    else
//    {
//        position = it;
//        return position;
//    }
//};

//------------------------------------------------------------

//template <typename T>
//
//void VehicleRental :: Delete(T& instance){};
//
//template <>
//void VehicleRental :: Delete <Truck>(Truck& vehicle){
//    TruckList.erase(Find(vehicle));
//};
//
//template <>
//void VehicleRental::Delete <Car>(Car& vehicle) {
//    CarList.erase(Find(vehicle));
//};
//
//template <>
//void VehicleRental :: Delete <Customer>(Customer& customer){
//    CustomerList.erase(Find(customer));
//};

//---------------------------------------------------------------
void VehicleRental::Rent(Vehicle& vehicle, Customer& Customer)
{
    try
    {
        vehicle.Rent();
        vehicle.ReduceCondition();
        Customer.rent_vehicle(vehicle);
    }
    catch (std::string exnum)
    {
        std::cout << "Wyjtek" << exnum << std::endl;
    }
}

void VehicleRental::Payment(Customer& customer, int money) {
    try
    {
        customer.pay(money);
    }
    catch (std::string exnum)
    {
        std::cout << "Wyjątek" << exnum << std::endl;
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
    Car autko1;
    Truck autko2;
    bool isCar = 0;
    bool isTruck = 1;
    while (in >> name >> c >> pesel >> drive >> vehi >> b) {
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
            << CustomerList[i].pesel << " " << CustomerList[i].driving_license_type << " " 
            << CustomerList[i].rented_vehicle.numberplate << " " << CustomerList[i].debt << std::endl;
    }
    out.close();
}