#include <iostream>
#include <vector>
using namespace std;

int main () {
  vector<int> ve = {1,2,3,4};
  vector<int>::iterator it;
  for (it = ve.begin(); it != ve.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
