#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream file("source.txt", ios::app);
  file << "Hey bor I am sexy as fuc,\n";
  file.close();

  return 0;
}
