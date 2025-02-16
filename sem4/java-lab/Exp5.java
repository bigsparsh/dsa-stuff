class Exp5 {

  boolean armstrong (int n) {
    int length = 0, temp = n, sum = 0;
    while (temp != 0) {
      length++;
      temp /= 10;
    }
    temp = n;
    while (temp != 0) {
      sum += Math.pow(temp % 10, length);
      temp /= 10;
    }
    return sum == n;
  }

  public static void main(String args[]) {
    Exp5 obj = new Exp5();
    int n = 153;

    if (obj.armstrong(n)) System.out.println(n + " is an armstrong number");
    else System.out.println(n + " is not an armstrong number");
  }
}
