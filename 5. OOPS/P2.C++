/*Challenge: Create a Car class that simulates the behavior of a vehicle.
Attributes:
model: String representing the car model name.
year: Integer indicating the car's manufacturing year.
fuelLevel: Double representing the remaining fuel quantity (percentage or liters).
speed: Integer representing the current speed in kilometers per hour.
isRunning: Boolean indicating whether the car is currently running.
Methods:
startEngine(): Sets isRunning to true and prints a starting message.
stopEngine(): Sets isRunning to false and prints a stopping message.
accelerate(amount): Increases the car's speed by the specified amount (check engine state and fuel level).
brake(amount): Decreases the car's speed by the specified amount (ensure speed doesn't become negative).
refuel(amount): Increases the fuel level by the specified amount (check for tank capacity).
printStatus(): Displays the car's model, speed, fuel level, and running state.
*/

#include <iostream>
using namespace std;

class Car {
public:
    string model;
    int year;
    double fuel;      // in liters
    int speed;        // km/h
    bool isRunning;

    Car(string m, int y, double f) {
        model = m;
        year = y;
        fuel = f;
        speed = 0;
        isRunning = false;
    }

    void startEngine() {
        if(!isRunning) {
            isRunning = true;
            cout << model << " engine started." << endl;
        } else {
            cout << model << " engine is already running." << endl;
        }
    }

    void stopEngine() {
        if(isRunning) {
            isRunning = false;
            speed = 0;
            cout << model << " engine stopped." << endl;
        } else {
            cout << model << " engine is already off." << endl;
        }
    }

    void accelerate(int amount) {
        if(isRunning && fuel > 0) {
            speed += amount;
            fuel -= amount * 0.05;  // simple fuel consumption
            if(fuel < 0) fuel = 0;
            cout << model << " accelerated to " << speed << " km/h." << endl;
        } else if(!isRunning) {
            cout << model << " can't accelerate, engine is off." << endl;
        } else {
            cout << model << " can't accelerate, no fuel." << endl;
        }
    }

    void brake(int amount) {
        speed -= amount;
        if(speed < 0) speed = 0;
        cout << model << " slowed down to " << speed << " km/h." << endl;
    }

    void refuel(double amount) {
        fuel += amount;
        if(fuel > 100) fuel = 100; // assuming tank max capacity 100 liters
        cout << model << " refueled to " << fuel << " liters." << endl;
    }

    void printStatus() {
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel: " << fuel << " liters" << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Running: " << (isRunning ? "Yes" : "No") << endl;
    }
};

int main() {
    Car c1("BMW", 1980, 60.0);
    Car c2("Ferrari", 1950, 65.0);

    c1.startEngine();
    c1.accelerate(25);
    c1.brake(120);
    c1.refuel(20);

    c2.startEngine();
    c2.brake(220);

    cout << endl;
    c1.printStatus();
    cout << endl;
    c2.printStatus();

    return 0;
}
