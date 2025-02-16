#include <iostream>
#include <fstream>
using namespace std;

int main () {
  string txt;
  ofstream file("source.txt", ios::out);
  file << "Heye, Bro" <<  "  " << "How you doin' ?";
  file.close();
  ifstream file2("source.txt", ios::in);
  while (file2 >> txt) {
    cout << txt << endl;
  }
  file2.close();
  return 0;
}
