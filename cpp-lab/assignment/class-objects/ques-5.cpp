// Employee Payroll System:
//    Create an Employee class that contains attributes like employee ID, name, designation, and salary.
//    Implement methods to calculate the annual salary, apply a bonus, and display the employee details.
//    Instantiate multiple Employee objects, and use the methods to manage their payroll information.

#include <iostream>

class Employee {
  private:
    int employeeID;
    std::string name;
    std::string designation;
    double salary;

  public:
    Employee (int id, std::string n, std::string d, double s) : employeeID(id), name(n), designation(d), salary(s) {}

    double annualSalary() {
        return salary * 12;
    }

    void applyBonus(double bonus) {
        salary += bonus;
    }

    void display() {
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Designation: " << designation << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }
};

int main () {

  Employee emp1(1, "John Doe", "Software Engineer", 50000.0);

  emp1.display();
  std::cout << "Annual Salary: " << emp1.annualSalary() << std::endl;
  emp1.applyBonus(5000.0);
  emp1.display();

  return 0;

}

