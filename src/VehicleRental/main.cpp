#include "../VehicleRental/VehicleRental.hpp"
#include "../Tests/Test.hpp"

int main(int argc, char* argv[]){
    VehicleRental wypozyczalnia;
    if(argc == 1)
        wypozyczalnia.Menu();
    
    if(strcmp(argv[1],"test") == 0){
         std::cout<< "TESTY!!!" << std::endl;
         TestCustomer();
         TestVehicle();
         TestVehicleRental();
    };

    
    
}