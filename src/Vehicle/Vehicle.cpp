#include "../Vehicle/Vehicle.hpp"

Vehicle::Vehicle(std::string nam, int d, std::string n, int c) {
	name = nam;
	dateProduction = d;
	numberplate = n;
	costOfRenting = c;
	condition = 100;
	isRent = false;
	isWork = true;
}

bool Vehicle::canRent() {
	if (isWork && !(isRent)) return true;
	return false;
}

void Vehicle::Rent() {
	if (canRent()) isRent = true;
}

void Vehicle::Return() {
	isRent = false;
	ReduceCondition();
}

void Vehicle::ReduceCondition() {
	if (canRent()) {
		condition -= 10;
		if (condition <= 0) isWork = false;
	}
}

void Vehicle::Repair() {
	if (!isWork) {
		condition = 100;
		isWork = true;
	}
}

Car::Car(std::string nam, int d, std::string n, int c, int s) {
	name = nam;
	dateProduction = d;
	numberplate = n;
	costOfRenting = c;
	numberOfSeats = s;
	condition = 100;
	isRent = false;
	isWork = true;
}

Truck::Truck(std::string nam, int d, std::string n, int c, int ca) {
	name = nam;
	dateProduction = d;
	numberplate = n;
	costOfRenting = c;
	capacity = ca;
	condition = 100;
	isRent = false;
	isWork = true;
}