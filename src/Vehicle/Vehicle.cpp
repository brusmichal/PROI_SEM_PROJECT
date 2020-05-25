#include "../Vehicle/Vehicle.hpp"

Vehicle::Vehicle(int d, std::string n, int c) {
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