/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// 11. Employee Management System
// • Objective: Create a base class Employee with a virtual function getSalary(). Derive classes
// Manager and Developer from Employee, and implement getSalary() for each type of employee.
// • Scenario:
// o Your company needs a system to manage employee information and calculate their salary based
// on job roles. Managers and Developers have different salary structures.
// o The base class Employee will have a virtual function getSalary(), which is overridden by
// Manager and Developer to calculate salary based on different factors.
// • Instructions:
// o Define an abstract base class Employee with a pure virtual function getSalary().
// o Create a derived class Manager that calculates salary based on base salary plus bonuses.
// o Create a derived class Developer that calculates salary based on base salary and experience.
// o In the main function, create objects of Manager and Developer, and use polymorphism to
// calculate and display their salaries.

#include <iostream>
using namespace std;

class Employee {
public:
  virtual void getSalary() = 0;
};

class Manager : public Employee {
public:
  void getSalary() { cout << "Manager salary: $100,000" << endl; }
};

class Developer : public Employee {
public:
  void getSalary() { cout << "Developer salary: $80,000" << endl; }
};

int main() {
  Employee *employee;
  Manager manager;
  Developer developer;

  employee = &manager;
  employee->getSalary();

  employee = &developer;
  employee->getSalary();

  return 0;
}
