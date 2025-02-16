/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 5: Pointer to Object and Deep Copy
// Objective: Understand deep copying with pointers to objects.
// Problem:
// Create a class Box with the following attributes:
// • length (int)
// • width (int)
// • height (int)
// • A dynamically allocated array content to store items (represented as
// integers). Implement a copy constructor to perform a deep copy. In main(),
// create two pointers to Box objects. Initialize the first object using one
// pointer and make a deep copy of it using the second pointer. Modify the
// contents of the second box and verify that the first box remains unchanged.
// Requirements:
// • Implement deep copy using a copy constructor.
// • Use pointers to allocate memory for the objects and their content.
// • Demonstrate the difference between shallow and deep copy by modifying one
// object and ensuring the other remains unaffected

#include <iostream>
using namespace std;

class Box {
private:
  int length, width, height;
  int *content;

public:
  Box(int l, int w, int h) {
    length = l;
    width = w;
    height = h;
    content = new int[length * width * height];
  }
  Box(const Box &b) {
    length = b.length;
    width = b.width;
    height = b.height;
    content = new int[length * width * height];
    for (int i = 0; i < length * width * height; i++) {
      content[i] = b.content[i];
    }
  }
  void setContents(int *c) {
    for (int i = 0; i < length * width * height; i++) {
      content[i] = c[i];
    }
  }
  void display() {
    cout << "Box dimensions: " << length << "x" << width << "x" << height
         << endl;
    cout << "Contents: ";
    for (int i = 0; i < length * width * height; i++) {
      cout << content[i] << " ";
    }
    cout << endl;
  }
  ~Box() { delete[] content; }
};

int main() {
  int l, w, h;
  cout << "Enter the length of the box: ";
  cin >> l;
  cout << "Enter the width of the box: ";
  cin >> w;
  cout << "Enter the height of the box: ";
  cin >> h;
  Box *box1 = new Box(l, w, h);
  int c[l * w * h];
  cout << "Enter the contents of the box: ";
  for (int i = 0; i < l * w * h; i++) {
    cin >> c[i];
  }
  box1->setContents(c);
  Box *box2 = new Box(*box1);
  cout << "Box 1 details:" << endl;
  box1->display();
  cout << "Box 2 details:" << endl;
  box2->display();
  cout << "Enter new contents for box 2: ";
  for (int i = 0; i < l * w * h; i++) {
    cin >> c[i];
  }
  box2->setContents(c);
  cout << "Box 1 details:" << endl;
  box1->display();
  cout << "Box 2 details:" << endl;
  box2->display();
  delete box1;
  delete box2;
  return 0;
}
