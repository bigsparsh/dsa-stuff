#include <iostream>

class Student {
  private: 
    int scores[5];
  public:
    void input () {
      std::cout << "\nEnter the scores for each subject: \n";
      for (int i = 0; i < 5; i++) {
        std::cout << "\nSubject: " << i+1 << ": ";
        std::cin >> scores[i];
      }
    }
    int calculateTotalScore () {
      int sum = 0;
      for (int score : scores) 
        sum += score;
      return sum;
    }
};

int main () {
  int size, count = 0;
  std::cout << "\nHow many students are in the class?: ";
  std::cin >> size;

  Student students[size];

  for (int i = 0; i < size; i++ ) {
    students[i].input();
    if (i != 0 && students[0].calculateTotalScore() < students[i].calculateTotalScore()) count++;
  }

  std::cout << "\n\n" << count << " student have more score than anna.\n";
}
