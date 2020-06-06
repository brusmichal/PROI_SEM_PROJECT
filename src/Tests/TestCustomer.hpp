#ifndef TEST_CUSTOMER_H
#define TEST_CUSTOMER_H

#include "../Customer/Customer.hpp"
#include <assert.h>

#define REQUIRE(exp) assert(exp)

using std::cout;
using std::endl;

void TestKonstruktorCustomer() {
	Customer ktos;
	REQUIRE(ktos.name == "");
	cout << "Dobrze zdefiniowana zmienna name" << endl;
	REQUIRE(ktos.surname == "");
	cout << "Dobrze zdefiniowana zmienna surname" << endl;
	REQUIRE(ktos.pesel == 0);
	cout << "Dobrze zdefiniowana zmienna pesel" << endl;
	REQUIRE(ktos.driving_licence_type == 'B');
	cout << "Dobrze zdefiniowana zmienna driving_licence_type" << endl;
	REQUIRE(ktos.debt == 0);
	cout << "Dobrze zdefiniowana zmienna debt" << endl;
	REQUIRE(ktos.rented_vehicle.numberplate == "BS00000");
	cout << "Dobrze zdefiniowana zmienna rented_vehicle " << endl;

	Customer ktos1("Jan", "Kowalski", 00000000000, 'C');
	REQUIRE(ktos1.name == "Jan");
	cout << "Dobrze zdefiniowana zmienna name" << endl;
	REQUIRE(ktos1.surname == "Kowalski");
	cout << "Dobrze zdefiniowana zmienna surname" << endl;
	REQUIRE(ktos1.pesel == 00000000000);
	cout << "Dobrze zdefiniowana zmienna pesel" << endl;
	REQUIRE(ktos1.driving_licence_type == 'C');
	cout << "Dobrze zdefiniowana zmienna driving_licence_type" << endl;
	REQUIRE(ktos1.debt == 0);
	cout << "Dobrze zdefiniowana zmienna debt" << endl;
	REQUIRE(ktos1.rented_vehicle.numberplate == "BS00000");
	cout << "Dobrze zdefiniowana zmienna rented_vehicle " << endl;

	Car autko("Maluch", 1970, "BS12345", 200, 5);
	Customer ktos2("Agata", "Kowalska", 00000000012, 'B', autko, 100);
	REQUIRE(ktos2.name == "Agata");
	cout << "Dobrze zdefiniowana zmienna name" << endl;
	REQUIRE(ktos2.surname == "Kowalska");
	cout << "Dobrze zdefiniowana zmienna surname" << endl;
	REQUIRE(ktos2.pesel == 00000000012);
	cout << "Dobrze zdefiniowana zmienna pesel" << endl;
	REQUIRE(ktos2.driving_licence_type == 'B');
	cout << "Dobrze zdefiniowana zmienna driving_licence_type" << endl;
	REQUIRE(ktos2.debt == 100);
	cout << "Dobrze zdefiniowana zmienna debt" << endl;
	REQUIRE(ktos2.rented_vehicle.numberplate == "BS12345");
	cout << "Dobrze zdefiniowana zmienna rented_vehicle " << endl;
	cout << "Konstruktor DZIALA " << endl;
}



void Testrent_vehicle() {
	bool isthrow = 0;
	Car autko("Fiat", 1959, "BS54321", 1000, 5);
	Customer ktos("Agata", "Kowalska", 00000000012, 'B');

	ktos.rent_vehicle(autko);
	REQUIRE(ktos.debt == 1000);
	REQUIRE(ktos.rented_vehicle.numberplate == "BS54321");
	Car autko2("", 0, "BS00000", 0, 0);
	Customer ktos2("Agata", "Kowalska", 00000000012, 'B', autko2, 100);

	ktos2.rent_vehicle(autko);
	REQUIRE(ktos2.debt == 1100);
	REQUIRE(ktos2.rented_vehicle.numberplate == "BS54321");
	Car autko3("Opel", 2019, "BS11111", 1000, 5);
	try
	{
		ktos2.rent_vehicle(autko3);
	}
	catch (...)
	{
		isthrow = 1;
	}
	REQUIRE(isthrow);
	cout << "Metoda rent_vehicle DZIALA " << endl;
}

void Testreturn_vehicle() {
	bool isthrow = 0;
	Car autko("Fiat", 1959, "BS54321", 1000, 5);
	Customer ktos2("Agata", "Kowalska", 00000000012, 'B', autko, 100);
	Customer ktos("Agata", "Kowalska", 00000000012, 'B');
	ktos2.return_vehicle();
	REQUIRE(ktos2.debt == 100);
	REQUIRE(ktos2.rented_vehicle.numberplate == "BS00000");
	try
	{
		ktos.return_vehicle();
	}
	catch (...)
	{
		isthrow = 1;
	}
	REQUIRE(isthrow);
	cout << "Metoda return_vehicle DZIALA " << endl;
}

void Testpay() {
	Car autko("Fiat", 1959, "BS54321", 1000, 5);
	Customer ktos2("Agata", "Kowalska", 00000000012, 'B', autko, 1000);
	ktos2.pay(400);
	REQUIRE(ktos2.debt == 600);
	cout << "Metoda pay DZIALA " << endl;
}

void Testshow_driving_type() {
	Customer ktos1("Agata", "Kowalska", 00000000012, 'B');
	Customer ktos2("Agata", "Nowak", 12000000012, 'C');
	REQUIRE(ktos1.show_driving_type() == 'B');
	REQUIRE(ktos2.show_driving_type() == 'C');
	cout << "Metoda show_driving_type DZIALA " << endl;
}

void TestOperatorComparison() {
	Car autko("Maluch", 1970, "BS12345", 200, 5);
	Customer ktos2("Agata", "Kowalska", 00000000012, 'B', autko, 100);
	Customer ktos1 = ktos2;
	REQUIRE(ktos1 == ktos2);
	std::cout << "Operator== dla tych samych DZIALA" << std::endl;
	Customer ktos3("Agata", "Kowalska", 00000000012, 'B', autko, 100);
	Customer ktos4("Agata", "Kowalska", 12300000012, 'C');
	REQUIRE(!(ktos3 == ktos4));
	std::cout << "Operator== dla tych roznych DZIALA" << std::endl;
}


void TestCustomer() {
	TestKonstruktorCustomer();
	Testrent_vehicle();
	Testreturn_vehicle();
	Testpay();
	Testshow_driving_type();
	TestOperatorComparison();
}
#endif