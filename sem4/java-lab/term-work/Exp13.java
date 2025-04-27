// Method overriding (Runtime Polymorphism), Abstract class and Abstract
// method, Inheritance, interfaces:
// Write a java program to calculate the area of a rectangle, a square and a circle.
// Create an abstract class 'Shape' with three abstract methods namely
// rectangleArea() taking two parameters, squareArea() and circleArea() taking
// one parameter each.
// Now create another class ‘Area’ containing all the three methods
// rectangleArea(), squareArea() and circleArea() for printing the area of
// rectangle, square and circle respectively. Create an object of class Area and call
// all the three methods.
// (Use Runtime Polymorphism)

abstract class Shape {
    abstract void rectangleArea(int length, int breadth);
    abstract void squareArea(int side);
    abstract void circleArea(int radius);
}

class Area extends Shape {
    void rectangleArea(int length, int breadth) {
        System.out.println("Area of Rectangle: " + (length * breadth));
    }

    void squareArea(int side) {
        System.out.println("Area of Square: " + (side * side));
    }

    void circleArea(int radius) {
        System.out.println("Area of Circle: " + (Math.PI * radius * radius));
    }
}

public class Exp13 {
    public static void main(String[] args) {
        Area area = new Area();
        area.rectangleArea(5, 10);
        area.squareArea(4);
        area.circleArea(3);
    }
}
