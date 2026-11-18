
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string name;
    double balance;

public:
    BankAccount(int acc, string n, double b) {
        accountNumber = acc;
        name = n;
        balance = b;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getName() {
        return name;
    }

    double getBalance() {
        return balance;
    }

    virtual void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    virtual void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid amount");
        balance += amount;
    }

    void deposit(int amount) {
        deposit((double)amount);
    }

    virtual void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid amount");
        if (amount > balance)
            throw runtime_error("Insufficient balance");
        balance -= amount;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int acc, string n, double b)
        : BankAccount(acc, n, b) {}

    void display() override {
        cout << "\n--- Savings Account ---";
        BankAccount::display();
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(int acc, string n, double b)
        : BankAccount(acc, n, b) {}

    void display() override {
        cout << "\n--- Current Account ---";
        BankAccount::display();
    }
};

int main() {
    vector<BankAccount*> accounts;

    accounts.push_back(new SavingsAccount(101, "Garima", 5000));
    accounts.push_back(new CurrentAccount(102, "Kristal", 8000));

    int choice, index;
    double amount;

    do {
        cout << "\n\n--- BANK MANAGEMENT SYSTEM ---";
        cout << "\n1. Display Accounts";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Save Records";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    for (BankAccount* acc : accounts)
                        acc->display();
                    break;

                case 2:
                    cout << "Enter account index (1 or 2): ";
                    cin >> index;
                    cout << "Enter amount: ";
                    cin >> amount;

                    if (index < 1 || index > 2)
                        throw out_of_range("Invalid account");

                    accounts[index - 1]->deposit(amount);
                    cout << "Deposit successful!";
                    break;

                case 3:
                    cout << "Enter account index (1 or 2): ";
                    cin >> index;
                    cout << "Enter amount: ";
                    cin >> amount;

                    if (index < 1 || index > 2)
                        throw out_of_range("Invalid account");

                    accounts[index - 1]->withdraw(amount);
                    cout << "Withdrawal successful!";
                    break;

                case 4: {
                    ofstream file("accounts.txt");

                    if (!file)
                        throw runtime_error("File opening failed");

                    for (BankAccount* acc : accounts) {
                        file << acc->getAccountNumber() << ","
                             << acc->getName() << ","
                             << acc->getBalance() << endl;
                    }

                    file.close();
                    cout << "Records saved successfully!";
                    break;
                }

                case 5:
                    cout << "Thank you!";
                    break;

                default:
                    cout << "Invalid choice!";
            }
        }
        catch (exception& e) {
            cout << "\nError: " << e.what();
        }

    } while (choice != 5);

    for (BankAccount* acc : accounts)
        delete acc;

    return 0;
}
