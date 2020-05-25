#include <iostream>
#include <cstdlib>
#include <string>
#include "../Customer/Customer.hpp"

Customer::Customer(const string str1, const string str2, const long long pes, const char type)
{
	Customer::name = str1;
	Customer::surname = str2;
	Customer::pesel = pes;
	Customer::driving_license_type = type;
}

void Customer::borrow(const Vehicle car)
{

	if (Customer::borrowed.name == "")
	{
		Customer::borrowed = car;
		Customer::arrear += car.price;
		Customer::history.push_back(Customer::borrowed);
	}
	else
	{
		std::string error = "Pojazd ju\276 wypo\276yczony";
		throw error;
	}
}

void Customer::return_vehicle()
{

	Customer::borrowed = {};
}

void Customer::pay(const int price)
{
	Customer::arrear -= price;
}

void Customer::show_history()
{
	cout << "Historia wypo\276ycze\344:" << endl;
	//for (int i = 0; i < Customer::history.size(); ++i)
		//cout << Customer::history[i]<<endl;
}

std::ostream& operator<< (ostream& os, Customer& klient)
{
	return os << klient.name + " " + klient.surname + " Pesel: " + std::to_string(klient.pesel)
		+ " Zaleglosc: " + std::to_string(klient.arrear)<<" Wypo\276yczone: "<<klient.borrowed.name<<endl;
}