##this is makefile
#usage:
#make || #make test || #make clean


CXX = g++
CXXFLAGS = -Wall -c
BIN := bin
TARGET := $(BIN)/all
OBJ = bin/customer.o bin/vehicle.o bin/vehiclerental.o bin/main.o bin/menu.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $? -o $@ 
# bin/main.o: src/VehicleRental/main.cpp  src/VehicleRental/*.hpp
# 	$(CXX) $(CXXFLAGS)  $< -o $@
bin/customer.o: src/Customer/Customer.cpp src/Customer/Customer.hpp src/Vehicle/Vehicle.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@ 
bin/vehicle.o: src/Vehicle/*.cpp src/Vehicle/Vehicle.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@ 
bin/vehiclerental.o: src/VehicleRental/*.cpp src/VehicleRental/VehicleRental.hpp src/IO_functions/*.hpp src/MyStack/MyStack_impl.hpp src/Vehicle/Vehicle.hpp\
	src/Customer/Customer.hpp 
	$(CXX) $(CXXFLAGS)  $< -o $@ 
bin/main.o: src/VehicleRental/main.cpp src/Tests/Test.hpp src/VehicleRental/VehicleRental.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@
bin/menu.o: src/VehicleRental/Menu.cpp src/VehicleRental/VehicleRental.hpp
	$(CXX) $(CXXFLAGS)  $< -o $@
run: all
	bin/all test
clean:
	rm -f $(OBJ) $(TARGET)