#ifndef VEHICLE_H
#define VEHICLE_H
#include "../VehicleRental/VehicleRental.hpp"
#include <string>


class Vehicle : protected VehicleRental <Vehicle> {
	int dateProduction;
	string numberplate;
	int costOfRenting;
	int condition;
	bool isRent;
	bool isWork;

	Vehicle(int, string, int);
	~Vehicle();

	bool canRent();
	void Rent();
	void Return();
	void ReduceCondition();
	void Repair();
};
#endif
