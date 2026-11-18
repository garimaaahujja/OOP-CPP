#include <iostream>
#include <string>
#include <cstring>
#include <utility>
using namespace std;

class Student {
private:
    char* name;

public:
    // Default Constructor
    Student() {
        name = new char[8];
        strcpy(name, "Unknown");
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Student(const char* studentName) {
        name = new char[strlen(studentName) + 1];
        strcpy(name, studentName);
        cout << "Parameterized Constructor Called" << endl;
    }

    // Copy Constructor
    Student(const Student &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        cout << "Copy Constructor Called" << endl;
    }

    // Move Constructor
    Student(Student &&other) noexcept {
        name = other.name;
        other.name = nullptr;
        cout << "Move Constructor Called" << endl;
    }

    // Copy Assignment Operator
    Student& operator = (const Student &other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        cout << "Copy Assignment Operator Called" << endl;
        return *this;
    }

    // Move Assignment Operator
    Student& operator = (Student &&other) noexcept {
        if (this != &other) {
            delete[] name;
            name = other.name;
            other.name = nullptr;
        }
        cout << "Move Assignment Operator Called" << endl;
        return *this;
    }

    void display() const {
        if (name != nullptr) {
            cout << "Student Name: " << name << endl;
        } else {
            cout << "Student Name: Empty" << endl;
        }
    }

    // Destructor
    ~Student() {
        delete[] name;
        cout << "Destructor Called" << endl;
    }
};

int main() {
    cout << "\n--- Default Constructor ---\n";
    Student s1;
    s1.display();

    cout << "\n--- Parameterized Constructor ---\n";
    Student s2("Garima");
    s2.display();

    cout << "\n--- Copy Constructor ---\n";
    Student s3 = s2;
    s3.display();

    cout << "\n--- Move Constructor ---\n";
    Student s4 = move(s2);
    s4.display();

    cout << "\n--- Copy Assignment ---\n";
    s1 = s3;
    s1.display();

    cout << "\n--- Move Assignment ---\n";
    s1 = move(s4);
    s1.display();

    return 0;
}