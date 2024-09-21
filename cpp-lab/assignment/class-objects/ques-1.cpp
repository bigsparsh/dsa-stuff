// 1. Car Dealership Inventory:
//    Design a Car class that represents a car in a dealership's inventory. Attributes should include make, model, year, price, and availability status.
//    Implement methods to update the price, mark a car as sold, and display the car details.
//    Create a few Car objects to represent the inventory and perform operations like selling a car and updating prices.

#include <iostream>

class Car {
  private:
    std::string make, model;
    int year;
    double price;
    bool availability;

  public:
    void setProperties (std::string mk, std::string md, int y, double p, bool a) {
      make = mk;
      model = md;
      price = p;
      availability = a;
    }

    void updatePrice (int newPrice) {
      price = newPrice;
    }

    void sellCar () {
      if (availability)
        availability = false;
        std::cout << "\nNow the car has been sold.";
      else 
        std::cout << "\nThe car has already been sold.";
    }

    void getDetails () {
      std::cout << "\nMake: " << make;
      std::cout << "\nModel: " << model;
      std::cout << "\nYear: " << year;
      std::cout << "\nPrice: Rs. " << price;
      std::cout << "\nAvailability: " << availability ? "Yes" : "No";
    }
}

int main () {
  car c1, c2;
  c1.setProperties ("Toyota", "Innova", 2023, 3056750, true);
  c2.setProperties ("Audi", "A8", 2024, 50000000, true);
}
