// Q1.  Objective:
//     • Use the Scanner class to take user input.
//     • Implement a simple bank account system with deposit and withdrawal
//     features.
// A bank wants a simple program where customers can:
// ✅ Check balance
// ✅ Deposit money
// ✅ Withdraw money
// Create a class having functions to accept multiple customer data and
// performing above given operations.

import java.util.Scanner;

class Exp7 {

  int balance = 0;
  String name, accType;

  void checkBalance() { System.out.println("Balance: " + balance); }

  void deposit(int amount) {
    balance += amount;
    System.out.println("Deposited: " + amount);
  }

  void withdraw(int amount) {
    if (balance < amount) {
      System.out.println("Insufficient balance");
    } else {
      balance -= amount;
      System.out.println("Withdrawn: " + amount);
    }
  }

  void display() {
    System.out.println("Name: " + name);
    System.out.println("Account Type: " + accType);
    System.out.println("Balance: " + balance);
  }

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    int choice, amount;
    String name, accType;

    int n;

    System.out.print("Enter number of customers: ");
    n = sc.nextInt();

    Exp7 obj[] = new Exp7[n];

    for (int i = 0; i < n; i++) {
      obj[i] = new Exp7();
      System.out.print("Enter name: ");
      obj[i].name = sc.next();
      System.out.print("Enter account type: ");
      obj[i].accType = sc.next();
    }

    do {
      System.out.println("1. Check balance");
      System.out.println("2. Deposit money");
      System.out.println("3. Withdraw money");
      System.out.println("4. Display details");
      System.out.println("5. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();

      switch (choice) {
      case 1:
        System.out.print("Enter account number (1 - " + n + "): ");
        int accNo = sc.nextInt();
        obj[accNo - 1].checkBalance();
        break;
      case 2:
        System.out.print("Enter account number (1 - " + n + "): ");
        accNo = sc.nextInt();
        System.out.print("Enter amount to deposit: ");
        amount = sc.nextInt();
        obj[accNo - 1].deposit(amount);
        break;
      case 3:
        System.out.print("Enter account number (1 - " + n + "): ");
        accNo = sc.nextInt();
        System.out.print("Enter amount to withdraw: ");
        amount = sc.nextInt();
        obj[accNo - 1].withdraw(amount);
        break;
      case 4:
        System.out.print("Enter account number (1 - " + n + "): ");
        accNo = sc.nextInt();
        obj[accNo - 1].display();
        break;
      case 5:
        break;
      default:
        System.out.println("Invalid choice");
      }
    } while (choice != 5);
  }
}
