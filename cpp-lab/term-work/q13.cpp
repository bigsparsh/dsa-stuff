/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 13: Saving Student Records to a File
// Problem Statement:
// Write a C++ program to save student records to a file. The program should:
// 1. Define a Student class with attributes such as name, age, and grade.
// 2. Accept user input to create multiple student objects.
// 3. Write these objects to a file named students.dat.
// 4. Ensure that the data is written in a structured format (e.g., using binary or text format).
// Requirements:
// • Implement file handling using ofstream.
// • Use the << operator for output to write data to the file.
// Example:
// • Input:
// • Name: John, Age: 20, Grade: A
// • Name: Jane, Age: 22, Grade: B
// • Output (in students.dat):
// • John 20 A
// • Jane 22 B

#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
  string name;
  int age;
  char grade;
};

int main() {
  Student student;
  ofstream file("students.dat", ios::out);

  if (!file) {
    cout << "Error creating file" << endl;
    return 1;
  }

  cout << "Enter student name: ";
  cin >> student.name;
  cout << "Enter student age: ";
  cin >> student.age;
  cout << "Enter student grade: ";
  cin >> student.grade;

  file << student.name << " " << student.age << " " << student.grade << endl;
  file.close();

  return 0;
}
