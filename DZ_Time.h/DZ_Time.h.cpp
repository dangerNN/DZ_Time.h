#include "Time.h"
#include "Time.h"
#include "Bus.h"
#include <iostream>
#include <vector>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);

    Time_ startTime(6, 0, 0, true);
    Time_ endTime(11, 0, 0, true);
    int routeDuration = 30;
    int restTime = 10;

    Bus bus(startTime, endTime, routeDuration, restTime);

    bus.printSchedule();

    return 0;
}