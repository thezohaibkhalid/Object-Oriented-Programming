#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Constructor to initialize with fixed values
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void displayTime() {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void addTime(const Time& other) {
        seconds += other.seconds;
        minutes += seconds / 60;
        seconds %= 60;

        minutes += other.minutes;
        hours += minutes / 60;
        minutes %= 60;

        hours += other.hours;
    }
};

int main() {
    Time t1(2, 30, 45); // 02:30:45
    Time t2(1, 15, 30); // 01:15:30
    Time t3;            // Default-initialized to 00:00:00

    cout << "Time 1: ";
    t1.displayTime();

    cout << "Time 2: ";
    t2.displayTime();

    t3.addTime(t1);
    t3.addTime(t2);

    cout << "Resultant Time: ";
    t3.displayTime();

    return 0;
}
