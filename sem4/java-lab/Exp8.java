// Q2. Objective:
//     • Use Scanner to take user input for product selection.
//     • Calculate the total bill after shopping.
// Scenario:
// A shopping website wants a program where users:
// ✅ Select items (Mobile, Laptop, Headphones)
// ✅ Choose quantity
// ✅ Get the total bill
// Create a class having functions to accept multiple customer data and
// performing above given operations.

import java.util.Scanner;

class Exp8 {

  String name;
  int price = 0;

  void selectItems() {
    Scanner sc = new Scanner(System.in);
    int choice, q;
    System.out.println("Select items:");
    System.out.println("1. Mobile");
    System.out.println("2. Laptop");
    System.out.println("3. Headphones");
    System.out.print("Enter choice: ");
    choice = sc.nextInt();
    System.out.println("Enter the quantity: ");
    q = sc.nextInt();
    switch (choice) {
    case 1:
      price += 10000 * q;
      break;
    case 2:
      price += 50000 * q;
      break;
    case 3:
      price += 1000 * q;
      break;
    default:
      System.out.println("Invalid choice");
    }
  }

  void getBill() { System.out.println("Total bill: " + price); }

  void display() {
    System.out.println("Name: " + name);
    System.out.println("Price: " + price);
  }

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    int choice, quantity, price;
    String name, product;

    int n;

    System.out.print("Enter number of customers: ");
    n = sc.nextInt();

    Exp8 obj[] = new Exp8[n];

    for (int i = 0; i < n; i++) {
      obj[i] = new Exp8();
      System.out.print("Enter name: ");
      obj[i].name = sc.next();
    }

    do {
      System.out.println("1. Select items");
      System.out.println("2. Get bill");
      System.out.println("3. Display details");
      System.out.println("4. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();

      switch (choice) {
      case 1:
        System.out.println("Enter customer number (1 - " + n + "): ");
        int custNo = sc.nextInt();
        obj[custNo - 1].selectItems();
        break;
      case 2:
        System.out.println("Enter customer number (1 - " + n + "): ");
        custNo = sc.nextInt();
        obj[custNo - 1].getBill();
        break;
      case 3:
        System.out.println("Enter customer number (1 - " + n + "): ");
        custNo = sc.nextInt();
        obj[custNo - 1].display();
        break;
      case 4:
        break;
      }
    } while (choice != 4);
  }
}
