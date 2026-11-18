#include <iostream>
using namespace std;

class Complex {
public:
    int real, image;

    Complex(int r = 0, int i = 0) {
        real = r;
        image = i;
    }

    // Function Overloading
    void add(int a, int b) {
        cout << "Integer Sum: " << a + b << endl;
    }

    void add(double a, double b) {
        cout << "Double Sum: " << a + b << endl;
    }

    // Operator Overloading
    Complex operator + (const Complex &c) {
        return Complex(real + c.real, image + c.image);
    }

    void display() {
        cout << real << " + " << image << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(2, 5);
    c1.add(10, 20);

    Complex c3 = c1 + c2;
    cout << "Complex Sum: ";
    c3.display();

    return 0;
}