#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "../VehicleRental/VehicleRental.hpp"


class Customer : protected VehicleRental <Customer>{
	std::string name;
		std::string surname;
		long long pesel;
		char driving_license_type;
		Vehicle borrowed;
		std::vector<Vehicle> history;
		int arrear=0;
	
	public:
		Customer(const std::string, const std::string, const long long, const char); //Konstruktor
		void borrow(const Vehicle); //funkcja do wypo�yczania pojazdu
		void pay(const int); //funkcja op�aty
		void return_vehicle(); //funkcja do zwracania pojazdu
		void show_history();

	friend
		std::ostream& operator<< (std::ostream& os, Customer& cust); //operator wyswietlenia osoby

};
#endif