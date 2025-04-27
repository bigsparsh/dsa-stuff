// Write a java program to create an interface that consists of a method to display
// volume () as an abstract method and redefine this method in the derived 
// classes to suit their requirements.
// Create classes called Cone, Hemisphere and Cylinder that implements the
// interface. Using these three classes, design a program that will accept
// dimensions of a cone, cylinder and hemisphere interactively and display the
// volumes.
// Volume of cone = (1/3)πr2h Volume of hemisphere = (2/3)πr3Volume of
// cylinder = πr2h

import java.util.Scanner;

interface Volume {
    double calculateVolume();
}

class Cone implements Volume {
    private double radius;
    private double height;

    public Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public double calculateVolume() {
        return (1.0 / 3.0) * Math.PI * Math.pow(radius, 2) * height;
    }
}

class Hemisphere implements Volume {
    private double radius;

    public Hemisphere(double radius) {
        this.radius = radius;
    }

    public double calculateVolume() {
        return (2.0 / 3.0) * Math.PI * Math.pow(radius, 3);
    }
}

class Cylinder implements Volume {
    private double radius;
    private double height;

    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public double calculateVolume() {
        return Math.PI * Math.pow(radius, 2) * height;
    }
}

public class Exp15 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter radius and height of Cone: ");
        double coneRadius = scanner.nextDouble();
        double coneHeight = scanner.nextDouble();
        Cone cone = new Cone(coneRadius, coneHeight);
        System.out.println("Volume of Cone: " + cone.calculateVolume());

        System.out.print("Enter radius of Hemisphere: ");
        double hemisphereRadius = scanner.nextDouble();
        Hemisphere hemisphere = new Hemisphere(hemisphereRadius);
        System.out.println("Volume of Hemisphere: " + hemisphere.calculateVolume());

        System.out.print("Enter radius and height of Cylinder: ");
        double cylinderRadius = scanner.nextDouble();
        double cylinderHeight = scanner.nextDouble();
        Cylinder cylinder = new Cylinder(cylinderRadius, cylinderHeight);
        System.out.println("Volume of Cylinder: " + cylinder.calculateVolume());

        scanner.close();
    }
}
