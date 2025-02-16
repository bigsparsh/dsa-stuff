/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 14: Saving and Retrieving Product Information
// Problem Statement:
// Write a C++ program that saves product information to a file and allows retrieval. The program should:
// 1. Define a Product class with attributes like id, name, and price.
// 2. Write the product objects to a file named products.dat.
// 3. After saving, read the data from the file and display all products using a function.
// Requirements:
// • Use ofstream for writing to the file and ifstream for reading.
// • Make sure to handle file not found scenarios.
// • Use proper formatting to store and retrieve data.
// Example:
// • Input:
// • ID: 1, Name: Laptop, Price: 999.99 
// • ID: 2, Name: Phone, Price: 499.99
// • Output (in file):
// • 1 Laptop 999.99
// • 2 Phone 499.99

#include <iostream>
#include <fstream>
using namespace std;

class Product {
public:
  int id;
  string name;
  double price;
};

void displayProducts() {
  Product product;
  ifstream file("products.dat", ios::in);

  if (!file) {
    cout << "Error opening file" << endl;
    return;
  }

  while (file >> product.id >> product.name >> product.price) {
    cout << "ID: " << product.id << ", Name: " << product.name << ", Price: " << product.price << endl;
  }

  file.close();
}

int main() {
  Product product;
  ofstream file("products.dat", ios::out);

  if (!file) {
    cout << "Error creating file" << endl;
    return 1;
  }

  cout << "Enter product ID: ";
  cin >> product.id;
  cout << "Enter product name: ";
  cin >> product.name;
  cout << "Enter product price: ";
  cin >> product.price;

  file << product.id << " " << product.name << " " << product.price << endl;
  file.close();

  displayProducts();

  return 0;
}
