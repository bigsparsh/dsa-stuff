// 2. Bank Account Management:
//    Design a BankAccount class that represents a customer's bank account. The class should have attributes for the account holder's name, account number, balance, and interest rate.
//    Implement methods for depositing money, withdrawing money, and calculating interest.
//    Create a few objects of BankAccount and demonstrate the use of these methods.

#include <iostream>

class BankAccount {
  private:
    int accNum;
    std::string name;
    double balance, interestRate;
  public:
    void setProperties (int a, std::string n, double b, double ir) {
      accNum = a;
      name = n;
      balance = b;
      interestRate = ir;
    }
    void deposit (double amount) {
      balance += amount;
    }
    void withdraw (double amount) {
      if (balance - amount < 0) std::cout << "Insufficient balance" << std::endl;
      else balance -= amount;
    }
    void display () {
      std::cout << "Name: " << name << std::endl;
      std::cout << "Balance: " << balance << std::endl;
    }
    void calcInterest () {
      double interest = balance * interestRate / 100;
      balance += interest;
      std::cout << "Interest: " << interest << std::endl;
    }
};

int main () {
  BankAccount bnk;
  int accNum, choice;
  std::string name;
  double amount, interestRate;

  do {
    std::cout << "\nWelcome to Bank\n 1. Set Bank Information\n 2. Display balance\n 3. Deposit\n 4. Withdraw\n 5. Calculate interest\n 6. Exit \n Enter your choice (1-6): ";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "\nEnter bank account number, your name, balance and interest rate: ";
        std::cin >> accNum >>  name >> amount >> interestRate;
        bnk.setProperties(accNum, name, amount, interestRate);
        break;
      case 2:
        bnk.display();
        break;
      case 3:
        std::cout << "\nEnter the amount to deposit: ";
        std::cin >> amount;
        bnk.deposit(amount);
        break;
      case 4:
        std::cout << "\nEnter the amount to withdraw: ";
        std::cin >> amount;
        bnk.withdraw(amount);
        break;
      case 5:
        bnk.calcInterest();
        break;
    }
  } while (choice < 6);

  std::cout << "\nExiting...\n";

  return 0;
}
