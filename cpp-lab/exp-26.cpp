// You are provided with a vector of N integers. Then, you are given 2 queries. For the
// first query, you are provided with 1 integer, which denotes a position in the vector.
// The value at this position in the vector needs to be erased. The next query consists
// of 2 integers denoting a range of the positions in the vector. The elements which fall
// under that range should be removed. The second query is performed on the updated
// vector which we get after performing the first query.
// Input Format
// The first line of the input contains an integer N. The next line contains N spaceseparated integers (1-based index). The third line contains a single integer x,
// denoting the position of an element that should be removed from the vector. The
// fourth line contains two integers a and b denoting the range that should be erased
// from the vector inclusive of a and exclusive of b.
// Output Format
// Print the size of the vector in the first line and the elements of the vector after the
// two erase operations in the second line separated by space.
// Sample Input
// 6
// 1 4 6 2 8 9
// 2
// 2 4
// Sample Output
// 3
// 1 8 9
// Explanation
// The first query is to erase the 2nd element in the vector, which is 4. Then, a modified
// vector is {1 6 2 8 9}, we want to remove the range of 2~4, which means the 2nd and
// 3rd elements should be removed. Then 6 and 2 in the modified vector are removed
// and we finally get {1 8 9}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int x;
    cin >> x;
    v.erase(v.begin() + x - 1);
    int a, b;
    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
