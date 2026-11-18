#include <iostream>
#include <exception>
using namespace std;

class BankException : public exception {
public:
    const char* what() const noexcept override {
        return "Banking Error";
    }
};

class InsufficientBalance : public BankException {
public:
    const char* what() const noexcept override {
        return "Insufficient balance!";
    }
};

class InvalidAmount : public BankException {
public:
    const char* what() const noexcept override {
        return "Invalid transaction amount!";
    }
};

int main() {
    double balance = 5000, amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        if (amount <= 0) {
            throw InvalidAmount();
        }
        if (amount > balance) {
            throw InsufficientBalance();
        }
        balance -= amount;
        cout << "Transaction Successful!";
        cout << "\nRemaining balance: " << balance;
    }
    catch (const InvalidAmount &e) {
        cout << e.what();
    }
    catch (const InsufficientBalance &e) {
        cout << e.what();
    }

    return 0;
}