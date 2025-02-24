#include <iostream>
using namespace std;
#define Max 100
int main() {
  int m;
  cout << "Enter the number of test cases : ";
  cin >> m;
  for (int j = 0; j < m; j++) {
    int arr[Max];
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;
    cout << "Enter the elements of an array : ";
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = n - 1; i > 0; i--) {
      int j = 0;
      int k = i - 1;
      while (j < k) {
        if ((arr[j] + arr[k]) == arr[i]) {
          cout << j << "-" << k << "-" << i << endl;
          j++;
          k--;
        } else if ((arr[j] + arr[k]) > arr[i]) {
          k--;
        } else {
          j++;
        }
      }
    }
  }
  return 0;
}
