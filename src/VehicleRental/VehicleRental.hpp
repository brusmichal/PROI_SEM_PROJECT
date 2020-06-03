#ifndef VEHICLE_RENTAL_H
#define VEHICLE_RENTAL_H
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "../Vehicle/Vehicle.hpp"
#include "../Customer/Customer.hpp"


class VehicleRental {
public:
    std::vector <Car> CarList;
    std::vector <Truck> TruckList;
    std::vector <Customer> CustomerList;

public:
    VehicleRental() {
        std::vector <Car>* CarList = new std::vector <Car>();
        std::vector <Truck>* TruckList = new std::vector <Truck>();
        std::vector <Customer>* CustomerList = new std::vector <Customer>();

    }
    ~VehicleRental() {
        delete CarList;
        delete TruckList;
        delete CustomerList;
    };

    void Menu();
    void menu_customer(int);
    void menu_vehicle(int, bool);
    void LoadData();
    void ExportData();

    void Rent(Vehicle& vehicle, Customer& Customer);
    void Payment(Customer& customer, int money);
    void Return(Customer& customer);

    template <typename T>
    typename std::vector<T>::iterator Find(const T& value);
    template <typename T>
    void Add(T& instance);
    template <typename T>
    void Delete(T& instance);

    // void ShowVehicleList(/*enum:all, free, taken, car, truck"*/);
    // void ShowCustomerList(/*enum: all, withdebt */);




//template <typename T>
//friend void ShowInfo(T& instance);

};
#endif