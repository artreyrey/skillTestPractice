#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string brand; // Common attribute for all vehicles
    int year;     // Common attribute for all vehicles

public:
    // Parameterized constructor
    Vehicle(string b, int y) : brand(b), year(y) {}

    // Getter for brand
    string getBrand() const {
        return brand;
    }

    // Setter for brand
    void setBrand(const string& b) {
        brand = b;
    }

    // Getter for year
    int getYear() const {
        return year;
    }

    // Setter for year (with validation)
    void setYear(int y) {
        if (y >= 1900 && y <= 2023) { // Validate year
            year = y;
        } else {
            cout << "Invalid year! Year must be between 1900 and 2023." << endl;
        }
    }

    // Virtual function to display vehicle details
    virtual void displayDetails() const {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    // Pure virtual function for vehicle-specific behavior
    virtual void drive() const = 0;

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Derived class: Car
class Car : public Vehicle {
private:
    int numDoors; // Specific attribute for Car

public:
    // Parameterized constructor
    Car(string b, int y, int nd) : Vehicle(b, y), numDoors(nd) {}

    // Getter for numDoors
    int getNumDoors() const {
        return numDoors;
    }

    // Setter for numDoors (with validation)
    void setNumDoors(int nd) {
        if (nd >= 2 && nd <= 5) { // Cars typically have 2 to 5 doors
            numDoors = nd;
        } else {
            cout << "Invalid number of doors! Must be between 2 and 5." << endl;
        }
    }

    // Override displayDetails to include numDoors
    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class method
        cout << "Number of Doors: " << numDoors << endl;
    }

    // Override drive function
    void drive() const override {
        cout << "Driving the " << brand << " car with " << numDoors << " doors." << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
private:
    bool hasBasket; // Specific attribute for Bike

public:
    // Parameterized constructor
    Bike(string b, int y, bool hb) : Vehicle(b, y), hasBasket(hb) {}

    // Getter for hasBasket
    bool getHasBasket() const {
        return hasBasket;
    }

    // Setter for hasBasket
    void setHasBasket(bool hb) {
        hasBasket = hb;
    }

    // Override displayDetails to include hasBasket
    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class method
        cout << "Has Basket: " << (hasBasket ? "Yes" : "No") << endl;
    }

    // Override drive function
    void drive() const override {
        cout << "Riding the " << brand << " bike" << (hasBasket ? " with a basket." : ".") << endl;
    }
};

int main() {
    // Create a Car object
    Car car("Toyota", 2020, 4);
    cout << "Car Details:" << endl;
    car.displayDetails();
    car.drive();
    cout << endl;

    // Create a Bike object
    Bike bike("Hero", 2019, true);
    cout << "Bike Details:" << endl;
    bike.displayDetails();
    bike.drive();
    cout << endl;

    // Use polymorphism to handle vehicles
    Vehicle* vehicles[] = { &car, &bike };

    cout << "Polymorphic Behavior:" << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->displayDetails();
        vehicle->drive();
        cout << endl;
    }

    return 0;
}
