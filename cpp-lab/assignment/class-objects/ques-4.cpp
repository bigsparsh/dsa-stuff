// Library Book Management:
//    Design a Book class with attributes like title, author, ISBN, and availability status.
//    Implement methods to issue a book, return a book, and display the book details.
//    Create a few Book objects and demonstrate issuing and returning books.

#include <iostream>

class Book {
  private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;

  public:
    Book (std::string t, std::string a, std::string i, bool av) : title(t), author(a), ISBN(i), isAvailable(av) {}

    void issue() {
        if (isAvailable) {
            isAvailable = false;
            std::cout << "Book issued successfully." << std::endl;
        } else {
            std::cout << "Book is not available." << std::endl;
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            std::cout << "Book returned successfully." << std::endl;
        } else {
            std::cout << "Book is already available." << std::endl;
        }
    }

    void display() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << ISBN << std::endl;
        std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
    }
};

int main () {

  Book book1("The Alchemist", "Paulo Coelho", "978-0062315007", true);

  book1.display();
  book1.issue();
  book1.display();
  book1.returnBook();
  book1.display();

  return 0;

}
