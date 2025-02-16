/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 6:
// You are tasked with creating a simple library management system in C++. Each book in the library has a unique
// identification number (ID) and a title. You need to implement a class called Book to represent individual books.
// The challenge is to keep track of the total number of books in the library using a static member variable and provide
// methods to access and manipulate this data.
// Solution:
// To solve this problem, you can create a C++ class named Book with the following features:
//  1. Private Data Members:
// o id: An integer to store the unique ID of the book.
// o title: A string to store the title of the book.
// 2. Static Data Member:
// o totalCount: A static integer that keeps track of the total number of books in the library.
// Initialize it to zero.
// 3. Constructors:
// o Create a constructor that takes the book’s ID and title as parameters and assigns them to the
// corresponding data members. In this constructor, increment the totalCount static member
// variable by 1 to reflect the addition of a new book to the library.
// 4. Destructor:
// o Create a destructor that decrements the totalCount static member variable by 1 when a book
// object is destroyed (i.e., removed from the library).
// 5. Static Member Function:
// o Create a static member function called getTotalCount that returns the total number of books
// in the library.

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    static int totalCount;
public:
    Book(int id, string title) {
        this->id = id;
        this->title = title;
        totalCount++;
    }
    ~Book() {
        totalCount--;
    }
    static int getTotalCount() {
        return totalCount;
    }
};

int Book::totalCount = 0;

int main() {
    Book book1(1, "Book 1");
    Book book2(2, "Book 2");
    Book book3(3, "Book 3");

    cout << "Total number of books in the library: " << Book::getTotalCount() << endl;

    return 0;
}
