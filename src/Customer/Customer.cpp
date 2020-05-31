#include <iostream>
#include <cstdlib>
#include <string>
#include "../Customer/Customer.hpp"

Customer::Customer(const std::string str1, const std::string str2, const long long pes, const char type, Vehicle car= Vehicle("", 0, "BS00000", 0), int deb=0)
{
	name = str1;
	surname = str2;
	pesel = pes;
	driving_license_type = type;
	rented_vehicle = car;
	debt = deb;
}


void Customer::rent_vehicle(const Vehicle car)
{

	if (Customer::rented_vehicle.name == "")
	{
		Customer::rented_vehicle = car;
		Customer::debt += car.costOfRenting;
		Customer::history.push_back(Customer::rented_vehicle);
	}
	else
	{
		std::string error = "Pojazd już wypożyczony";
		throw error;
	}
}

void Customer::return_vehicle()
{

	Customer::rented_vehicle = {};
}

void Customer::pay(const int price)
{
	Customer::debt -= price;
}

void Customer::show_history()
{
	std::cout << "Historia wypożyczeń:" << std::endl;
	//for (int i = 0; i < Customer::history.size(); ++i)
		//cout << Customer::history[i]<<endl;
}

std::ostream& operator<< (std::ostream& os, Customer& klient)
{
	return os << klient.name + " " + klient.surname + " Pesel: " + std::to_string(klient.pesel)
		+ " Zaleglosc: " + std::to_string(klient.debt)<<" Wypo\276yczone: "<<klient.borrowed.name<<endl;
}