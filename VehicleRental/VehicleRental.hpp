#ifndef VEHICLE_RENTAL_H
#define VEHICLE_RENTAL_H
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "../Customer/Customer.hpp"

class VehicleRental {
    std::vector <Vehicle> VehicleList;
    std::vector <Customer> CustomerList;

public:

    void Menu();
    void LoadData();
    void ExportData();

    void Rent(Vehicle& vehicle, Customer& Customer);
    void Payment(Vehicle& vehicle, Customer& customer);

    //template <typename T>
    //std::vector<T>::iterator Find(const T& value);
    template <typename T>
    void Add(T& instance);
    template <typename T>
    void Delete(T& instance);

    // void ShowVehicleList(/*enum:all, free, taken"*/);
   // void ShowCustomerList(/*enum: all, withdebt */);
    template <typename T>
    friend void ShowInfo(T& instance);

};
#endif