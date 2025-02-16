/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Problem 1: Library Book Management
// Scenario:
// You are developing a system for managing library books. Each book has a title, an author, and a unique book ID.
// The library wants to dynamically manage books when they are checked in and out.
// Task:
// Create a Book class with the following attributes:
// • title (string)
// • author (string)
// • bookID (int)
// Implement a method displayDetails() to show the book's information. In main(), dynamically allocate
// memory for 3 Book objects using pointers and allow the user to enter the details for each book. Once the details are
// entered, use the pointers to display the information for all books.
// Requirements:
// • Use dynamic memory allocation to create books at runtime.
// • Store the books using pointers and access their attributes and methods through the pointers.

#include <iostream>
using namespace std;

class Book {
private:
  string title, author;
  int book_id;
public:
  Book (int bi, string tt, string at) : book_id(bi), title(tt), author(at) {}
  void displayDetails () {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Book ID: " << book_id << endl;
  }
};

int main () {

  Book *b1, *b2, *b3;

  for (int i = 0; i < 3; i++) {
    string title, author;
    int book_id;
    cout << "Enter the title of the book: ";
    cin >> title;
    cout << "Enter the author of the book: ";
    cin >> author;
    cout << "Enter the book ID: ";
    cin >> book_id;
    if (i == 0) {
      b1 = new Book(book_id, title, author);
    } else if (i == 1) {
      b2 = new Book(book_id, title, author);
    } else {
      b3 = new Book(book_id, title, author);
    }
  }

  b1->displayDetails();
  b2->displayDetails();
  b3->displayDetails();

  delete b1;
  delete b2;
  delete b3;

  return 0;

}
