#include <iostream>

class TollBooth {
  private:
    unsigned int numOfCars;
    double moneyCollected;

  public: 
    TollBooth () {
      numOfCars = moneyCollected = 0;
    }

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
  TollBooth tollBooth;
  char input_char;

  do {
    std::cout << "Enter 'p' for paying car, 'n' for non-paying car, 'esc' to quit: ";
    std::cin >> input_char;

    switch (input_char) {
      case 'p':
        tollBooth.payingCar();
        break;
      case 'n':
        tollBooth.nonPayingCar();
        break;
      case 27:
        tollBooth.display();
        break;
      default:
        std::cout << "Invalid input\n";
    }
  } while (input_char != 27);

  return 0;
}
