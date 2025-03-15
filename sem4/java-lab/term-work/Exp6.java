// The problem to rearrange positive and negative numbers in an array .
// Method: This approach moves all negative numbers to the beginning and
// positive numbers to the end butchanges the order of appearance of the
// elements of the array.
// Steps:
// 1. Declare an array and input the array elements.
// 2. Start traversing the array and if the current element is negative,
// swap the current elementwith the first positive element and
// continue traversing until all the elements have been encountered.
// 3. Print the rearranged array.
// Test case:
// • Input: 1 -1 2 -2 3 -3
//  Output: -1 -2 -3 1 3 2

import java.util.Scanner;

public class Exp6 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of elements: ");
    int n = sc.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter the elements: ");
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] < 0) {
        if (i != j) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
        j++;
      }
    }
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    sc.close();
  }
}
