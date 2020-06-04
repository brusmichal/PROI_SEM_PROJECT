#include "../Customer/Customer.hpp"

Customer::Customer(const std::string str1, const std::string str2, const long long pes, const char type, Vehicle car = Vehicle("", 0, "BS00000", 0), int deb = 0)
{
	name = str1;
	surname = str2;
	pesel = pes;
	driving_license_type = type;
	rented_vehicle = car;
	debt = deb;
}

Customer::Customer(const std::string str1, const std::string str2, const long long pes, const char type)
{
	name = str1;
	surname = str2;
	pesel = pes;
	driving_license_type = type;
	rented_vehicle = Vehicle("", 0, "BS00000", 0);
	debt = 0;
}



Customer::Customer() {
	name = "";
	surname = "";
	pesel = 0;
	driving_license_type = 'B';
	rented_vehicle = Vehicle();
	debt = 0;
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
	if (rented_vehicle.numberplate != "BS00000")
		rented_vehicle = Vehicle();
	else
		throw "Osoba nie posiada wypozyczonego pojazdu";
}

void Customer::pay(const int price)
{
	Customer::debt -= price;
}

void Customer::show_history()
{
	std::cout << "Historia wypożyczeń:" << std::endl;
	for (int i = 0; i < Customer::history.size(); ++i)
		std::cout << Customer::history[i]<<std::endl;
}

char Customer::show_driving_type()
{
	return driving_license_type;
}


bool Customer::operator==(const Customer& cust)
{
	return pesel == cust.pesel;
}


std::ostream& operator<< (std::ostream& os, Customer& klient)
{
	std::string zwroc = klient.name + " " + klient.surname + " Pesel: " + std::to_string(klient.pesel)
		+ " Zaleglosc: " + std::to_string(klient.debt) + " Wypozyczone: ";
	if (klient.rented_vehicle == Vehicle())
		return os << zwroc << " brak" << std::endl;
	else
		return os << zwroc << "Tak" << std::endl;
}