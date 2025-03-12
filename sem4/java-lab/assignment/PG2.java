// Write a Java program to get current full date and time.

import java.util.Calendar;

public class PG2 {

  public static void main(String[] args) {
    Calendar cal = Calendar.getInstance();
    System.out.println("Current full date and time:");
    System.out.println(
        cal.get(Calendar.YEAR) + "-" + (cal.get(Calendar.MONTH) + 1) + "-" +
        cal.get(Calendar.DATE) + " " + cal.get(Calendar.HOUR_OF_DAY) + ":" +
        cal.get(Calendar.MINUTE) + ":" + cal.get(Calendar.SECOND) + "." +
        cal.get(Calendar.MILLISECOND));
  }
}
