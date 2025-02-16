/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// 12. Animal Sound Simulation
// • Objective: Create a base class Animal with a virtual function makeSound(). Derive classes Dog, Cat,
// and Cow from Animal, and implement makeSound() to produce different animal sounds.
// • Scenario:
// o You are building a virtual zoo where you need to simulate animal sounds. Each animal produces a
// different sound when it is called to make a sound.
// o The base class Animal will have a virtual function makeSound(), which is overridden by each
// derived class to simulate the specific sound of each animal.
// • Instructions:
// o Define a base class Animal with a virtual function makeSound().
// o Create derived classes Dog, Cat, and Cow. In each derived class, implement makeSound() to
// simulate the sound of the respective animal.
// o In the main function, create pointers to Animal and use polymorphism to call makeSound()
// for each animal.

#include <iostream>
using namespace std;

class Animal {
public:
  virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
  void makeSound() { cout << "Dog says: Woof!" << endl; }
};

class Cat : public Animal {
public:
  void makeSound() { cout << "Cat says: Meow!" << endl; }
};

class Cow : public Animal {
public:
  void makeSound() { cout << "Cow says: Moo!" << endl; }
};

int main() {
  Animal *animal;
  Dog dog;
  Cat cat;
  Cow cow;

  animal = &dog;
  animal->makeSound();

  animal = &cat;
  animal->makeSound();

  animal = &cow;
  animal->makeSound();

  return 0;
}
