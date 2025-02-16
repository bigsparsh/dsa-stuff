/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 4: Array of Pointers to Objects
// Objective: Learn how to handle an array of pointers to objects.
// Problem:
// Create a class Student with the following attributes:
// • name (string)
// • grade (float)
// Add a method display() that prints the student's name and grade.
// In main(), create an array of 3 pointers to Student objects. Dynamically allocate memory for each student, set
// their name and grade, and then use the array to call the display() method for each student.
// Requirements:
// • Use an array of pointers to manage multiple objects.
// • Dynamically allocate memory for each object.
// • Access each object through the array of pointers.

#include <iostream>
using namespace std;

class Student {
private:
  string name;
  float grade;
public:
  void setDetails(string n, float g) {
    name = n;
    grade = g;
  }
  void display() {
    cout << "Name: " << name << endl;
    cout << "Grade: " << grade << endl;
  }
};

int main() {
  Student *students[3];
  string name;
  float grade;
  for (int i = 0; i < 3; i++) {
    students[i] = new Student;
    cout << "Enter the name of student " << i+1 << ": ";
    cin >> name;
    cout << "Enter the grade of student " << i+1 << ": ";
    cin >> grade;
    students[i]->setDetails(name, grade);
  }
  for (int i = 0; i < 3; i++) {
    cout << "Student " << i+1 << " details:" << endl;
    students[i]->display();
  }
  for (int i = 0; i < 3; i++) {
    delete students[i];
  }
  return 0;
}
