#include <iostream>

class Bank {
  private:
    int accNum;
    std::string name, accType;
    double balance;
  public:
    void setProperties (int a, std::string t, std::string n, double b) {
      accNum = a;
      name = n;
      accType = t;
      balance = b;
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
};

int main () {
  Bank bnk;
  int accNum, choice;
  std::string name, accType;
  double amount;

  do {
    std::cout << "\nWelcome to Bank\n 1. Set Bank Information\n 2. Display balance\n 3. Deposit\n 4. Withdraw\n 5. Exit\n Enter your choice (1/2/3/4): ";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "\nEnter bank account number, type, your name and balance: ";
        std::cin >> accNum >> accType >> name >> amount;
        bnk.setProperties(accNum, accType, name, amount);
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
    }
  } while (choice < 5);

  std::cout << "\nExiting...\n";

  return 0;
}
