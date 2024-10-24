#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string *author;
    string *title;
    double *price;
    int *pages;

public:
    Book (string a, string t, double p, int pa) : author(new string(a)), title(new string(t)), price(new double(p)), pages(new int(pa)) {}
    Book (Book &obj) {
      author = new string(*obj.author);
      title = new string(*obj.title);
      price = new double(*obj.price);
      pages = new int(*obj.pages);
    }

    void setAuthor (string auth) {
      *author = auth;
    }

    void display () {
      cout << "Author: " << *author << endl;
      cout << "Title: " << *title << endl;
      cout << "Price: $" << *price << endl;
      cout << "Pages: " << *pages << endl;
    }
};

int main () {
  Book b1("George RR Martin", "Fire and Blood", 500.45, 711);
  b1.display();
  Book b2 = b1;
  b1.setAuthor("Stephen King");
  b2.display();
  
  return 0;
}
