#include <iostream>
using namespace std;

class Publication {
  string title;
};

class Book : public Publication {
  int accession_no;

public:
  Book(int an) : accession_no(an) {}
  void showInfo() {
    cout << "The Accession number of the Book: " << accession_no << endl;
  }
};

class Magazine : public Publication {
  int volume_no;

public:
  Magazine(int vn) : volume_no(vn) {}
  void showInfo() {
    cout << "The Volume number of the magazine: " << volume_no << endl;
  }
};

class Journal : public Book, public Magazine {
public:
  Journal(int an, int vn) : Book(an), Magazine(vn) {}
  void showInfo() {
    Book::showInfo();
    Magazine::showInfo();
  }
};

int main() {
  Journal jr(1000, 20);
  jr.showInfo();

  return 0;
}
