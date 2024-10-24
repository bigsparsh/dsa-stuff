#include <iostream>

using namespace std;

class Transaction;
class Account {
  private: 
    double balance;
    void deposit (int amt) {
      balance += amt;
    }
    void withdraw (int amt) {
      if (amt > balance) {
        cout << "Not enough balance to withdraw." << endl;
      } else {
        balance -= amt;
      }
    }
    friend class Transaction;
  public:
    Account () : balance (0.0) {}
};

class Transaction {
  public: 
    void depositMoney (Account &acc, int amt) {
      acc.deposit(amt);
      cout << "Now your balance is: " << acc.balance << endl;
    }

    void withdrawMoney (Account &acc, int amt) {
      acc.withdraw(amt);
      cout << "Now your balance is: " << acc.balance << endl;
    }
};

int main () {
  Account acc;
  Transaction txn;
  
  txn.depositMoney (acc, 2100);
  txn.withdrawMoney (acc, 4000);
  txn.withdrawMoney (acc, 2000);

  return 0;
}
