#include <iostream>

class Time {
private:
      int hr, min, sec;

public:
  Time() { hr = min = sec = 0; }
  Time(int h, int m, int s) : hr(h), min(m), sec(s) {}

  Time add(Time t1, Time t2) {
    int temp_hrs = 0, temp_min = 0, temp_sec = 0;
    if (t1.sec + t2.sec > 60) {
      temp_min = (t1.sec + t2.sec) / 60;
      temp_sec = (t1.sec + t2.sec) % 60;
    } else
      temp_sec = t1.sec + t2.sec;
    if (t2.min + t1.min + temp_min > 60) {
      temp_hrs = (t1.min + t2.min + temp_min) / 60;
      temp_min = (t1.min + t2.min + temp_min) % 60;
    } else
      temp_min = t1.min + t2.min + temp_min;
    temp_hrs += t1.hr + t2.hr;
    Time t3(temp_hrs, temp_min, temp_sec);
    return t3;
  }

  void show() {
    std::cout << "\nThe time is " << hr << ":" << min << ":" << sec;
  }
};

int main() {
  int hrs, mins, secs;
  std::cout << "\nEnter the first time (H/M/S): ";
  std::cin >> hrs >> mins >> secs;
  Time t1(hrs, mins, secs);
  std::cout << "\nEnter the second time (H/M/S): ";
  std::cin >> hrs >> mins >> secs;
  Time t2(hrs, mins, secs);

  Time t3 = t1.add(t1, t2);
  t3.show();
}
