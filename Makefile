##this is makefile
#usage:
#make || #make test || #make clean


CXX = g++
CXXFLAGS = -Wall -c
BIN := bin
TARGET := $(BIN)/all
OBJ = bin/customer.o bin/vehicle.o bin/vehiclerental.o bin/main.o

all : $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $? -o $@
bin/main.o: src/VehicleRental/main.cpp  src/VehicleRental/*.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@
bin/menu.o 
bin/customer.o: src/Customer/Customer.cpp src/Customer/Customer.hpp 
	$(CXX) $(CXXFLAGS)  $< -o $@
bin/vehicle.o: src/Vehicle/Vehicle.cpp src/Vehicle/Vehicle.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@
bin/vehiclerental.o: src/VehicleRental/VehicleRental.cpp src/VehicleRental/Menu.cpp src/VehicleRental/*.hpp src/Tests/*.hpp src/IO_functions/*.hpp src/MyStack/*.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@




clean:
	rm -f $(OBJ) $(TARGET)