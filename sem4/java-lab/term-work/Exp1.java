// Taking input from Command line and convert objects into primitivedata
// type:
// Write a java program to take input as a command line argument. Your name,
// course, universityrollno and semester. Display the information.
// Name: UniversityRollNo:Course:
// 2
// 50
// 2 1
// 25
// 0
// 25
// 0 3
// 2

import java.util.Scanner;

public class Exp1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter name: ");
    String name = sc.next();
    System.out.println("Enter course: ");
    String course = sc.next();
    System.out.println("Enter university roll number: ");
    int universityRollNo = sc.nextInt();
    System.out.println("Enter semester: ");
    int semester = sc.nextInt();
    System.out.println("Name: " + name +
                       "\nUniversity Roll No: " + universityRollNo +
                       "\nCourse: " + course + "\nSemester: " + semester);
  }
}
