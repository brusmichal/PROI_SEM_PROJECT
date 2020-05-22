#ifndef CAR_RENTAL_H
#define CAR_RENTAL_H
#include <vector>
#include "../Vehicle/Vehicle.hpp"
#include "../Customer/Customer.hpp"


class CarRental{
    std::vector <Vehicle> VehicleList;
    std::vector <Customer> CustomerList;

public:



friend void Show();
    
};
#endif