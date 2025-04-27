// Write a java program to implement abstract class andabstract method with
// following details:
// Create a abstract Base Class TemperatureData members:
// double temp;
// Method members:
// void setTempData(double) abstact void changeTemp()
//
// Sub Class Fahrenheit (subclass of Temperature) Data members:
// double ctemp;
// method member:
// Override abstract method changeTemp() to convert Fahrenheit temperature into
// degree Celsius by using formula C=5/9*(F-32) and display converted
// temperature
// Sub Class Celsius (subclass of Temperature)
// Data member:
// double ftemp;
// Method member:
// Override abstract method changeTemp() to convert degree Celsius into
// Fahrenheit temperature by using formula F=9/5*c+32 and display converted
// temperature

abstract class Temperature {
    double temp;

    void setTempData(double temp) {
        this.temp = temp;
    }

    abstract void changeTemp();
}

class Fahrenheit extends Temperature {
    double ctemp;

    void changeTemp() {
        ctemp = (5.0 / 9) * (temp - 32);
        System.out.println("Temperature in Celsius: " + ctemp);
    }
}

class Celsius extends Temperature {
    double ftemp;

    void changeTemp() {
        ftemp = (9.0 / 5) * temp + 32;
        System.out.println("Temperature in Fahrenheit: " + ftemp);
    }
}

public class Exp14 {
    public static void main(String[] args) {
        Fahrenheit fahrenheit = new Fahrenheit();
        fahrenheit.setTempData(100);
        fahrenheit.changeTemp();

        Celsius celsius = new Celsius();
        celsius.setTempData(37);
        celsius.changeTemp();
    }
}
