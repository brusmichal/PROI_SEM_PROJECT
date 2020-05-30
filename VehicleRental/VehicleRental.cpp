#include "VehicleRental.hpp"


std::ifstream in;
std::ofstream out;


template <typename T>

void VehicleRental::Add(T& instance) {};

template <>
void VehicleRental::Add<Vehicle>(Vehicle& vehicle) {
    VehicleList.push_back(vehicle);
}

template <>
void VehicleRental::Add<Customer>(Customer& customer) {
    CustomerList.push_back(customer);
}

//-----------------------------------------------------------
/*
template <typename T>

void VehicleRental :: Delete(T& instance){}

template <>
void VehicleRental :: Delete<Vehicle> (Vehicle& vehicle){
    VehicleList.erase(Find(vehicle));
}
template <>
void VehicleRental :: Delete<Customer> (Customer& customer){
    CustomerList.erase(Find(customer));
}

//----------------------------------------------------------

//template <typename T>
//typename std::vector<T>::iterator VehicleRental  :: Find (const T& value){}

//template <>
std::vector<Vehicle>::iterator VehicleRental::Find(const Vehicle& vehicle) {

    std::vector<Vehicle>::iterator position;
    auto it = std::find(VehicleList.begin(), VehicleList.end(), vehicle);

    if (it != VehicleList.end())
        throw "Vehicle not found";
    else
    {
        position = it;
        return position;
    }
}
//template<>
std::vector<Customer>::iterator VehicleRental::Find (const Customer& customer) {

    std::vector<Customer>::iterator position;
    auto it = std::find(CustomerList.begin(), CustomerList.end(), customer);

    if (it == CustomerList.end())
        throw "Customer not found";
    else
    {
        position = it;
        return position;
    }
}
*/
//---------------------------------------------------------------    
void VehicleRental::Rent(Vehicle& vehicle, Customer& Customer)
{
    try
    {
        Customer.rent_vehicle(vehicle);
        vehicle.Rent();
        vehicle.ReduceCondition();
    }
    catch (std::string exnum)
    {
        std::cout << "Wyj¹tek" << exnum << std::endl;
    }
}

void VehicleRental::LoadData() {
    std::string a, c, vehi;
    int b, d, e;
    bool f, g;
    long long pesel;
    char drive;
    in.open("Vehicles.txt");
    while (in >> a >> b >> c >> d >> e >> f >> g) {
        Vehicle autko(a, b, c, d, e, f, g);
        VehicleList.push_back(autko);
    }
    in.close();
    in.open("Customers.txt");
    while (in >> a >> c >> pesel >> drive >> vehi >> b) {
        Vehicle autko;
        if (vehi != "BS00000") {
            for (int i = 0; i < VehicleList.size(); ++i) {
                if (VehicleList[i].numberplate == vehi) autko = VehicleList[i];
            }
        }
        Customer klient(a, c, pesel, drive, autko, b);
        CustomerList.push_back(klient);
    }
    in.close();
}

void VehicleRental::ExportData() {
    out.open("Vehicles.txt");
    for (int i = 0; i < VehicleList.size(); ++i) {
        out << VehicleList[i].name << " " << VehicleList[i].dateProduction
            << " " << VehicleList[i].numberplate << " " << VehicleList[i].costOfRenting
            << " " << VehicleList[i].condition << " " << VehicleList[i].isRent << " "
            << VehicleList[i].isWork << std::endl;
    }
    out.close();
    out.open("Customers.txt");
    for (int i = 0; i < CustomerList.size(); ++i) {
        out << CustomerList[i].name << " " << CustomerList[i].surname << " "
            << CustomerList[i].pesel << " " << CustomerList[i].rented_vehicle.numberplate
            << " " << CustomerList[i].debt << std::endl;
    }
    out.close();
}

