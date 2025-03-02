// WAP in java to input 2 D array and print position (row and column) of all odd
// and even numbers.

import java.util.Scanner;

class Exp11 {
  public static void main(String args[]) {
    int rows, cols;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter number of rows: ");
    rows = sc.nextInt();
    System.out.println("Enter number of columns: ");
    cols = sc.nextInt();

    int arr[][] = new int[rows][cols];
    System.out.println("Enter elements of array: ");
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        arr[i][j] = sc.nextInt();
      }
    }

    System.out.println("Position of odd and even numbers: ");
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (arr[i][j] % 2 == 0) {
          System.out.println("Even at position (" + i + ", " + j + ")");
        } else {
          System.out.println("Odd at position (" + i + ", " + j + ")");
        }
      }
    }
  }
}
