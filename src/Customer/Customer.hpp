#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <string>
#include "../Vehicle/Vehicle.hpp"


class Customer /*: protected VehicleRental*/{
	std::string name;
	std::string surname;
	long long pesel;
	char driving_license_type;
	Vehicle rented_vehicle;
	std::vector<Vehicle> history;
	int debt;
	
    public:
		Customer(const std::string, const std::string, const long long, const char, Vehicle, int); //Konstruktor
		Customer(const std::string, const std::string, const long long, const char);
		Customer();
		void rent_vehicle(const Vehicle); //funkcja do wypozyczania pojazdu
		void pay(const int); //funkcja oplaty
		void return_vehicle(); //funkcja do zwracania pojazdu
		void show_history();
		char show_driving_type(); //zwraca typ prawojazd

		bool operator==(const Customer& cust);

	friend
		std::ostream& operator<< (std::ostream& os, Customer& cust); //operator wyswietlenia osoby
    friend class Vehicle;
	friend class VehicleRental;
};
#endif