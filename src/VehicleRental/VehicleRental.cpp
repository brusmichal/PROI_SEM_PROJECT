#include "VehicleRental.hpp"

template <typename T>

void VehicleRental <T> ::Add(T& instance) {};

void VehicleRental <Vehicle> ::Add(Vehicle& vehicle) {
    VehicleList.push_back(vehicle);
};

void VehicleRental <Customer> ::Add(Customer& customer) {
    CustomerList.push_back(customer);
};

//-----------------------------------------------------------

template <typename T>

void VehicleRental <T> ::Delete(T& instance) {};

void VehicleRental <Vehicle> ::Delete(Vehicle& vehicle) {
    VehicleList.erase(Find(vehicle));
};

void VehicleRental <Customer> ::Delete(Customer& customer) {
    CustomerList.erase(Find(customer));
};

//------------------------------------------------------------

template <typename T>

typename std::vector<T>::iterator VehicleRental <T> ::Find(const T& value) {};

std::vector<Vehicle>::iterator VehicleRental <Vehicle> ::Find(const Vehicle& vehicle) {

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

std::vector<Customer>::iterator VehicleRental <Customer> ::Find(const Customer& customer) {

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
