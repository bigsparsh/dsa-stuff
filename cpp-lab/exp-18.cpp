// You are given three classes A, B and C. All three classes implement their own
// version of func. In class A, func multiplies the value passed as a parameter by 2. In
// class B, func multiplies the value passed as a parameter by 3. In class C, func
// multiplies the value passed as a parameter by 5.You are given class D such that You
// need to modify the class D and implement the function update_val which sets D's
// val to new_val by manipulating the value by only calling the func defined in classes
// A, B and C.It is guaranteed that new_val has only 2, 3 and 5 as its prime factors.
// Implement class D's function update_val. This function should update D's val only
// by calling A, B and C's func.

#include <iostream>
using namespace std;

class A {
public:
    A() : val(1) {}
    int val;
    void func(int &a) {
        a = a * 2;
    }
};

class B {
public:
    B() : val(1) {}
    int val;
    void func(int &a) {
        a = a * 3;
    }
};

class C {
public:
    C() : val(1) {}
    int val;
    void func(int &a) {
        a = a * 5;
    }
};

class D : public A, public B, public C {
    int val;
  public:
    D() : val(1) {}
    void update_val(int new_val) {
        int a, b, c;
        a = b = c = 0;
        while (new_val % 2 == 0) {
            A::func(val);
            new_val /= 2;
            a++;
        }
        while (new_val % 3 == 0) {
            B::func(val);
            new_val /= 3;
            b++;
        }
        while (new_val % 5 == 0) {
            C::func(val);
            new_val /= 5;
            c++;
        }
        cout << "Called A: " << a << " times" << endl;
        cout << "Called B: " << b << " times" << endl;
        cout << "Called C: " << c << " times" << endl;
    }
};


int main() {
    D().update_val(60);
    return 0;
}

