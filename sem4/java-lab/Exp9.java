// Q3 Objective:
//     • Use the Scanner class to take student scores.
//     • Calculate and display the final grade based on scores.
// Scenario:
// A school needs a program where students input their scores in 3 subjects, and
// the system calculates: ✅ Total marks ✅ Average percentage ✅ Grade (A, B,
// C, D, or F) Create a class having functions to accept multiple students’ data
// and performing above given operations.

import java.util.Scanner;

class Exp9 {

  String name;
  int marks[] = new int[3];
  int total = 0;
  float avg = 0;
  char grade;

  void getMarks() {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter name: ");
    name = sc.next();
    System.out.print("Enter marks in 3 subjects: ");
    for (int i = 0; i < 3; i++) {
      marks[i] = sc.nextInt();
      total += marks[i];
    }
    avg = total / 3;
    if (avg >= 90) {
      grade = 'A';
    } else if (avg >= 80) {
      grade = 'B';
    } else if (avg >= 70) {
      grade = 'C';
    } else if (avg >= 60) {
      grade = 'D';
    } else {
      grade = 'F';
    }
  }

  void display() {
    System.out.println("Name: " + name);
    System.out.println("Total marks: " + total);
    System.out.println("Average percentage: " + avg);
    System.out.println("Grade: " + grade);
  }

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    int n;

    System.out.print("Enter number of students: ");
    n = sc.nextInt();

    Exp9 obj[] = new Exp9[n];

    for (int i = 0; i < n; i++) {
      obj[i] = new Exp9();
      obj[i].getMarks();
    }

    for (int i = 0; i < n; i++) {
      obj[i].display();
    }
  }
}
