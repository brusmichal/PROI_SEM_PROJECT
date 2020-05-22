#ifndef CAR_RENTAL_H
#define CAR_RENTAL_H
#include <vector>
#include "../Vehicle/Vehicle.hpp"
#include "../Customer/Customer.hpp"


template <typename T>

class CarRental{
    std::vector <Vehicle> VehicleList;
    std::vector <Customer> CustomerList;

public:
    CarRental(){
        VehicleList = new std::vector <Vehicle>();
        CustomerList = new std::vector <Customer>();
        
    }
    ~CarRental(){
        delete VehicleList;
        delete CustomerList;
    };

    void ReturnVehicleList(/*enum:all, free, taken"*/);
    void ReturnCustomerList(/*enum: all, withdebt */);
    void Rent(Vehicle& vehicle);
    void Payment(Vehicle& vehicle, Customer& customer);
    CarRental& Find(T& value);
    void Add(T instance);
    void Delete(T instance);




friend void Show();
    
};
#endif