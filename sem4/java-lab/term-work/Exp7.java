// Program to find the saddle point coordinates in a given matrix. A saddle
// point is an element of the matrix,which is the minimum element in its row and
// the maximum in its column. For example, consider the matrix given belowMat
// [3][3] 1 2 3 4 5 6 7 8 9 Here, 7 is the saddle point because it is the
// minimum element in its row and maximum element in its column. Steps to find
// the saddle point coordinates in a givenmatrix.
// 1. Input the matrix from the user.
// 2. Use two loops, one for traversing the row andthe other for
// traversing the column.
// 3. If the current element is the minimum element inits row and
// maximum element in its column, then return its coordinates.
// Else, continue traversing

import java.util.Scanner;

public class Exp7 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of rows: ");
    int m = sc.nextInt();
    System.out.println("Enter the number of columns: ");
    int n = sc.nextInt();
    int[][] mat = new int[m][n];
    System.out.println("Enter the elements: ");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = sc.nextInt();
      }
    }
    for (int i = 0; i < m; i++) {
      int min = mat[i][0];
      int col = 0;
      for (int j = 1; j < n; j++) {
        if (mat[i][j] < min) {
          min = mat[i][j];
          col = j;
        }
      }
      int k;
      for (k = 0; k < m; k++) {
        if (min < mat[k][col]) {
          break;
        }
      }
      if (k == m) {
        System.out.println("Saddle point is: " + min);
        break;
      }
    }
    sc.close();
  }
}
