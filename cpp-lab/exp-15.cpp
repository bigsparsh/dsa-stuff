#include <iostream>
using namespace std;

class MyClass {
private:
    float value;

public:
    // Constructor
    MyClass(float v = 0) : value(v) {}

    // Display value
    void showValue() const {
        cout << "Value: " << value << endl;
    }

    // Overloading Unary -
    MyClass operator-() {
        MyClass temp;
        temp.value = -value;
        return temp;
    }

    // Overloading Pre-increment ++
    MyClass operator++() {
        MyClass temp;
        temp.value = value + 1.5;  // Incrementing by 1.5
        return temp;
    }

    // Overloading Post-increment ++
    MyClass operator++(int) {
        MyClass temp;
        temp.value = value;
        value += 1.5;  // Incrementing by 1.5
        return temp;
    }

    // Overloading Pre-decrement --
    MyClass operator--() {
        MyClass temp;
        temp.value = value - 2.0;  // Decrementing by 2.0
        return temp;
    }

    // Overloading Post-decrement --
    MyClass operator--(int) {
        MyClass temp;
        temp.value = value;
        value -= 2.0;  // Decrementing by 2.0
        return temp;
    }
};

int main() {
    MyClass obj(5.0);

    cout << "Initial value: ";
    obj.showValue();

    // Unary -
    MyClass negativeObj = -obj;
    cout << "After unary -: ";
    negativeObj.showValue();

    // Pre-increment
    MyClass preIncObj = ++obj;
    cout << "After pre-increment: ";
    preIncObj.showValue();

    // Post-increment
    MyClass postIncObj = obj++;
    cout << "After post-increment: ";
    postIncObj.showValue();

    // Pre-decrement
    MyClass preDecObj = --obj;
    cout << "After pre-decrement: ";
    preDecObj.showValue();

    // Post-decrement
    MyClass postDecObj = obj--;
    cout << "After post-decrement: ";
    postDecObj.showValue();

    return 0;
}
