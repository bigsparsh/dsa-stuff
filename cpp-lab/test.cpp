#include <iostream>

class AdvanceNum {
  private:
    int data;
  public:
    AdvanceNum(int num=0) : data(num) {}

    friend AdvanceNum operator+(int newData, const AdvanceNum& obj);
    
    int getData () {
      return data;
    }

};

AdvanceNum operator+(int newData, const AdvanceNum& obj) {
  return AdvanceNum(newData + obj.data);
}

int main () {
  AdvanceNum a(5);
  AdvanceNum b(10);
  AdvanceNum c = 19 + a;
  std::cout << "The data: " << c.getData() << std::endl;
  return 0;
}
