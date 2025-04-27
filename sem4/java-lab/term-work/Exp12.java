// Method overloading (Compile time Polymorphism):
// Write a Java program to create a class called
// ArrayDemo and overload arrayFunc() function.
// void arrayFunc(int [], int) To find all pairs of elements in an
// Array whose sum is equal to a givennumber :
// Array numbers= [4, 6, 5, -10, 8, 5, 20], target=10
// Output :
// Pairs of elements whose sum is 10 are :4 + 6 = 10
// 5 + 5 = 10
// -10 + 20 = 10
// void arrayFunc(int A[], int p, int B[], int q) Giventwo sorted arrays A
// and B of size p and q, Overload method arrayFunc() to merge elements of
// A with B bymaintaining the sorted order i.e. fill A with first p smallest
// elements and fill B with remaining elements.
// Example:
// Input :
// 2
// int[] A = { 1, 5, 6, 7, 8, 10 }
// int[] B = { 2, 4, 9 }
// Output:
// Sorted Arrays:
// A: [1, 2, 4, 5, 6, 7]
// B: [8, 9, 10]
// (Use Compile time Polymorphism MethodOverloading)

import java.util.Scanner;

class ArrayDemo {
    void arrayFunc(int[] numbers, int target) {
        System.out.println("Pairs of elements whose sum is " + target + " are:");
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target) {
                    System.out.println(numbers[i] + " + " + numbers[j] + " = " + target);
                }
            }
        }
    }

    void arrayFunc(int[] A, int p, int[] B, int q) {
        int[] merged = new int[p + q];
        int i = 0, j = 0, k = 0;

        while (i < p && j < q) {
            if (A[i] < B[j]) {
                merged[k++] = A[i++];
            } else {
                merged[k++] = B[j++];
            }
        }

        while (i < p) {
            merged[k++] = A[i++];
        }

        while (j < q) {
            merged[k++] = B[j++];
        }

        System.out.println("Sorted Arrays:");
        System.out.print("A: ");
        for (int m = 0; m < p; m++) {
            System.out.print(merged[m] + " ");
        }
        System.out.println();
        System.out.print("B: ");
        for (int n = p; n < p + q; n++) {
            System.out.print(merged[n] + " ");
        }
    }
}
  
class Exp12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayDemo ad = new ArrayDemo();

        int[] numbers = {4, 6, 5, -10, 8, 5, 20};
        int target = 10;
        ad.arrayFunc(numbers, target);

        int[] A = {1, 5, 6, 7, 8, 10};
        int[] B = {2, 4, 9};
        ad.arrayFunc(A, A.length, B, B.length);
    }
}
