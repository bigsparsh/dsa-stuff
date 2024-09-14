#include <iostream>

class TollBooth {
  private:
    unsigned int numOfCars;
    double moneyCollected;

    TollBooth () {
      numOfCars = moneyCollected = 0;
    }
  public: 
    void payingCar () {
      numOfCars++;
      moneyCollected += 0.5;
    }
    void nonPayingCar () {
      numOfCars++;
    }
    void display () {
      std::cout << "Number of cars: " << numOfCars << "\n";
      std::cout << "Money collected: " << moneyCollected << "\n";
    }
};

int main () {
  return 0;
}
