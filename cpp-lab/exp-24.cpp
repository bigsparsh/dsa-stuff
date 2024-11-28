// Templates are the foundation of generic programming, which involves writing code
// in a way that is independent of any particular type. Write a program that can create
// a list (create a class list) of given type (int, float, char etc.) and perform insertion
// and deletion on list object.

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class List {
    vector<T> list;
  public:
    void insert(T val) {
        list.push_back(val);
    }
    void remove(T val) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == val) {
                list.erase(list.begin() + i);
                break;
            }
        }
    }
    void display() {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    List<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.display();
    intList.remove(20);
    intList.display();

    List<float> floatList;
    floatList.insert(10.5);
    floatList.insert(20.5);
    floatList.insert(30.5);
    floatList.display();
    floatList.remove(20.5);
    floatList.display();

    List<char> charList;
    charList.insert('a');
    charList.insert('b');
    charList.insert('c');
    charList.display();
    charList.remove('b');
    charList.display();

    return 0;
}
