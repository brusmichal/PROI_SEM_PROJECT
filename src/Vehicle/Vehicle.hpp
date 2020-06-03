#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

class Vehicle /*: protected VehicleRental <Vehicle>*/ {
public:
	std::string numberplate;
protected:
	std::string name;
	int dateProduction;
	int costOfRenting;
	int condition;
	bool isRent;
	bool isWork;

public:
	Vehicle(std::string, int, std::string, int);
	Vehicle(std::string, int, std::string, int, int, bool, bool);
	Vehicle();
	//	~Vehicle();
protected:
	bool canRent();
	void Rent();
	void Return();
	void ReduceCondition();
	void Repair();

	friend
		std::ostream& operator<< (std::ostream& os, Vehicle& vehi);

	friend class Customer;
	friend class VehicleRental;
};

class Car :public Vehicle {
	int numberOfSeats;

public:
	Car(std::string, int, std::string, int, int);
	Car(std::string, int, std::string, int, int, int, bool, bool);
	Car();
	//	~Car();

	friend class Customer;
	friend class VehicleRental;
};

class Truck :public Vehicle {
	int capacity;

public:
	Truck(std::string, int, std::string, int, int);
	Truck(std::string, int, std::string, int, int,  int, bool, bool);
	Truck();
	//	~Truck();

	friend class Customer;
	friend class VehicleRental;
};
#endif
