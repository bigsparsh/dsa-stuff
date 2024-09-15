#include <iostream>

class SavingsAccount {
  private:
    double savingsBalance;
    static double annualInterestRate;
  public:
    SavingsAccount () {
      savingsBalance = 0.0;
    }
    void calculateMonthlyInterest () {
      savingsBalance += (savingsBalance * annualInterestRate) / 12;
    }
    static void modifyInterestRate (double newRate) {
      annualInterestRate = newRate;
    }
    void setSavingsBalance (double sb) {
      savingsBalance = sb;
    }
    double getSavingsBalance () {
      return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0;

int main () {
  SavingsAccount saver1, saver2;
  saver1.setSavingsBalance(2000.00);
  saver2.setSavingsBalance(3000.00);
  SavingsAccount::modifyInterestRate(0.04);
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  std::cout << "Saver 1: " << saver1.getSavingsBalance() << "\n";
  std::cout << "Saver 2: " << saver2.getSavingsBalance() << "\n";
  SavingsAccount::modifyInterestRate(0.05);
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  std::cout << "Saver 1: " << saver1.getSavingsBalance() << "\n";
  std::cout << "Saver 2: " << saver2.getSavingsBalance() << "\n";
  return 0;
}
