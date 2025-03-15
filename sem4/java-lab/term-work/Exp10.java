// Class definition, creating objects and constructors:
// Write a java program to create a class named 'Bank ' with the following data
// members:
// • Name of depositor
// • Address of depositor
// • Account Number
// • Balance in account
// Class 'Bank' has a method for each of the following:
// 1. Generate a unique account number for each depositor.
// 2. For first depositor, account number will be 1001, for second depositor
// it will be 1002 and so on
// 3. Display information and balance of depositor
// 4. Deposit more amount in balance of any depositor
// 5. Withdraw some amount from balance deposited.
// 6. Change address of depositor
// After creating the class, do the following operations.
// 1. Enter the information (name, address, account number, balance) of the
// depositors. Number of depositors is to be entered by the user.
// 2. Print the information of any depositor.
// 3. Add some amount to the account of any depositor and then display
// final information of that depositor.
// 4. Remove some amount from the account of any.
// depositor and then display final information of that depositor.
// 5. Change the address of any depositor and then display the final
// information of that depositor.
// 6. Randomly repeat these processes for some other
// bank accounts.
// create the program as loop based menu driven program.

import java.util.ArrayList;
import java.util.Scanner;

class Bank {
  private String depositorName;
  private String depositorAddress;
  private int accountNumber;
  private double balance;
  public static int nextAccountNumber = 0;

  public Bank(String name, String address, double initialBalance) {
    this.depositorName = name;
    this.depositorAddress = address;
    this.balance = initialBalance;
  }

  public String getName() { return depositorName; }

  public String getAddress() { return depositorAddress; }

  public int getAccountNumber() { return accountNumber; }

  public double getBalance() { return balance; }

  public void displayInfo() {
    System.out.println("\nDepositor Information:");
    System.out.println("Name: " + depositorName);
    System.out.println("Address: " + depositorAddress);
    System.out.println("Account Number: " + accountNumber);
    System.out.println("Balance: $" + balance);
  }

  public void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      System.out.println("$" + amount + " deposited successfully.");
    } else {
      System.out.println("Invalid amount. Deposit amount must be positive.");
    }
  }

  public void withdraw(double amount) {
    if (amount > 0) {
      if (amount <= balance) {
        balance -= amount;
        System.out.println("$" + amount + " withdrawn successfully.");
      } else {
        System.out.println("Insufficient balance.");
      }
    } else {
      System.out.println("Invalid amount. Withdrawal amount must be positive.");
    }
  }

  public void changeAddress(String newAddress) {
    this.depositorAddress = newAddress;
    System.out.println("Address updated successfully.");
  }
}

public class Exp10 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Bank Management System");
    System.out.print("Enter the number of depositors: ");
    int numDepositors = scanner.nextInt();
    scanner.nextLine();
    Bank accounts[] = new Bank[numDepositors];

    for (int i = 0; i < numDepositors; i++) {
      System.out.println("\nEnter details for Depositor " + (i + 1) + ":");
      System.out.print("Name: ");
      String name = scanner.nextLine();

      System.out.print("Address: ");
      String address = scanner.nextLine();

      System.out.print("Initial Balance: $");
      double initialBalance = scanner.nextDouble();
      scanner.nextLine();

      Bank account = new Bank(name, address, initialBalance);
      accounts[Bank.nextAccountNumber++] = account;
      System.out.println("Account created successfully with Account Number: " +
                         account.getAccountNumber());
    }

    int choice;
    do {
      displayMenu();
      choice = scanner.nextInt();
      scanner.nextLine();

      switch (choice) {
      case 1:
        System.out.print("Enter account number: ");
        int accNumber = scanner.nextInt();
        scanner.nextLine();

        Bank account = findAccount(accounts, accNumber);
        if (account != null) {
          account.displayInfo();
        } else {
          System.out.println("Account not found.");
        }
        break;

      case 2:
        System.out.print("Enter account number: ");
        accNumber = scanner.nextInt();
        scanner.nextLine();

        account = findAccount(accounts, accNumber);
        if (account != null) {
          System.out.print("Enter amount to deposit: $");
          double amount = scanner.nextDouble();
          scanner.nextLine();

          account.deposit(amount);
          account.displayInfo();
        } else {
          System.out.println("Account not found.");
        }
        break;

      case 3:
        System.out.print("Enter account number: ");
        accNumber = scanner.nextInt();
        scanner.nextLine();

        account = findAccount(accounts, accNumber);
        if (account != null) {
          System.out.print("Enter amount to withdraw: $");
          double amount = scanner.nextDouble();
          scanner.nextLine();

          account.withdraw(amount);
          account.displayInfo();
        } else {
          System.out.println("Account not found.");
        }
        break;

      case 4:
        System.out.print("Enter account number: ");
        accNumber = scanner.nextInt();
        scanner.nextLine();

        account = findAccount(accounts, accNumber);
        if (account != null) {
          System.out.print("Enter new address: ");
          String newAddress = scanner.nextLine();

          account.changeAddress(newAddress);
          account.displayInfo();
        } else {
          System.out.println("Account not found.");
        }
        break;

      case 5:
        System.out.println("\nList of all accounts:");
        for (Bank acc : accounts) {
          acc.displayInfo();
          System.out.println("--------------------------");
        }
        break;

      case 0:
        System.out.println("Exiting..");
        break;

      default:
        System.out.println("Invalid choice. Please try again.");
      }

    } while (choice != 0);

    scanner.close();
  }

  private static Bank findAccount(Bank accounts[], int accountNumber) {
    for (Bank account : accounts) {
      if (account.getAccountNumber() == accountNumber) {
        return account;
      }
    }
    return null;
  }

  private static void displayMenu() {
    System.out.println("\n==== Bank Management System Menu ====");
    System.out.println("1. Display account information");
    System.out.println("2. Deposit amount");
    System.out.println("3. Withdraw amount");
    System.out.println("4. Change address");
    System.out.println("5. List all accounts");
    System.out.println("0. Exit");
    System.out.print("Enter your choice: ");
  }
}
