class Exp6 {
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            System.out.println("Error! Division by zero.");
            return Double.NaN;
        }
        return a / b;
    }

    double sin(double angle) {
        return Math.sin(Math.toRadians(angle));
    }

    double cos(double angle) {
        return Math.cos(Math.toRadians(angle));
    }

    double tan(double angle) {
        return Math.tan(Math.toRadians(angle));
    }

    public static void main(String[] args) {
      int a, b;
      a = 10;
      b = 20;
      
      Exp6 obj = new Exp6();
      System.out.println("Sum of a and b is: " + obj.add(a, b));
      System.out.println("Difference of a and b is: " + obj.subtract(a, b));
      System.out.println("Product of a and b is: " + obj.multiply(a, b));
      System.out.println("Quotient of a and b is: " + obj.divide(a, b));
      System.out.println("Sine of 30 degrees is: " + obj.sin(30));
      System.out.println("Cosine of 30 degrees is: " + obj.cos(30));
      System.out.println("Tangent of 30 degrees is: " + obj.tan(30));
      
    }
}
