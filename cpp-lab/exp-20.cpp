// Implement a real case scenario by a proper C++ code to provide the solution to Diamond Problem in C++

#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public:
    void display() {
        cout << "Class B" << endl;
    }
};

class C : public A {
public:
    void display() {
        cout << "Class C" << endl;
    }
};

class D : public B, public C {
public:
    void display() {
        cout << "Class D" << endl;
    }
};

int main() {
    D obj;
    obj.B::display();
    obj.C::display();
    obj.display();
    return 0;
}
