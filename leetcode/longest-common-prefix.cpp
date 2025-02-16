#include <iostream>
#include <vector>

using namespace std;

string longestcommonprefix (vector<string> strs) {
  int bi = 0;
  string output = "";
  char buffer;
  while (true) {
    if (bi >= strs[0].size()) return output;
    buffer = strs[0][bi];

    bool check = true;
    for (string str : strs) {
      if (bi > str.size()) return output;
      if (buffer != str[bi]) {
        check = false;
        break;
      }
    }
    if (!check) return output;
    output += buffer;
    bi++;
  }
}

int main() {
  vector<string> strs = {"dog", "flow", "flight"};
  cout << "The answer is:" << longestcommonprefix(strs) << endl;

  return 0;
}
