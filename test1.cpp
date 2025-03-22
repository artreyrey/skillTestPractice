#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int age;
    string favoriteFood;
    string course;

public:
    // Parameterized constructor
    Student(string n, int a, string ff, string c) : name(n), age(a), favoriteFood(ff), course(c) {}

    // Method to display student details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Favorite Food: " << favoriteFood << endl;
        cout << "Course: " << course << endl;
    }

    // Pure virtual function for pass/fail
    virtual void passFail() const = 0;

    // Virtual destructor
    virtual ~Student() = default;
};

class Undergraduate : public Student {
public:
    // Constructor
    Undergraduate(string n, int a, string ff, string c) : Student(n, a, ff, c) {}

    // Override passFail method
    void passFail() const override {
        if (age >= 18) {
            cout << "Pass: Eligible for college" << endl;
        }
        else {
            cout << "Fail: Cannot be in college" << endl;
        }
    }
};

int main() {
    // Variables to store user input
    string name, favoriteFood, course;
    int age;

    // Get user input
    cout << "Enter name: ";
    getline(cin, name); // Use getline to handle spaces
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(); // Clear the newline character left by cin
    cout << "Enter favorite food: ";
    getline(cin, favoriteFood); // Use getline to handle spaces
    cout << "Enter course: ";
    getline(cin, course); // Use getline to handle spaces

    // Create an Undergraduate object with user input
    Undergraduate lance(name, age, favoriteFood, course);

    // Display details and verify pass/fail
    lance.displayDetails();
    lance.passFail();

    return 0;
}
