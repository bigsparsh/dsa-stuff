// String Handling in Java (using String and StringBuffer class):
// Program to find all the patterns of 0(1+)0 in the given string. Given a
// string containing 0's and 1's, find the total number of 0(1+)0 patterns in
// the string and output it. 0(1+)0 - There should be at least one '1' between
// the two 0's. For example, consider the following string.
// Input: 01101111010
// Output: 3
// Explanation: 01101111010 - count = 1

import java.util.Scanner;

public class Exp8 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the string: ");
    String input = sc.nextLine();
    int count = countPatterns(input);
    System.out.println("Input: " + input);
    System.out.println("Output: " + count);
  }

  public static int countPatterns(String str) {
    int count = 0;
    int i = 0;

    while (i < str.length() - 2) {
      if (str.charAt(i) == '0') {
        int j = i + 1;
        boolean foundOne = false;

        while (j < str.length() && str.charAt(j) == '1') {
          foundOne = true;
          j++;
        }

        if (foundOne && j < str.length() && str.charAt(j) == '0') {
          count++;
          i = j;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    return count;
  }
}
