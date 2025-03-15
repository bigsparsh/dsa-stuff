// Concepts of Java Control statements, Conditional statements, loops and
// iterations, Wrapper classes, Scanner Class:
// Using the switch statement, write a menu-driven program to calculate the
// maturity amount of a bank deposit.
// The user is given the following options:
// (i) Term Deposit
// (ii) Recurring Deposit
// For option (i) accept Principal (p), rate of interest (r) and time period in
// years (n). Calculate and output the maturity amount (a) receivable using the
// formula a = p[1 + r / 100]n. For option (ii) accept monthly installment (p),
// rate of interest (r) and time period in months (n). Calculate and output the
// maturity amount (a) receivable using the formula a = p * n + p * n(n + 1) / 2
// * r / 100 * 1 / 12. For an incorrect option, an appropriate error message
// should be displayed. [ Use Scanner Class to take input ]

import java.util.Scanner;

public class Exp2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the type of deposit: ");
    System.out.println("1. Term Deposit");
    System.out.println("2. Recurring Deposit");
    int choice = sc.nextInt();
    switch (choice) {
    case 1:
      System.out.println("Enter the principal amount: ");
      double p = sc.nextDouble();
      System.out.println("Enter the rate of interest: ");
      double r = sc.nextDouble();
      System.out.println("Enter the time period in years: ");
      double n = sc.nextDouble();
      double a = p * (1 + r / 100) * n;
      System.out.println("Maturity amount: " + a);
      break;
    case 2:
      System.out.println("Enter the monthly installment: ");
      double p1 = sc.nextDouble();
      System.out.println("Enter the rate of interest: ");
      double r1 = sc.nextDouble();
      System.out.println("Enter the time period in months: ");
      double n1 = sc.nextDouble();
      double a1 = p1 * n1 + p1 * n1 * (n1 + 1) / 2 * r1 / 100 * 1 / 12;
      System.out.println("Maturity amount: " + a1);
      break;
    default:
      System.out.println("Invalid choice");
    }
  }
}
