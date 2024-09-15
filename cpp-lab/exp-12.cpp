#include <iostream>

class Time {
  private:
    int hours, minutes, seconds;

  public:
    Time () {
      hours = minutes = seconds = 0;
    }
    Time (int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    Time add (Time t1, Time t2) {
      int temp_hrs = 0, temp_min = 0, temp_sec = 0;
      if (t1.seconds + t2.seconds > 60) { 
        temp_min = (t1.seconds + t2.seconds) / 60;
        temp_sec = (t1.seconds + t2.seconds) % 60;
      } else temp_sec = t1.seconds + t2.seconds;
      if (t2.minutes + t1.minutes + temp_min > 60) {
        temp_hrs = (t1.minutes + t2.minutes + temp_min) / 60;
        temp_min = (t1.minutes + t2.minutes + temp_min) % 60;
      } else temp_min = t1.minutes + t2.minutes + temp_min;
      temp_hrs += t1.hours + t2.hours;
      Time t3(temp_hrs, temp_min, temp_sec);
      return t3;
    }

    void show () {
      std::cout << "\nThe time is " << hours << ":" << minutes << ":" << seconds;
    }
};

int main () {
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
