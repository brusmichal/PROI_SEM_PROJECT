#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Customer
{
		string name;
		string surname;
		long long pesel;
		char driving_license_type;
		Vehicle borrowed;
		vector<Vehicle> history;
		int arrear=0;
	
	public:
		Customer(const string, const string, const long long, const char); //Konstruktor
		void borrow(const Vehicle); //funkcja do wypo¿yczania pojazdu
		void pay(const int); //funkcja op³aty
		void return_vehicle(); //funkcja do zwracania pojazdu
		void show_history();

	friend
		ostream& operator<< (ostream& os, Customer& cust); //operator wyswietlenia osoby

};