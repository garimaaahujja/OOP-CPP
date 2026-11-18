#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name = "Rahul";
    
    void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    int roll = 101;
};

class GraduateStudent : public Student {
public:
    string degree = "MCA";
};

int main() {
    GraduateStudent g;
    g.display();
    cout << "Roll No.: " << g.roll << endl;
    cout << "Degree: " << g.degree << endl;
    return 0;
}