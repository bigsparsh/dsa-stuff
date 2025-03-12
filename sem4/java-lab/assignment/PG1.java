// 1: Write a Java program to find the number of days in a month.
// Test Data
// Input a month number: 2
// Input a year: 2016
// Expected Output :
// February 2016 has 29 days

import java.util.Scanner;

public class PG1 {

  static void find_days_in_month(int month, int year) {
    String month_name = "";
    int days = 0;
    switch (month) {
    case 1:
      month_name = "January";
      days = 31;
      break;
    case 2:
      month_name = "February";
      if (year % 4 == 0) {
        days = 29;
      } else {
        days = 28;
      }
      break;
    case 3:
      month_name = "March";
      days = 31;
      break;
    case 4:
      month_name = "April";
      days = 30;
      break;
    case 5:
      month_name = "May";
      days = 31;
      break;
    case 6:
      month_name = "June";
      days = 30;
      break;
    case 7:
      month_name = "July";
      days = 31;
      break;
    case 8:
      month_name = "August";
      days = 31;
      break;
    case 9:
      month_name = "September";
      days = 30;
      break;
    case 10:
      month_name = "October";
      days = 31;
      break;
    case 11:
      month_name = "November";
      days = 30;
      break;
    case 12:
      month_name = "December";
      days = 31;
      break;
    default:
      System.out.println("Invalid month number");
      return;
    }
    System.out.println(month_name + " " + year + " has " + days + " days");
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the month number: ");
    int month = sc.nextInt();
    System.out.println("Enter the year: ");
    int year = sc.nextInt();
    sc.close();
    find_days_in_month(month, year);
  }
}
