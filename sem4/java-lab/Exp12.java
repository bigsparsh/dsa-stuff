// Library Management System with Static Nested Class Using Array of Objects:
// Objective:
// •	Implement a Library system where the outer class Library contains a
// static nested class Book. •	The Library will use an array to store multiple
// Book objects. •	Operations like adding books, borrowing a book,
// returning a book, and displaying available books will be performed.

import java.util.Scanner;

class Library {
  static class Book {
    String title;
    String author;
    boolean isAvailable;

    Book(String title, String author) {
      this.title = title;
      this.author = author;
      this.isAvailable = true;
    }
  }

  public static void main(String args[]) {
    int n;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter number of books: ");
    n = sc.nextInt();

    Book books[] = new Book[n];
    for (int i = 0; i < n; i++) {
      System.out.println("Enter title of book " + (i + 1) + ": ");
      String title = sc.next();
      System.out.println("Enter author of book " + (i + 1) + ": ");
      String author = sc.next();
      books[i] = new Book(title, author);
    }

    while (true) {
      System.out.println("1. Add book");
      System.out.println("2. Borrow book");
      System.out.println("3. Return book");
      System.out.println("4. Display available books");
      System.out.println("5. Exit");
      System.out.println("Enter choice: ");
      int choice = sc.nextInt();

      switch (choice) {
      case 1:
        System.out.println("Enter title of book: ");
        String title = sc.next();
        System.out.println("Enter author of book: ");
        String author = sc.next();
        Book newBook = new Book(title, author);
        Book newBooks[] = new Book[n + 1];
        for (int i = 0; i < n; i++) {
          newBooks[i] = books[i];
        }
        newBooks[n] = newBook;
        books = newBooks;
        n++;
        break;
      case 2:
        System.out.println("Enter title of book to borrow: ");
        title = sc.next();
        for (int i = 0; i < n; i++) {
          if (books[i].title.equals(title)) {
            if (books[i].isAvailable) {
              books[i].isAvailable = false;
              System.out.println("Book borrowed successfully.");
            } else {
              System.out.println("Book is not available.");
            }
            break;
          }
        }
        break;
      case 3:
        System.out.println("Enter title of book to return: ");
        title = sc.next();
        for (int i = 0; i < n; i++) {
          if (books[i].title.equals(title)) {
            if (!books[i].isAvailable) {
              books[i].isAvailable = true;
              System.out.println("Book returned successfully.");
            } else {
              System.out.println("Book is already available.");
            }
            break;
          }
        }
        break;
      case 4:
        System.out.println("Available books: ");
        for (int i = 0; i < n; i++) {
          if (books[i].isAvailable) {
            System.out.println("Title: " + books[i].title +
                               ", Author: " + books[i].author);
          }
        }
        break;
      case 5:
        System.exit(0);

      default:
        System.out.println("Invalid choice.");
      }
    }
  }
}
