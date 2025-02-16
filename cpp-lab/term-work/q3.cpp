/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Problem 3: Employee Shift Management
// Scenario:
// A company manages its employees and their shifts dynamically. Each employee has a name, an employee ID, and a
// shift duration (in hours). The company wants to dynamically allocate employee records based on the number of
// employees in each shift.
// Task:
// Create an employee class with the following attributes:
// • name (string)
// • employeeID (int)
// • shiftDuration (int)
// In main(), dynamically allocate memory for an array of Employee objects using pointers. Let the user specify
// the number of employees in the shift and enter details for each employee. Finally, display the shift details of all
// employees.
// Requirements:
// • Dynamically allocate memory for multiple employees based on user input.
// • Use pointers to store and access employee data.
// • Handle memory cleanup using delete[] after the employee shift ends.

#include <iostream>
using namespace std;

class Employee {
private:
  string name;
  int employeeID, shiftDuration;
public:
  void setDetails (string n, int ei, int sd) {
    name = n;
    employeeID = ei;
    shiftDuration = sd;
  }
  void display() {
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Shift Duration: " << shiftDuration << " hours" << endl;
  }
};

int main() {
  int n;
  cout << "Enter the number of employees: ";
  cin >> n;
  Employee *emp = new Employee[n];
  string name;
  int employeeID, shiftDuration;
  for (int i = 0; i < n; i++) {
    cout << "Enter the name of employee " << i+1 << ": ";
    cin >> name;
    cout << "Enter the employee ID of employee " << i+1 << ": ";
    cin >> employeeID;
    cout << "Enter the shift duration of employee " << i+1 << ": ";
    cin >> shiftDuration;
    emp[i].setDetails(name, employeeID, shiftDuration);
  }
  for (int i = 0; i < n; i++) {
    cout << "Employee " << i+1 << " details:" << endl;
    emp[i].display();
  }
  delete[] emp;
  return 0;
}
