#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream f("student.csv", ios::in | ios::out | ios::trunc);

    f << "101, Amit, 90\n";
    f << "102, Rahul, 85\n";

    cout << "Position: " << f.tellp() << endl;

    f.seekg(0);
    cout << "Read Position: " << f.tellg() << endl;

    string line;
    while (getline(f, line)) {
        cout << line << endl;
    }

    f.seekp(0);
    cout << "Write Position: " << f.tellp() << endl;

    f.close();
    return 0;
}