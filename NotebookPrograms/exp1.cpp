#include <iostream>
using namespace std;

int main() {
    int age = 20;
    float percentage = 85.5f;
    double pi = 3.14159265;
    char grade = 'A';
    bool isStudent = true;

    const int DAYS_IN_WEEK = 7;

    int a = 10;
    int b = 5;

    int sum = a + b;
    int difference = a - b;
    int multiplication = a * b;
    int division = a / b;

    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "\n--- Student Information ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Percentage: " << percentage << endl;
    cout << "Value of Pi: " << pi << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student: " << isStudent << endl;
    cout << "Days in a week: " << DAYS_IN_WEEK << endl;

    cout << "\n--- Operator Results ---" << endl;
    cout << "Addition: " << sum << endl;
    cout << "Subtraction: " << difference << endl;
    cout << "Multiplication: " << multiplication << endl;
    cout << "Division: " << division << endl;

    return 0;
}