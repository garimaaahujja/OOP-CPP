#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    vector<int> marks = {75, 90, 60, 85, 75};

    map<string, int> students;
    unordered_map<int, string> records;

    students["Amit"] = 75;
    students["Riya"] = 90;
    students["Neha"] = 60;
    students["Raj"] = 85;
    students["Simran"] = 70;

    int id = 1;
    for (auto s : students) {
        records[id++] = s.first;
    }

    sort(marks.begin(), marks.end());

    cout << "Sorted Marks: ";
    for (int m : marks) {
        cout << m << " ";
    }
    cout << endl;

    auto it = find_if(marks.begin(), marks.end(), [](int m) { return m > 80; });

    if (it != marks.end()) {
        cout << "\nFirst mark above 80: " << *it << endl;
    }

    transform(marks.begin(), marks.end(), marks.begin(), [](int m) { return m + 5; });

    cout << "\nAfter adding grace marks: ";
    for (int m : marks) {
        cout << m << " ";
    }
    cout << endl;

    return 0;
}