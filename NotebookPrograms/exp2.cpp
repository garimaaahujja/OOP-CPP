#include <iostream>
#include <string>
using namespace std;

class ElectricCar {
private:
    string model;
    int batteryPercentage;

protected:
    string brand;
    int speed;

public:
    ElectricCar(string b, string m, int s, int battery) {
        brand = b;
        model = m;
        speed = s;
        batteryPercentage = battery;
    }

    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }

    void displayCarDetails() {
        cout << "Model: " << model << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }

    void displayElectricCarDetails() {
        displayBrand();
        displayCarDetails();
        cout << "Battery: " << batteryPercentage << "%" << endl;
    }

    void chargeBattery() {
        batteryPercentage = 100;
        cout << "Battery charged successfully!" << endl;
    }
};

int main() {
    ElectricCar car("Tesla", "Model S", 250, 80);

    cout << "\n--- Vehicle Details ---" << endl;
    car.displayElectricCarDetails();

    cout << "\n--- Charging Vehicle ---" << endl;
    car.chargeBattery();

    return 0;
}