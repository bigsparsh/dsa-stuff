import java.util.Scanner;

class Exp10 {

  String name;
  int id;
  double principalAmount;
  double rateOfInterest;
  double timePeriod;

  Exp10 (int i, String n, double p, double r, double t) {
    id = i;
    name = n;
    principalAmount = p;
    rateOfInterest = r;
    timePeriod = t;
  }

  double simpleInterest() {
    return (principalAmount * rateOfInterest * timePeriod) / 100;
  }

  double totalAmount() {
    return principalAmount + simpleInterest();
  }

  public static void main(String args[]) {

    Exp10 obj = null;
    Scanner sc = new Scanner(System.in);
    int choice;

    do {
      System.out.println("1. Enter customer details");
      System.out.println("2. Calculate simple interest and total amount");
      System.out.println("3. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();

      switch (choice) {
        case 1:
          System.out.print("Enter customer id: ");
          int id = sc.nextInt();
          System.out.print("Enter customer name: ");
          String name = sc.next();
          System.out.print("Enter principal amount: ");
          double principalAmount = sc.nextDouble();
          System.out.print("Enter rate of interest: ");
          double rateOfInterest = sc.nextDouble();
          System.out.print("Enter time period: ");
          double timePeriod = sc.nextDouble();
          obj = new Exp10(id, name, principalAmount, rateOfInterest, timePeriod);
          break;
        case 2:
          System.out.println("Simple interest: " + obj.simpleInterest());
          System.out.println("Total amount: " + obj.totalAmount());
          break;
        case 3:
          break;
        default:
          System.out.println("Invalid choice");
      }
    } while (choice != 3);

    sc.close();

  }
}
