#ifndef VEHICLE_RENTAL_H
#define VEHICLE_RENTAL_H
#include <vector>
#include<iterator>
#include <algorithm>
#include "../Vehicle/Vehicle.hpp"
#include "../Customer/Customer.hpp"




class VehicleRental{
    std::vector <Vehicle> VehicleList;
    std::vector <Customer> CustomerList;

public:
    VehicleRental(){
        VehicleList = new std::vector <Vehicle>();
        CustomerList = new std::vector <Customer>();
        
    }
    ~VehicleRental(){
        delete VehicleList;
        delete CustomerList;
    };

    void Menu();
    void LoadData();
    void ExportData();

    void Rent(Vehicle& vehicle, Customer& Customer);
    void Payment(Vehicle& vehicle, Customer& customer);

    template <typename T>
    typename std::vector<T>::iterator Find(const T& value);
    template <typename T>
    void Add(T& instance);
    template <typename T>
    void Delete(T& instance);

    // void ShowVehicleList(/*enum:all, free, taken"*/);
    // void ShowCustomerList(/*enum: all, withdebt */);





friend void ShowInfo(T& instance);
    
};
#endif