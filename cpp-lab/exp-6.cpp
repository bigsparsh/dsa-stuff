#include <iostream>

class Hotel {
  private:
    int roomNumber;
    std::string name;
    double tariff;
    int days;
    
    double calc () {
      return (tariff * days > 10000) ? (tariff * days * 1.05) : (tariff * days);
    }
    
  public:
    void checkIn (int r, std::string n, double t, int d) {
      roomNumber = r;
      name = n;
      tariff = t;
      days = d;
    }
    void checkOut () {
      std::cout << "Room Number: " << roomNumber << std::endl;
      std::cout << "Name: " << name << std::endl;
      std::cout << "Tariff: " << tariff << std::endl;
      std::cout << "Days: " << days << std::endl;
      std::cout << "Total Amount: " << calc() << std::endl;
    }
};

int main () {
  Hotel h;
  int r, d;
  std::string n;
  double t;
  std::cout << "Enter room number, name, tariff and days: ";
  std::cin >> r >> n >> t >> d;
  h.checkIn(r, n, t, d);
  h.checkOut();
  return 0;
}
