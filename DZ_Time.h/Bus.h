#pragma once
#include "Time.h"

class Bus {
private:
    Time_ startTime;
    Time_ endTime;
    int routeDuration;
    int restTime;

public:
    Bus(const Time_& startTime, const Time_& endTime, int routeDuration, int restTime);
    void createSchedule(Time_ departures[], Time_ arrivals[], int& count) const;
    void printSchedule() const;
};