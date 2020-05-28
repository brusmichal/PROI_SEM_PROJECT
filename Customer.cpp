#include <iostream>
#include <cstdlib>
#include <string>
#include "../Customer/Customer.hpp"

Customer::Customer(const std::string str1, const std::string str2, const long long pes, const char type, Vehicle car= Vehicle("", 0, "", 0))
{
	name = str1;
	surname = str2;
	pesel = pes;
	driving_license_type = type;
	rented_vehicle = car;
}

void Customer::rent_vehicle(const Vehicle car)
{

	if (Customer::rented_vehicle.name == "")
	{
		rented_vehicle = car;
		debt += car.costOfRenting;
		history.push_back(Customer::rented_vehicle);
	}
	else
	{
		std::string error = "Pojazd już wypozyczony";
		throw error;
	}
}

void Customer::return_vehicle()
{
	if (rented_vehicle.name != "")
		rented_vehicle = Vehicle("", 0, "", 0);
	else
		throw "Osoba nie posiada wypozyczonego pojazdu";
}

void Customer::pay(const int price)
{
	Customer::debt -= price;
}

void Customer::show_history()
{
	std::cout << "Historia wypozyczen :" << std::endl;
	for (int i = 0; i < Customer::history.size(); ++i)
		cout << Customer::history[i]<<endl;
}

char Customer::show_driving_type()
{
	return driving_license_type;
}

std::ostream& operator<< (std::ostream& os, Customer& klient)
{
	return os << klient.name + " " + klient.surname + " Pesel: " + std::to_string(klient.pesel)
		+ " Zaleglosc: " + std::to_string(klient.debt)<<" Wypozyczone: "<<klient.rented_vehicle<<endl;
}