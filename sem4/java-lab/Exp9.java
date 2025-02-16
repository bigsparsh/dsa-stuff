import java.util.Scanner;

class Exp9 {
  
    public static void main(String args[]) {
  
      Scanner sc = new Scanner(System.in);
      
      int choice;
      
      do {
        System.out.println("1. Enter student scores");
        System.out.println("2. Exit");
        System.out.print("Enter your choice: ");
        choice = sc.nextInt();
  
        switch (choice) {
          case 1:
            System.out.print("Enter student name: ");
            String name = sc.next();
            System.out.print("Enter marks in subject 1: ");
            int sub1 = sc.nextInt();
            System.out.print("Enter marks in subject 2: ");
            int sub2 = sc.nextInt();
            System.out.print("Enter marks in subject 3: ");
            int sub3 = sc.nextInt();
            int total = sub1 + sub2 + sub3;
            double avg = total / 3;
            String grade;
            if (avg >= 90) grade = "A";
            else if (avg >= 80) grade = "B";
            else if (avg >= 70) grade = "C";
            else if (avg >= 60) grade = "D";
            else grade = "F";
            System.out.println("Total marks: " + total);
            System.out.println("Average percentage: " + avg);
            System.out.println("Grade: " + grade);
            break;
          case 2:
            break;
          default:
            System.out.println("Invalid choice");
        }
      } while (choice != 2);
  
    }
}
