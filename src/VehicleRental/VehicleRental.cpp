#include "VehicleRental.hpp"

template <typename T>

void VehicleRental::Add(T& instance){};

template <>
void VehicleRental::Add <Vehicle> (Vehicle& vehicle){
    VehicleList.push_back(vehicle);
};

template <>
void VehicleRental :: Add <Customer> (Customer& customer){
    CustomerList.push_back(customer);
};

//-----------------------------------------------------------

template <typename T>

void VehicleRental :: Delete(T& instance){};

template <>
void VehicleRental :: Delete <Vehicle>(Vehicle& vehicle){
    VehicleList.erase(Find(vehicle));
};
template <>
void VehicleRental :: Delete <Customer>(Customer& customer){
    CustomerList.erase(Find(customer));
};

//------------------------------------------------------------

template <typename T>

typename std::vector<T>::iterator VehicleRental  :: Find <T>(const T& value){};

template<>
std::vector<Vehicle>::iterator VehicleRental :: Find <Vehicle>(const Vehicle& vehicle){

    std::vector<Vehicle>::iterator position;
    auto it = std::find(VehicleList.begin(), VehicleList.end(), vehicle);

    if (it == VehicleList.end())
        throw "Vehicle not found";
    else
    {
        position = it;
        return position;
    }
};

template<>
std::vector<Customer>::iterator VehicleRental :: Find <Customer>(const Customer& customer){

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

//---------------------------------------------------------------
