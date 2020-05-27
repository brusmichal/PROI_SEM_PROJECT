#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include "../VehicleRental/VehicleRental.hpp"
#include <string>


class Vehicle : protected VehicleRental <Vehicle> {
protected:
	std::string name;
	int dateProduction;
	std::string numberplate;
	int costOfRenting;
	int condition;
	bool isRent;
	bool isWork;

public:
	Vehicle(std::string, int, std::string, int);
	//	~Vehicle();

	bool canRent();
	void Rent();
	void Return();
	void ReduceCondition();
	void Repair();

	friend
		std::ostream& operator<< (std::ostream& os, Vehicle& vehi);

	//	friend class Customer;
};

class Car :protected Vehicle {
	int numberOfSeats;

	Car(std::string, int, std::string, int, int);
	//	~Car();
};

class Truck :protected Vehicle {
	int capacity;

	Truck(std::string, int, std::string, int, int);
	//	~Truck();
};
#endif
