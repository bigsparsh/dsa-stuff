#include <iostream>

class Rectangle {
  private:
    double length;
    double width;
  
  public: 
    void setProperties (double l, double w){
      length = l;
      width = w;
    }
    double calcArea () {
      return length * width;
    }
    double calcPerimeter () {
      return 2 * (length + width);
    }
};

int main () {
  Rectangle r;
  double l, w;
  std::cout << "Enter length and width of rectangle: ";
  std::cin >> l >> w;
  r.setProperties(l, w);
  std::cout << "Area of Rectangle: " << r.calcArea() << std::endl;
  std::cout << "Perimeter of Rectangle: " << r.calcPerimeter() << std::endl;
  return 0;
}
