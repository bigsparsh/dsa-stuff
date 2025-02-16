/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 7: 
// Imagine you are developing a simple social networking application in C++. Users can create profiles with personal
// information such as their name, age, and a list of their friends.
// However, users have the option to mark some friends as “private,” and private friends should be hidden from public
// view. Your task is to implement a solution using C++ classes and a friend function to manage this feature.

#include <iostream>
#include <string>
using namespace std;

class UserProfile {
private:
    string name;
    int age;
    string publicFriends[10];
    string privateFriends[10];
    int publicFriendCount = 0;
    int privateFriendCount = 0;

public:
    UserProfile(const std::string& userName, int userAge) 
        : name(userName), age(userAge) {}

    void addFriend(const std::string& friendName, bool isPrivate) {
        if (isPrivate && privateFriendCount < 10) {
            privateFriends[privateFriendCount++] = friendName;
        } else if (!isPrivate && publicFriendCount < 10) {
            publicFriends[publicFriendCount++] = friendName;
        } else {
            cout << "Friend list is full. Cannot add more friends.\n";
        }
    }

    friend void viewPublicFriends(const UserProfile& profile);
};

void viewPublicFriends(const UserProfile& profile) {
    cout << "Public friends of " << profile.name << ":\n";
    for (int i = 0; i < profile.publicFriendCount; ++i) {
        cout << "- " << profile.publicFriends[i] << "\n";
    }
}

int main() {
    UserProfile user1("Alice", 25);
    user1.addFriend("Bob", false);
    user1.addFriend("Charlie", true);
    user1.addFriend("Dave", false);

    UserProfile user2("Eve", 30);
    user2.addFriend("Mallory", false);
    user2.addFriend("Trudy", true);

    viewPublicFriends(user1);
    viewPublicFriends(user2);

    return 0;
}
