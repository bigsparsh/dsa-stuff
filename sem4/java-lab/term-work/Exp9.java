// Write a java program to delete vowels from given string using StringBuffer
// class

import java.util.Scanner;

public class Exp9 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the string: ");
    String str = sc.nextLine();
    StringBuffer sb = new StringBuffer(str);
    for (int i = 0; i < sb.length(); i++) {
      char ch = sb.charAt(i);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
          ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        sb.deleteCharAt(i);
        i--;
      }
    }
    System.out.println("Output: " + sb);
    sc.close();
  }
}
