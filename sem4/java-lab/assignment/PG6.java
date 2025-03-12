// Create a package library with a class Book having attributes like title,
// author, ISBN. Implement methods to issue and return books.Write a program to
// demonstrate book transactions.

import library.Book;

public class PG6 {
  public static void main(String[] args) {
    Book book1 =
        new Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    Book book2 =
        new Book("To Kill a Mockingbird", "Harper Lee", "9780061120084");

    book1.issue();
    book2.issue();
    book1.returnBook();
    book2.issue();

    book1.display();
    book2.display();
  }
}
