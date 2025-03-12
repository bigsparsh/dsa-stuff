
package library;

public class Book {
  private String title;
  private String author;
  private String ISBN;
  private boolean isIssued;

  public Book(String title, String author, String ISBN) {
    this.title = title;
    this.author = author;
    this.ISBN = ISBN;
    this.isIssued = false;
  }

  public String getTitle() { return title; }

  public String getAuthor() { return author; }

  public String getISBN() { return ISBN; }

  public boolean isIssued() { return isIssued; }

  public void issue() { isIssued = true; }

  public void returnBook() { isIssued = false; }

  public void display() {
    System.out.println("Title: " + title);
    System.out.println("Author: " + author);
    System.out.println("ISBN: " + ISBN);
    System.out.println("Issued: " + isIssued);
  }
}
