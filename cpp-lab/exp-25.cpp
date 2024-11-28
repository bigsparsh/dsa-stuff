// Construct a C++ program to demonstrate different methods of List, Vector and Map in STL (Standard Template Library)

#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

int main() {
    // List
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_front(5);
    l.push_front(15);
    l.push_front(25);
    l.pop_back();
    l.pop_front();
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Vector
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.pop_back();
    vector<int>::iterator vit;
    for (vit = v.begin(); vit != v.end(); vit++) {
        cout << *vit << " ";
    }
    cout << endl;

    // Map
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";
    m[4] = "Four";
    m[5] = "Five";
    m.erase(3);
    map<int, string>::iterator mit;
    for (mit = m.begin(); mit != m.end(); mit++) {
        cout << mit->first << " " << mit->second << endl;
    }

    return 0;
}
