#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
class Customer;


class Vehicle{
protected:
	std::string numberplate;
	std::string name;
	int dateProduction;
	int costOfRenting;
	int condition;
	bool isRent;
	bool isWork;

public:
	Vehicle(std::string, int, std::string, int);
	Vehicle(std::string, int, std::string, int, int, bool, bool);
	Vehicle();
	//	~Vehicle();
protected:
	bool canRent();
	void Rent();
	void Return();
	void ReduceCondition();
	void Repair();

public:
	bool operator==(const Vehicle&);
	
	friend std::ostream& operator<< (std::ostream& os, Vehicle& vehi);
	friend std::ostream& operator<< (std::ostream& os, Customer& klient);
	friend class Customer;
	friend class VehicleRental;
	
	friend void TestKonstruktorVehicle();
	friend void TestKonstruktorCar();
	friend void TestcanRent();
	friend void TestRent();
	friend void TestReturn();
	friend void TestReduceCondition();
	friend void TestRepair();
	friend void TestRentVR();
	friend void TestReturnVR();
};

class Car :public Vehicle {
	int numberOfSeats;

public:
	Car(std::string, int, std::string, int, int);
	Car(std::string, int, std::string, int, int, int, bool, bool);
	Car();
	//	~Car();
	friend
		std::ostream& operator<< (std::ostream& os, Car& vehi);


	friend class Customer;
	friend class VehicleRental;
};

class Truck :public Vehicle {
	int capacity;

public:
	Truck(std::string, int, std::string, int, int);
	Truck(std::string, int, std::string, int, int,  int, bool, bool);
	Truck();
	//	~Truck();
	friend
		std::ostream& operator<< (std::ostream& os, Truck& vehi);


	friend class Customer;
	friend class VehicleRental;
};
#endif
