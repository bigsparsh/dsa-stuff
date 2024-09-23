// 3. Student Report Card:
//    Create a Student class with attributes for the student's name, roll number, and marks in three subjects.
//    Implement methods to calculate the total marks, percentage, and grade based on the percentage.
//    Create multiple Student objects, input their details and generate a report card that displays all the calculated information.

#include <iostream>

class Student {
  private:
    std::string name;
    int rollNum;
    double marks[3];
  public:
    double totalMarks () {
      return marks[0] + marks[1] + marks[2];
    }
    double percentage () {
      return totalMarks() / 3;
    }
    char grade () {
      double per = percentage();
      if (per >= 90) return 'A';
      else if (per >= 80) return 'B';
      else if (per >= 70) return 'C';
      else if (per >= 60) return 'D';
      else if (per >= 50) return 'E';
      else return 'F';
    }
    void setDetails (std::string n, int r, double m1, double m2, double m3) {
      name = n;
      rollNum = r;
      marks[0] = m1;
      marks[1] = m2;
      marks[2] = m3;
    }
};

int main () {

  Student s1, s2;
  std::string name;
  int rollNum;
  double m1, m2, m3;

  std::cout << "Enter the name, roll number and marks of student 1: ";
  std::cin >> name >> rollNum >> m1 >> m2 >> m3;
  s1.setDetails(name, rollNum, m1, m2, m3);

  std::cout << "Enter the name, roll number and marks of student 2: ";
  std::cin >> name >> rollNum >> m1 >> m2 >> m3;
  s2.setDetails(name, rollNum, m1, m2, m3);

  std::cout << "Student 1\nTotal Marks: " << s1.totalMarks() << "\nPercentage: " << s1.percentage() << "\nGrade: " << s1.grade();
  std::cout << "\nStudent 2\nTotal Marks: " << s2.totalMarks() << "\nPercentage: " << s2.percentage() << "\nGrade: " << s2.grade();

  return 0;

}
