// Q4. Objective:
//     • Accept Principal Amount, Rate of Interest, and Time Period as
//     command-line arguments. • Calculate Simple Interest and Total Amount.
// Scenario:
// A bank needs a program where customers can enter:
// customer name
// Customer id
// Principal Amount
// Rate of Interest (per annum, in %)
// Time Period (in years)
// The system calculates:
// ✅ Simple Interest
// ✅ Total Amount (Principal + Interest)

import java.util.Scanner;

class Exp10 {

  String name, id;
  double principal, rate, time, si, total;

  void getDetails() {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter name: ");
    name = sc.next();
    System.out.print("Enter id: ");
    id = sc.next();
    System.out.print("Enter principal amount: ");
    principal = sc.nextDouble();
    System.out.print("Enter rate of interest: ");
    rate = sc.nextDouble();
    System.out.print("Enter time period: ");
    time = sc.nextDouble();
  }

  void calculate() {
    si = (principal * rate * time) / 100;
    total = principal + si;
  }

  void display() {
    System.out.println("Name: " + name);
    System.out.println("ID: " + id);
    System.out.println("Principal amount: " + principal);
    System.out.println("Rate of interest: " + rate);
    System.out.println("Time period: " + time);
    System.out.println("Simple interest: " + si);
    System.out.println("Total amount: " + total);
  }

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    int n;

    System.out.print("Enter number of customers: ");
    n = sc.nextInt();

    Exp10 obj[] = new Exp10[n];

    for (int i = 0; i < n; i++) {
      obj[i] = new Exp10();
      obj[i].getDetails();
      obj[i].calculate();
    }

    for (int i = 0; i < n; i++) {
      obj[i].display();
    }
  }
}
