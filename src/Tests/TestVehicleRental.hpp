#ifndef TEST_VEHICLERENTAL_H
#define TEST_VEHICLERENTAL_H
#include "../VehicleRental/VehicleRental.hpp"
#include <assert.h>

#define REQUIRE(exp) assert(exp)

void TestAddVR() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5);
	Truck autko2("Maluch", 2002, "BS91239", 150, 500);
	Customer klient("Anna","Adamiakowa",12345678901,'B');
	VehicleRental wyp;
	wyp.Add(autko1);
	REQUIRE(wyp.CarList[0] == autko1);
	std::cout << "Metoda Add w klasie VehicelRental dla obiektow Car DZIALA" << std::endl;
	wyp.Add(autko2);
	REQUIRE(wyp.TruckList[0] == autko2);
	std::cout << "Metoda Add w klasie VehicelRental dla obiektow Truck DZIALA" << std::endl;
	wyp.Add(klient);
	REQUIRE(wyp.CustomerList[0] == klient);
	std::cout << "Metoda Add w klasie VehicelRental dla obiektow Customer DZIALA" << std::endl;
	wyp.Delete(autko1);
	wyp.Delete(autko2);
	wyp.Delete(klient);
}

void TestDeleteVR() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5);
	Truck autko2("Maluch", 2002, "BS91239", 150, 500);
	Customer klient1("Anna", "Adamiakowa", 12345678901, 'B');
	Car autko3("Jaguar", 2010, "BS98439", 200, 2);
	Truck autko4("MAN", 2012, "BS83119", 400, 800);
	Customer klient2("Adam", "Annowy", 12345676438, 'B');
	VehicleRental wyp;
	wyp.Add(autko1);
	wyp.Add(autko3);
	REQUIRE(wyp.CarList[wyp.CarList.size()-1] == autko3);
	wyp.Delete(autko3);
	REQUIRE(wyp.CarList[wyp.CarList.size() - 1] == autko1);
	std::cout << "Metoda Delete w klasie VehicelRental dla obiektow Car DZIALA" << std::endl;
	wyp.Add(autko2);
	wyp.Add(autko4);
	REQUIRE(wyp.TruckList[wyp.TruckList.size() - 1] == autko4);
	wyp.Delete(autko4);
	REQUIRE(wyp.TruckList[wyp.TruckList.size() - 1] == autko2);
	std::cout << "Metoda Delete w klasie VehicelRental dla obiektow Truck DZIALA" << std::endl;
	wyp.Add(klient1);
	wyp.Add(klient2);
	REQUIRE(wyp.CustomerList[wyp.CustomerList.size() - 1] == klient2);
	wyp.Delete(klient2);
	REQUIRE(wyp.CustomerList[wyp.CustomerList.size() - 1] == klient1);
	std::cout << "Metoda Delete w klasie VehicelRental dla obiektow Customer DZIALA" << std::endl;
}

void TestRentVR() {
	Car autko1("Polonez", 2000, "BS97979", 100, 5);
	Truck autko2("Maluch", 2002, "BS91239", 150, 500);
	Customer klient1("Anna", "Adamiakowa", 12345678901, 'B');
	Customer klient2("Adam", "Annowy", 12345676438, 'C');
	VehicleRental wyp;
	wyp.Add(autko1);
	wyp.Add(autko2);
	wyp.Add(klient1);
	wyp.Add(klient2);
	wyp.Rent(wyp.CarList[0], wyp.CustomerList[0]);
	REQUIRE(wyp.CustomerList[0].rented_vehicle == autko1);
	REQUIRE(wyp.CarList[0].isRent == 1);
	std::cout << "Metoda Rent w klasie VehicelRental dla obiektow Customer i Car DZIALA" << std::endl;
	wyp.Rent(wyp.TruckList[0], wyp.CustomerList[1]);
	REQUIRE(wyp.CustomerList[1].rented_vehicle == autko2);
	REQUIRE(wyp.TruckList[0].isRent == 1);
	std::cout << "Metoda Rent w klasie VehicelRental dla obiektow Customer i Truck DZIALA" << std::endl;
	wyp.Delete(autko1);
	wyp.Delete(autko2);
	wyp.Delete(klient1);
	wyp.Delete(klient2);
}

void TestReturnVR() {
	Car zadne;
	Truck zadneT;
	Car autko1("Polonez", 2000, "BS97979", 100, 5);
	Truck autko2("Maluch", 2002, "BS91239", 150, 500);
	Customer klient1("Anna", "Adamiakowa", 12345678901, 'B');
	Customer klient2("Adam", "Annowy", 12345676438, 'C');
	VehicleRental wyp;
	wyp.Add(autko1);
	wyp.Add(autko2);
	wyp.Add(klient1);
	wyp.Add(klient2);
	wyp.Rent(wyp.CarList[0], wyp.CustomerList[0]);
	REQUIRE(wyp.CustomerList[0].rented_vehicle == autko1);
	REQUIRE(wyp.CarList[0].isRent == 1);
	wyp.Return(wyp.CustomerList[0]);
	REQUIRE(wyp.CustomerList[0].rented_vehicle == zadne);
	REQUIRE(wyp.CarList[0].isRent == 0);
	std::cout << "Metoda Return w klasie VehicelRental dla obiektow Customer i Car DZIALA" << std::endl;
	wyp.Rent(wyp.TruckList[0], wyp.CustomerList[1]);
	REQUIRE(wyp.CustomerList[1].rented_vehicle == autko2);
	REQUIRE(wyp.TruckList[0].isRent == 1);
	wyp.Return(wyp.CustomerList[1]);
	REQUIRE(wyp.CustomerList[1].rented_vehicle == zadneT);
	REQUIRE(wyp.TruckList[0].isRent == 0);
	std::cout << "Metoda Return w klasie VehicelRental dla obiektow Customer i Truck DZIALA" << std::endl;
	wyp.Delete(autko1);
	wyp.Delete(autko2);
	wyp.Delete(klient1);
	wyp.Delete(klient2);
}

void TestPaymentVR() {
	VehicleRental wyp;
	Car a;
	Customer klient1("Anna", "Adamiakowa", 12345678901, 'B');
	Customer klient2("Adam", "Annowy", 12345676438, 'B', a, 1000);
	wyp.Add(klient1);
	wyp.Add(klient2);
	wyp.Payment(wyp.CustomerList[0], 100);
	wyp.Payment(wyp.CustomerList[1], 500);
	REQUIRE(wyp.CustomerList[0].debt == -100);
	REQUIRE(wyp.CustomerList[1].debt == 500);
	std::cout << "Metoda Payment w klasie VehicelRental DZIALA" << std::endl;
	wyp.Delete(klient1);
	wyp.Delete(klient2);

}


void TestVehicleRental(){
	TestAddVR();
	TestDeleteVR();
	TestPaymentVR();
	TestRentVR();
	TestReturnVR();
}
#endif