// Create a Base class that consists of private, protected and public data members and
// member functions. Try using different access modifiers for inheriting Base class to
// the Derived class and create a table that summarizes the above three modes (when
// derived in public, protected and private modes) and shows the access specifier of
// the members of base class in the Derived class.

#include <iostream>
using namespace std;

class Base {
private:
    int privateData;        // Accessible only within the Base class

protected:
    int protectedData;      // Accessible within Base and its derived classes

public:
    int publicData;         // Accessible everywhere

private:
    void privateMethod() {
        cout << "Private method of Base class" << endl;
    }

protected:
    void protectedMethod() {
        cout << "Protected method of Base class" << endl;
    }

public:
    void publicMethod() {
        cout << "Public method of Base class" << endl;
    }
};

class PublicDerived : public Base {
public:
    void accessMembers() {
        publicData = 10;    // Allowed
        protectedData = 20; // Allowed

        // privateData = 30; // Compilation Error

        publicMethod();
        protectedMethod();
        // privateMethod(); // Compilation Error
    }
};

// Derived class with protected inheritance
class ProtectedDerived : protected Base {
public:
    void accessMembers() {
        publicData = 10;    // Now protected
        protectedData = 20; // Remains protected

        publicMethod();     // Now protected
        protectedMethod();  // Remains protected
    }
};

class PrivateDerived : private Base {
public:
    void accessMembers() {
        publicData = 10;    // Now private
        protectedData = 20; // Now private

        publicMethod();     // Now private
        protectedMethod();  // Now private
    }
};

int main() {
    PublicDerived pubDerived;
    ProtectedDerived protDerived;
    PrivateDerived privDerived;

    pubDerived.publicMethod();     // Allowed
    // pubDerived.protectedMethod(); // Not allowed
    // pubDerived.privateData;       // Not accessible

    return 0;
}
