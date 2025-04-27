// Create a class MyCalculator which consists of a single method power (int, int).
// This method takes two integers, n and p, as parameters and finds np. If either
// n or p is negative, then the method must throw an exception which says, "n
// and p should be non- negative".
// Input Format
// Each line of the input contains two integers, n and p. Output Format
// Each line of the output contains the result, if neither of n and p is negative.
// Otherwise, the output contains "n and p should be non- negative".
// Sample Input
// 3 5
// 2 4
// 0 0
// -1 -2
// -1 3
// Sample Output
// 243
// 16
// java.lang.Exception: n and p should not be zero. java.lang.Exception: n or p
// should not be negative. java. lang. Exception: n or p should not be negative.
// Explanation
// In the first two cases, both n and p are positive. So, the power function returns
// the answer correctly.
// In the third case, both n and p are zero. So, the exception, "n and p should not
// be zero.” is printed.
// In the last two cases, at least one out of n and p is negative. So, the exception,
// "n or p should not be negative.” is printed for these two cases.

import java.util.Scanner;

class MyCalculator {
    public long power(int n, int p) throws Exception {
        if (n < 0 || p < 0) {
            throw new Exception("n and p should be non-negative");
        }
        return (long) Math.pow(n, p);
    }
}

public class Exp17 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MyCalculator calculator = new MyCalculator();

        int n = scanner.nextInt();
        int p = scanner.nextInt();
        try {
            long result = calculator.power(n, p);
            System.out.println(result);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
