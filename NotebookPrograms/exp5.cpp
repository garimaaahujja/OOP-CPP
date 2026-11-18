#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
};

class Circle : public Shape {
public:
    void area() override {
        cout << "Circle Area: 78.5" << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() override {
        cout << "Rectangle Area: 20" << endl;
    }
};

class Triangle : public Shape {
public:
    void area() override {
        cout << "Triangle Area: 15" << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;
    Triangle t;
    Shape *s;

    s = &c;
    s->area();

    s = &r;
    s->area();

    s = &t;
    s->area();

    return 0;
}