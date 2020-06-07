#ifndef TEST_VEHICLE_H
#define TEST_VEHICLE_H

#include "../Vehicle/Vehicle.hpp"
#include <assert.h>

#define REQUIRE(exp) assert(exp)

void TestKonstruktorCar() {
	Car autko;
	REQUIRE(autko.name == "");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko.numberplate == "BS00000");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko.dateProduction == 0);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko.costOfRenting == 0);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko.condition == 100);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko.numberOfSeats == 0);
	std::cout << "Dobrze zdefiniowana zmienna numberOfSeats" << std::endl;
	REQUIRE(!autko.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(autko.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;

	Car autko1("Maluch", 1970, "BS12345", 200, 5);
	REQUIRE(autko1.name == "Maluch");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko1.numberplate == "BS12345");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko1.dateProduction == 1970);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko1.costOfRenting == 200);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko1.condition == 100);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko1.numberOfSeats == 5);
	std::cout << "Dobrze zdefiniowana zmienna numberOfSeats" << std::endl;
	REQUIRE(!autko1.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(autko1.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;

	Car autko2("Polonez", 1985, "BS54321", 500, 4, 50, 1, 0);
	REQUIRE(autko2.name == "Polonez");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko2.numberplate == "BS54321");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko2.dateProduction == 1985);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko2.costOfRenting == 500);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko2.condition == 50);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko2.numberOfSeats == 4);
	std::cout << "Dobrze zdefiniowana zmienna numberOfSeats" << std::endl;
	REQUIRE(autko2.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(!autko2.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;
}

void TestKonstruktorTruck() {
	Truck autko;
	REQUIRE(autko.name == "");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko.numberplate == "BS00000");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko.dateProduction == 0);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko.costOfRenting == 0);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko.condition == 100);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko.capacity == 0);
	std::cout << "Dobrze zdefiniowana zmienna numberOfSeats" << std::endl;
	REQUIRE(!autko.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(autko.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;

	Truck autko1("Maluch", 1970, "BS12345", 200, 250);
	REQUIRE(autko1.name == "Maluch");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko1.numberplate == "BS12345");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko1.dateProduction == 1970);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko1.costOfRenting == 200);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko1.condition == 100);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko1.capacity == 250);
	std::cout << "Dobrze zdefiniowana zmienna numberOfSeats" << std::endl;
	REQUIRE(!autko1.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(autko1.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;

	Truck autko2("Polonez", 1985, "BS54321", 500, 300, 50, 1, 0);
	REQUIRE(autko2.name == "Polonez");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko2.numberplate == "BS54321");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko2.dateProduction == 1985);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko2.costOfRenting == 500);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko2.condition == 50);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko2.capacity == 300);
	std::cout << "Dobrze zdefiniowana zmienna numberOfSeats" << std::endl;
	REQUIRE(autko2.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(!autko2.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;
}

void TestKonstruktorVehicle() {
	Vehicle autko;
	REQUIRE(autko.name == "");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko.numberplate == "BS00000");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko.dateProduction == 0);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko.costOfRenting == 0);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko.condition == 100);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(!autko.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(autko.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;

	Vehicle autko1("Maluch", 1970, "BS12345", 200);
	REQUIRE(autko1.name == "Maluch");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko1.numberplate == "BS12345");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko1.dateProduction == 1970);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko1.costOfRenting == 200);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko1.condition == 100);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(!autko1.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(autko1.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;

	Vehicle autko2("Polonez", 1985, "BS54321", 500, 50, 1, 0);
	REQUIRE(autko2.name == "Polonez");
	std::cout << "Dobrze zdefiniowana zmienna name" << std::endl;
	REQUIRE(autko2.numberplate == "BS54321");
	std::cout << "Dobrze zdefiniowana zmienna numberplate" << std::endl;
	REQUIRE(autko2.dateProduction == 1985);
	std::cout << "Dobrze zdefiniowana zmienna dateProduction" << std::endl;
	REQUIRE(autko2.costOfRenting == 500);
	std::cout << "Dobrze zdefiniowana zmienna costOfRenting" << std::endl;
	REQUIRE(autko2.condition == 50);
	std::cout << "Dobrze zdefiniowana zmienna condition" << std::endl;
	REQUIRE(autko2.isRent);
	std::cout << "Dobrze zdefiniowana zmienna isRent" << std::endl;
	REQUIRE(!autko2.isWork);
	std::cout << "Dobrze zdefiniowana zmienna isWork" << std::endl;
}

void TestcanRent() {
	Car autko1;
	REQUIRE(autko1.canRent());
	std::cout << "Metoda canRent() dla isRent=0 i isWork=1 DZIALA" << std::endl;

	Truck autko2("Maluch", 2000, "BS98789", 100, 350, 100, 1, 1);
	REQUIRE(!autko2.canRent());
	std::cout << "Metoda canRent() dla isRent=1 i isWork=1 DZIALA" << std::endl;

	Vehicle autko3("Maluch", 2000, "BS98789", 100, 100, 0, 0);
	REQUIRE(!autko2.canRent());
	std::cout << "Metoda canRent() dla isRent=0 i isWork=0 DZIALA" << std::endl;
}

void TestRent() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5, 100, 0, 1);
	autko1.Rent();
	REQUIRE(autko1.isRent==1);
	std::cout << "Metoda Rent() dla canRent()=1 DZIALA" << std::endl;

	Truck autko2("Maluch", 2000, "BS98789", 100, 350, 100, 0, 0);
	autko2.Rent();
	REQUIRE(autko2.isRent==0);
	std::cout << "Metoda Rent() dla canRent()=0 DZIALA" << std::endl;
}

void TestReturn() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5, 100, 1, 1);
	autko1.Return();
	REQUIRE(autko1.isRent == 0);
	REQUIRE(autko1.condition == 90);
	std::cout << "Metoda Return() DZIALA" << std::endl;
}

void TestReduceCondition() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5, 100, 0, 1);
	autko1.ReduceCondition();
	REQUIRE(autko1.condition == 90);
	std::cout << "Metoda ReduceCondition() dla canRent()=1 DZIALA" << std::endl;

	Truck autko2("Maluch", 2000, "BS98789", 100, 350, 0, 0, 0);
	autko2.ReduceCondition();
	REQUIRE(autko2.condition == 0);
	std::cout << "Metoda ReduceCondition() dla canRent()=0 DZIALA" << std::endl;
}

void TestRepair() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5, 0, 0, 0);
	autko1.Repair();
	REQUIRE(autko1.condition == 100);
	REQUIRE(autko1.isWork == 1);
	std::cout << "Metoda Repair() dla isWork=0 DZIALA" << std::endl;

	Truck autko2("Maluch", 2000, "BS98789", 100, 350, 80, 0, 1);
	autko2.Repair();
	REQUIRE(autko2.condition == 80);
	REQUIRE(autko2.isWork == 1);
	std::cout << "Metoda Repair() dla isWork=1 DZIALA" << std::endl;
}

void TestOperatorComparisonVehicle() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5, 0, 0, 0);
	Car autko2 = autko1;
	REQUIRE(autko1 == autko2);
	std::cout << "Operator== dla tych samych działa DZIALA" << std::endl;

	Truck autko3("Maluch", 2000, "BS98789", 300, 350, 100, 0, 1);
	Truck autko4("Kia", 2010, "BS98765", 500, 350, 100, 0, 1);
	REQUIRE(!(autko3 == autko4));
	std::cout << "Operator== dla tych roznych działa DZIALA" << std::endl;
}

void TestVehicle(){
	TestKonstruktorVehicle();
	TestKonstruktorCar();
	TestKonstruktorTruck();
	TestcanRent();
	TestRent();
	TestReturn();
	TestReduceCondition();
	TestRepair();
	TestOperatorComparisonVehicle();
}
#endif