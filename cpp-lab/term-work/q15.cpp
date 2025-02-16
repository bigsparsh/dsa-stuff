/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 15: Writing Multiple Objects to a Binary File
// Problem Statement:
// Write a C++ program to save multiple objects to a binary file. The program
// should:
// 1. Define a Book class with attributes title, author, and price.
// 2. Allow the user to enter details of multiple books and store them in a
// binary file named books.dat.
// 3. Retrieve and display the details of all books from the binary file.
// Requirements:
// • Use ofstream with ios::binary to write objects in binary format.
// • Use ifstream with ios::binary to read binary data back into objects.
// Example:
// • Input:
// • Title: "The Great Gatsby", Author: "F. Scott Fitzgerald", Price: 10.99
// • Title: "1984", Author: "George Orwell", Price: 8.99
// • Output (in books.dat file):
// • Binary data representing the Book objects

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
  string title;
  string author;
  double price;
};

int main() {
  Book book;
  string title, author;
  double price;
  char choice;

  ofstream file("books.dat", ios::binary | ios::app);

  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  do {
    cout << "Enter title: ";
    getline(cin, title);
    book.title = title;

    cout << "Enter author: ";
    getline(cin, author);
    book.author = author;

    cout << "Enter price: ";
    cin >> price;
    book.price = price;

    file.write((char *)&book, sizeof(book));

    cout << "Do you want to enter another book? (y/n): ";
    cin >> choice;
    cin.ignore();
  } while (choice == 'y');

  file.close();

  ifstream file2("books.dat", ios::binary);

  if (!file2.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  while (file2.read((char *)&book, sizeof(book))) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Price: " << book.price << endl;
    cout << endl;
  }

  file2.close();

  return 0;
}
