// Create a class called Student that contains the data members like age, name,
// enroll_no, marks. Create another class called Faculty that contains data
// members like facultyName, facultyCode, salary,deptt, age, experience, gender.
// Create the function display() in both the classes to display the respective
// information. The derived Class Person demonstrates multiple inheritance. The
// program should be able to call both the base classes and displays their
// information. Remove the ambiguity (When we have exactly same variables or
// same methods in both the base classes, which one will becalled?) by proper
// mechanism

#include <iostream>
using namespace std;

class Student {
  int age;
  string name;
  int enroll_no;
  int marks;

public:
  Student(int age, string name, int enroll_no, int marks)
      : age(age), name(name), enroll_no(enroll_no), marks(marks) {}
  void display() {
    cout << "Student Information" << endl;
    cout << "Age: " << age << endl;
    cout << "Name: " << name << endl;
    cout << "Enrollment No: " << enroll_no << endl;
    cout << "Marks: " << marks << endl << endl;
  }
};

class Faculty {
  string facultyName;
  string facultyCode;
  int salary;
  string deptt;
  int age;
  int experience;

public:
  Faculty(string fn, string fc, int sl, string dp, int age, int exp)
      : facultyName(fn), facultyCode(fc), salary(sl), deptt(dp), age(age),
        experience(exp) {}
  void display() {
    cout << "Faculty Information" << endl;
    cout << "Faculty Name: " << facultyName << endl;
    cout << "Faculty Code: " << facultyCode << endl;
    cout << "Salary: " << salary << endl;
    cout << "Department: " << deptt << endl;
    cout << "Age: " << age << endl;
    cout << "Experience: " << experience << endl << endl;
  }
};

class Person : public Student, public Faculty {
public:
  Person(int sa, string name, int enroll_no, int marks, string facultyName,
         string facultyCode, int salary, string deptt, int pa, int experience)
      : Student(sa, name, enroll_no, marks),
        Faculty(facultyName, facultyCode, salary, deptt, pa, experience) {}
};

int main() {
  Person p(20, "John Doe", 12345, 90, "Dr. Jane Doe", "FAC123", 100000,
           "Computer Science", 40, 15);
  p.Student::display();
  p.Faculty::display();
  return 0;
}
