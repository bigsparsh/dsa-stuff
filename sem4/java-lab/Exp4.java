class Exp4 {
  boolean prime(int n) {
    int i;
    for (i = 2; i < n / 2; i++) 
      if (n % i == 0) return false;
    return true;
  }

  public static void main(String args[]) {
    Exp4 obj = new Exp4();
    int n = 7;

    if (obj.prime(n)) System.out.println(n + " is a prime number");
    else System.out.println(n + " is not a prime number");
  }
}
