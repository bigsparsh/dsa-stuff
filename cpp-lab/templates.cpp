#include <iostream>
using namespace std;

template <typename T> class Stack {
private:
  T data;

public:
  Stack(T d) : data(d) {}

  void setData(T d) { data = d; }

  T getData() { return data; }
};

int main() {
  Stack<int> s(19);
  cout << s.getData() << endl;
  return 0;
}
