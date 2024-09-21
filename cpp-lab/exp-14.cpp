#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const& obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    Complex operator-(Complex const& obj)
    {
        Complex res;
        res.real = real - obj.real;
        res.imag = imag - obj.imag;
        return res;
    }

    bool operator == (Complex const& obj) {
      if (real == obj.real && imag == obj.imag) 
        return true;
      return false;
    }

    void print() { 
      cout << real << " + " << imag << "i\n"; 
    }
};

int main()
{
    Complex c1(10, 5), c2(10, 5);
    Complex c3 = c1 + c2;
    c3.print();
    Complex c4 = c1 - c2;
    c4.print();
    std::cout << (c1 == c2);
    return 0;
}
