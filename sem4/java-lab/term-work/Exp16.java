// Write a java program to accept and print the employee details during runtime.
// The details will include employee id, name, dept_ Id. The program should
// raise an exception if user inputs incomplete or incorrect data. The entered
// value should meet the following conditions:
// a. First Letter of employee name should be in capital letter.
// b. Employee id should be between 2001 and 5001
// c. Department id should be an integer between 1 and 5.
// If the above conditions are not met, then the application should raise specific
// exception else should complete normal execution.

import java.util.Scanner;
import java.util.regex.Pattern;

class EmployeeException extends Exception {
    public EmployeeException(String message) {
        super(message);
    }
}

class Employee {
    private int id;
    private String name;
    private int deptId;

    public Employee(int id, String name, int deptId) throws EmployeeException {
        if (id < 2001 || id > 5001) {
            throw new EmployeeException("Employee ID must be between 2001 and 5001.");
        }
        if (!Pattern.matches("[A-Z][a-z]*", name)) {
            throw new EmployeeException("Employee name must start with a capital letter.");
        }
        if (deptId < 1 || deptId > 5) {
            throw new EmployeeException("Department ID must be between 1 and 5.");
        }
        this.id = id;
        this.name = name;
        this.deptId = deptId;
    }
  
    public void display() {
        System.out.println("Employee ID: " + id);
        System.out.println("Employee Name: " + name);
        System.out.println("Department ID: " + deptId);
    }
}

public class Exp16 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter Employee ID (2001-5001): ");
            int id = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            System.out.print("Enter Employee Name (First letter capital): ");
            String name = scanner.nextLine();
            System.out.print("Enter Department ID (1-5): ");
            int deptId = scanner.nextInt();

            Employee employee = new Employee(id, name, deptId);
            employee.display();
        } catch (EmployeeException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Invalid input. Please try again.");
        } finally {
            scanner.close();
        }
    }
}
