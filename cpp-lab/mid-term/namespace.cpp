#include <iostream>

using namespace std;

namespace StringOperation {
  string concatenate(string a, string b) {
    return a + b;
  }
  int getLength(string a) {
    return a.length();
  }
  string uppercase(const string& str) {
    string str1 = str;
    for (char& c : str1) {
        c = toupper(c);
    }
    return str1;
  }
  string lowercase(const string& str) {
    string str1 = str;
    for (char& c : str1) {
        c = tolower(c);
    }
    return str1;
  }
}

namespace MathOperation {
  int add(int a, int b) {
    return a + b;
  }
  int subtract(int a, int b) {
    return a - b;
  }
  int multiply(int a, int b) {
    return a * b;
  }
  double divide(int a, int b) {
    if (b == 0) {
      cout << "Can't divide with 0" << endl;
      return 0;
    }
    return (double) a / b;
  }
}

int main () {
  cout << StringOperation::lowercase("HELLO THERE") << endl;
  cout << StringOperation::concatenate("Sparsh", " Singh") << endl;
  cout << StringOperation::uppercase("hello world") << endl;
  cout << StringOperation::getLength("HELLO WsdLD") << endl;

  cout << MathOperation::add(1, 34) << endl;
  cout << MathOperation::subtract(23, 21) << endl;
  cout << MathOperation::divide(12, 0) << endl;
  cout << MathOperation::multiply(21, 2) << endl;

  return 0;
}
