/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Problem 2: Hospital Patient Records
// Scenario:
// A hospital maintains records of patients. Each patient has a name, age, and a unique patient ID. The hospital uses a
// dynamic system where patient records are created and deleted based on admission and discharge.
// Task:
// Create a Patient class with the following attributes:
// • name (string)
// • age (int)
// • patientID (int)
// In main(), create a pointer to a Patient object and dynamically allocate memory for the patient when a new
// patient is admitted. Once admitted, allow the user to input the patient's details. After the details are entered, display
// the patient's information using the pointer.
// Requirements:
// • Dynamically allocate memory for a new patient.
// • Use a pointer to manage and access patient details.
// • Ensure proper deallocation of memory when the patient is discharged (use delete).

#include <iostream>
using namespace std;

class Patient {
private:
  string name;
  int age, patient_id;
public:
  Patient (int pi, string nm, int ag) : patient_id(pi), name(nm), age(ag) {}
  void displayDetails () {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Patient ID: " << patient_id << endl;
  }
};

int main () {

  Patient *p1;

  string name;
  int age, patient_id;
  cout << "Enter the name of the patient: ";
  cin >> name;
  cout << "Enter the age of the patient: ";
  cin >> age;
  cout << "Enter the patient ID: ";
  cin >> patient_id;

  p1 = new Patient(patient_id, name, age);

  p1->displayDetails();

  delete p1;

  return 0;
}
