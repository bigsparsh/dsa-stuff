import java.util.Scanner;

class Exp8 {

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    int choice, quantity;
    double totalBill = 0;

    do {
      System.out.println("1. Mobile");
      System.out.println("2. Laptop");
      System.out.println("3. Headphones");
      System.out.println("4. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();

      switch (choice) {
        case 1:
          System.out.print("Enter quantity: ");
          quantity = sc.nextInt();
          totalBill += 10000 * quantity;
          break;
        case 2:
          System.out.print("Enter quantity: ");
          quantity = sc.nextInt();
          totalBill += 50000 * quantity;
          break;
        case 3:
          System.out.print("Enter quantity: ");
          quantity = sc.nextInt();
          totalBill += 1000 * quantity;
          break;
        case 4:
          System.out.println("Total bill: " + totalBill);
          break;
        default:
          System.out.println("Invalid choice");
      }
    } while (choice != 4);

    sc.close();

  }
}
