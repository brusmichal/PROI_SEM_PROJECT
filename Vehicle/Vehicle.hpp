#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>


class Vehicle : protected VehicleRental{
	std::string name;
	int dateProduction;
	std::string numberplate;
	int costOfRenting;
	int condition;
	bool isRent;
	bool isWork;

	Vehicle(std::string, int, std::string, int);
	~Vehicle();

	bool canRent();
	void Rent();
	void Return();
	void ReduceCondition();
	void Repair();

	friend class Customer;
};
#endif
