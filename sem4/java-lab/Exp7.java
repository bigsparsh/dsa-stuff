import java.util.Scanner;

class Exp7 {

  int balance = 0;
  String name;
  String accountType;

  Exp7 (int b, String n, String at) {
    balance = b;
    name = n;
    accountType = at;
  }

  void checkBalance() {
    System.out.println("Your balance is: " + balance);
  }

  void deposit(int amount) {
    balance += amount;
    System.out.println("Deposited " + amount + " successfully");
  }

  void withdraw(int amount) {
    if (balance < amount) System.out.println("Insufficient balance");
    else {
      balance -= amount;
      System.out.println("Withdrawn " + amount + " successfully");
    }
  }

  public static void main(String args[]) {

    int balance;
    String name, accountType;

    Scanner sc = new Scanner(System.in);

    System.out.print("Enter your name: ");
    name = sc.nextLine();

    System.out.print("Enter your account type: ");
    accountType = sc.nextLine();
    
    System.out.print("Enter your balance: ");
    balance = sc.nextInt();

    Exp7 obj = new Exp7(balance, name, accountType);

    int choice, amount;

    do {
      System.out.println("1. Check balance");
      System.out.println("2. Deposit money");
      System.out.println("3. Withdraw money");
      System.out.println("4. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();

      switch (choice) {
        case 1:
          obj.checkBalance();
          break;
        case 2:
          System.out.print("Enter the amount to deposit: ");
          amount = sc.nextInt();
          obj.deposit(amount);
          break;
        case 3:
          System.out.print("Enter the amount to withdraw: ");
          amount = sc.nextInt();
          obj.withdraw(amount);
          break;
        case 4:
          System.out.println("Exiting...");
          break;
        default:
          System.out.println("Invalid choice");
      }
    } while (choice != 4);

    sc.close();

  }
}
