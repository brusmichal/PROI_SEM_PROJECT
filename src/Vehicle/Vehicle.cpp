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

Vehicle::Vehicle(std::string nam, int d, std::string n, int cos, int con, bool isR, bool isW) {
	name = nam;
	dateProduction = d;
	numberplate = n;
	costOfRenting = cos;
	condition = con;
	isRent = isR;
	isWork = isW;
}

Vehicle::Vehicle() {
	std::string nazwa = "";
	std::string reje = "BS00000";
	name = nazwa;
	dateProduction = 0;
	numberplate = reje;
	costOfRenting = 0;
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

bool Vehicle::operator ==(const Vehicle& vehi1) {
	return vehi1.numberplate == numberplate;
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

Car::Car(std::string nam, int d, std::string n, int c, int s, int con, bool isR, bool isW) : Vehicle(nam, d, n, c, con, isR, isW) {
	numberOfSeats = s;
}

Car::Car() : Vehicle() {
	numberOfSeats = 0;
}

std::ostream& operator<< (std::ostream& os, Car& vehi)
{
	std::string status;
	if (vehi.isRent) status = " ";
	else status = " nie ";
	return os << "Nazwa pojazdu " + vehi.name + " Numer rejestracyjny " + vehi.numberplate
		+ " Data produkcji " + std::to_string(vehi.dateProduction) + " Koszt wypozyczenia "
		+ std::to_string(vehi.costOfRenting) + " Ilosc siedzen: "+ std::to_string(vehi.numberOfSeats)
		+ " Pojazd sprawny w " + std::to_string(vehi.condition) + "% Pojazd" + status + "jest wypozyczony";
}


Truck::Truck(std::string nam, int d, std::string n, int c, int ca) : Vehicle(nam, d, n, c) {
	capacity = ca;
}

Truck::Truck(std::string nam, int d, std::string n, int c, int ca, int con, bool isR, bool isW) : Vehicle(nam, d, n, c, con, isR, isW) {
	capacity = ca;
}

Truck::Truck() : Vehicle() {
	capacity = 0;
}
std::ostream& operator<< (std::ostream& os, Truck& vehi)
{
	std::string status;
	if (vehi.isRent) status = " ";
	else status = " nie ";
	return os << "Nazwa pojazdu " + vehi.name + " Numer rejestracyjny " + vehi.numberplate
		+ " Data produkcji " + std::to_string(vehi.dateProduction) + " Koszt wypozyczenia "
		+ std::to_string(vehi.costOfRenting) + " Pojemnosc bagaznika: " + std::to_string(vehi.capacity)
		+ " Pojazd sprawny w " + std::to_string(vehi.condition) + "% Pojazd" + status + "jest wypozyczony";
}
