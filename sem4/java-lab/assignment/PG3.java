// Write a Java program to get a day of the week of a specific date

import java.util.Calendar;
import java.util.Scanner;

public class PG3 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter a date in the format yyyy-mm-dd:");
    String date = sc.nextLine();
    String[] date_parts = date.split("-");
    int year = Integer.parseInt(date_parts[0]);
    int month = Integer.parseInt(date_parts[1]);
    int day = Integer.parseInt(date_parts[2]);
    Calendar cal = Calendar.getInstance();
    cal.set(year, month - 1, day);
    System.out.println("Day of the week for " + date + " is " +
                       cal.get(Calendar.DAY_OF_WEEK));
    sc.close();
  }
}
