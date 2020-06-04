#ifndef VEHICLE_RENTAL_H
#define VEHICLE_RENTAL_H
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "../Vehicle/Vehicle.hpp"
#include "../Customer/Customer.hpp"
#include "../MyStack/MyStack_impl.hpp"
#include "../VehicleRental/Enum.hpp"



class VehicleRental {
public:
    std::vector <Car> CarList;
    std::vector <Truck> TruckList;
    std::vector <Customer> CustomerList;
    MyStack <std::string> *Stack;

public:

    // VehicleRental(const VehicleRental&) {};
    // static VehicleRental& getSingleton()
    // {
    //     static VehicleRental singleton;
    //     return singleton;
    // }

    VehicleRental(){
        std::vector <Car> CarList = std::vector <Car>();
        std::vector <Truck> TruckList = std::vector <Truck>();
        std::vector <Customer> CustomerList = std::vector <Customer>();
        Stack = new MyStack <std::string>;
    };
    ~VehicleRental() {
        //delete CarList;
        //delete TruckList;
        //delete CustomerList;
        delete Stack;

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
    void Add(T instance);
    template <typename T>
    void Delete(T& instance);

    void ShowVehicleList(VehicleTypes type_v);
    void ShowCustomerList(CustomerTypes type_c);




template <typename T>
friend void ShowInfo(T& instance);

};
#endif