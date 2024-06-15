#include <iostream>

using namespace std;
 
class Vehicle {
public:
    void accelerate() {
        cout << "Accelerating a vehicle." << endl;
    }
};

class Car : public Vehicle {
public:
    void accelerate() {
        cout << "Accelerating a car." << endl;
    }
};

class Bike : public Vehicle {
public:
    void accelerate() {
        cout << "Accelerating a bike." << endl;
    }
};

int main() {
    Car car;
    Bike bike;
    
    car.accelerate();  // Calls the accelerate() function of the Car class
    
    bike.accelerate();  // Calls the accelerate() function of the Bike class
    
    return 0;
}

/*int main() {
    Car car;
    Bike bike;
    
    Vehicle& vehicleRef1 = car;
    vehicleRef1.accelerate();  // Calls the accelerate() function of the Car class
    
    Vehicle& vehicleRef2 = bike;
    vehicleRef2.accelerate();  // Calls the accelerate() function of the Bike class
    
    return 0;
}*/
