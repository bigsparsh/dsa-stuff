#include <iostream>

int main () {

  std::string name;
  int units; 
  double charge = 0;

  std::cout << "Enter the name of the customer: ";
  std::cin >> name;
  std::cout << "Enter the number of units consumed: ";
  std::cin >> units;

  if (units <= 100)  charge = units * 0.6;
  else if (units <= 300) charge = 100 * 0.6 + (units - 100) * 0.8;
  else charge = 100 * 0.6 + 200 * 0.8 + (units - 300) * 0.9;

  if (charge > 300) {
    charge += 50;;
    charge += charge * 0.15;
  }
  
  std::cout << "Name: " << name << std::endl;
  std::cout << "Units consumed: " << units << std::endl;
  std::cout << "Charge: " << charge << std::endl;


  return 0;
}

