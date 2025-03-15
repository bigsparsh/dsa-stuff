// Program to replace all 0's with 1 in a given integer. Given an integer as an
// input, all the 0's in the number has to be replaced with 1. For example,
// consider the following number Input: 102405 Output: 112415 Input: 56004
// Output: 56114
// Steps to replace all 0's with 1 in a given integer
// • Input the integer from the user.
// • Traverse the integer digit by digit.
// • If a '0' is encountered, replace it by '1'.
// • Print the integer.

import java.util.Scanner;

public class Exp4 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number: ");
    int num = sc.nextInt();
    int result = 0;
    int place = 1;
    while (num > 0) {
      int digit = num % 10;
      if (digit == 0) {
        result += 1 * place;
      } else {
        result += digit * place;
      }
      place *= 10;
      num /= 10;
    }
    System.out.println("Output: " + result);
    sc.close();
  }
}
