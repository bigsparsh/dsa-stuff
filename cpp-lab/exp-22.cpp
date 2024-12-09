// Create a base class called CAL_AREA(Abstract). Use this class to store float
// type values that could be used to compute the volume of figures. Derive two
// specific classes called cone, hemisphere and cylinder from the base CAL_AREA.
// Add to the base class, a member function getdata ( ) to initialize base class
// data members and another member function display volume( ) to compute and
// display the volume of figures. Make display volume ( ) as a pure virtual
// function and redefine this function in the derived classes to suit their
// requirements. Using these three classes, design a program that will accept
// dimensions of a cone, cylinder and hemisphere interactively and display the
// volumes. Remember values given as input will be and used as follows: Volume
// of cone = (1/3)πr2h Volume of hemisphere = (2/3)πr3 Volume of cylinder = πr2h

#include <iostream>
using namespace std;

class CAL_AREA {
protected:
  float r, h;

public:
  void getdata() {
    cout << "Enter the dimensions: ";
    cin >> r >> h;
  }
  virtual void display_volume() = 0;
};

class Cone : public CAL_AREA {
public:
  void display_volume() {
    cout << "Volume: " << (1.0 / 3.0) * 3.14159 * r * r * h << endl;
  }
};

class Hemisphere : public CAL_AREA {
public:
  void display_volume() {
    cout << "Volume: " << (2.0 / 3.0) * 3.14159 * r * r * r << endl;
  }
};

class Cylinder : public CAL_AREA {
public:
  void display_volume() { cout << "Volume: " << 3.14159 * r * r * h << endl; }
};

int main() {
  CAL_AREA *c;
  Cone cone;
  Hemisphere hemisphere;
  Cylinder cylinder;

  c = &cone;
  c->getdata();
  c->display_volume();

  c = &hemisphere;
  c->getdata();
  c->display_volume();

  c = &cylinder;
  c->getdata();
  c->display_volume();

  return 0;
}
