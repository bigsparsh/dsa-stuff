/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// 9. Bank Account System
// • Objective: Create an abstract class BankAccount with a virtual function calculateInterest().
// Derive classes SavingsAccount and CheckingAccount and implement
// calculateInterest() differently for both account types.
// • Scenario:
// o You are designing a banking system where different types of accounts need to calculate interest
// differently.
// o The base class BankAccount will have a virtual function calculateInterest(). The
// derived classes SavingsAccount and CheckingAccount will implement it differently
// based on account types.
// • Instructions:
// o Define an abstract base class BankAccount with a pure virtual function
// calculateInterest().
// o Create a derived class SavingsAccount that calculates interest based on the balance (e.g., 4%
// annually).
// o Create a derived class CheckingAccount that calculates interest as a flat rate (e.g., 1%
// annually).
// o In the main function, create objects of both SavingsAccount and CheckingAccount, and
// use polymorphism to calculate interest.

#include <iostream>
using namespace std;

class BankAccount {
public:
    virtual void calculateInterest() = 0;
};

class SavingsAccount : public BankAccount {
public:
    void calculateInterest() {
        cout << "Calculating interest for savings account..." << endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    void calculateInterest() {
        cout << "Calculating interest for checking account..." << endl;
    }
};

int main() {
    BankAccount* account1 = new SavingsAccount();
    BankAccount* account2 = new CheckingAccount();

    account1->calculateInterest();
    account2->calculateInterest();

    delete account1;
    delete account2;

    return 0;
}
