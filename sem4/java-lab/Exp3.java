class Exp3 {

  int factorial (int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
  }

  public static void main(String args[]) {
    Exp3 obj = new Exp3();
    int n = 5;

    System.out.println("Factorial of " + n + " is: " + obj.factorial(n));
  }
}
