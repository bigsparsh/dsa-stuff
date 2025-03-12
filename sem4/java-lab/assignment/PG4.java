// Write a Java program to calculate your age.

import java.util.Scanner;

public class PG4 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("Enter your birth year: ");
    int birthYear = input.nextInt();
    System.out.println("Enter the current year: ");
    int currentYear = input.nextInt();
    int age = currentYear - birthYear;
    System.out.println("Your age is: " + age);
    input.close();
  }
}
