#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int val = 0) : value(val) {}

    friend Number operator-(Number& num);
    friend Number& operator++(Number& num);
    friend Number operator++(Number& num, int);
    friend Number& operator--(Number& num);
    friend Number operator--(Number& num, int);

    void display() const {
        cout << "Value: " << value << endl;
    }
};

Number operator-(Number& num) {
    return Number(-num.value);
}

Number& operator++(Number& num) {
    ++num.value;
    return num;
}

Number operator++(Number& num, int) {
    Number temp = num;
    num.value++;
    return temp;
}

Number& operator--(Number& num) {
    --num.value;
    return num;
}

Number operator--(Number& num, int) {
    Number temp = num;
    num.value--;
    return temp;
}

int main() {
    Number n(10);

    cout << "Original ";
    n.display();

    Number neg = -n;
    cout << "After unary - ";
    neg.display();

    ++n;
    cout << "After pre-increment ";
    n.display();

    n++;
    cout << "After post-increment ";
    n.display();

    --n;
    cout << "After pre-decrement ";
    n.display();

    n--;
    cout << "After post-decrement ";
    n.display();

    return 0;
}
