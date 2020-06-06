##this is makefile
#usage:
#make || #make test || #make clean


CC = g++
CFLAGS = -c -Wall
OBJECTS = customer.o io_function.o mystack.o vehicle.o vehiclerental.o main.o
OBJDIR = ../bin
VRDIR = ../VehicleRental
VDIR = ../Vehicle
MSDIR = ../MyStack


rental: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

customer.o: customer.cpp customer.hpp
	$(CC) $(CFLAGS) $?

io_function: IO_functions.hpp
	$(CC) $(CFLAGS) $?

mystack: ../MyStack/MyStack.hpp ../MyStack/MyStack_impl.hpp
	$(CC) $(CFLAGS) $?

vehicle.o: ../Vehicle/Vehicle.cpp ../Vehicle/Vehicle.hpp
	$(CC) $(CFLAGS) $?

vehiclerental.o: ../VehicleRental/Enum.hpp ../VehicleRental/Menu.cpp ../VehicleRental/Test.hpp ../VehicleRental/VehicleRental.cpp ../VehicleRental/Vehicle.hpp
	$(CC) $(CFLAGS) $?
main.o: ../VehicleRental/main.cpp
	$(CC) $(CFLAGS)