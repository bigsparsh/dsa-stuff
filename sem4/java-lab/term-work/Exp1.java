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

class Exp1 {
  public static void main (String args[]) {
    System.out.println("Name: " + args[0]);
    System.out.println("University Roll No: " + args[1]);
    System.out.println("Course: " + args[2]);
    System.out.println("Semester: " + args[3]);
  }
}
