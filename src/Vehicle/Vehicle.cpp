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

std::ostream& operator<< (std::ostream& os, Vehicle& vehi)
{
	std::string status;
	if (vehi.isRent) status = " ";
	else status = " nie ";
	return os << "Nazwa pojazdu " + vehi.name + " Numer rejestracyjny " + vehi.numberplate
		+ " Data produkcji " + std::to_string(vehi.dateProduction) + " Koszt wypozyczenia "
		+ std::to_string(vehi.costOfRenting) + " Pojazd sprawny w " + std::to_string(vehi.condition) + "% Pojazd" + status + "jest wypozyczony";
}

Car::Car(std::string nam, int d, std::string n, int c, int s) :Vehicle(nam, d, n, c) {
	numberOfSeats = s;
}

Truck::Truck(std::string nam, int d, std::string n, int c, int ca) : Vehicle(nam, d, n, c) {
	capacity = ca;
}