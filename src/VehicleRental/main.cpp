#include "../VehicleRental/VehicleRental.hpp"
#include "../VehicleRental/Test.hpp"

int main(int argc, char* argv[]){
    VehicleRental wypozyczalnia;
    
    if(argc == 1)
        wypozyczalnia.Menu();
     if(argv[1] == "-test")
        Test();
    
}