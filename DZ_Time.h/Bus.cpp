#include "Bus.h"
#include "Time.h"
#include <iostream>
#include <windows.h>
using namespace std;

Bus::Bus(const Time_& startTime, const Time_& endTime, int routeDuration, int restTime)
    : startTime(startTime), endTime(endTime), routeDuration(routeDuration*60), restTime(restTime * 60) {
}

void Bus::createSchedule(Time_ departures[], Time_ arrivals[], int& count) const {
    Time_ currentDeparture = startTime;
    count = 0;
    while (currentDeparture < endTime && count < 100) {
        Time_ arrival = currentDeparture;
        arrival += routeDuration;

        departures[count] = currentDeparture;
        arrivals[count] = arrival;
        count++;

        currentDeparture = arrival;
        currentDeparture += restTime;
    }
}

void Bus::printSchedule() const {
    const int maxTrips = 100;
    Time_ departures[maxTrips];
    Time_ arrivals[maxTrips];
    int count = 0;

    createSchedule(departures, arrivals, count);

    cout << "Розклад автобусного маршруту:\n";
    for (int i = 0; i < count; i++) {
        cout << "Рейс " << i + 1 << ": ";
        departures[i].showTime();
        cout << " - ";
        arrivals[i].showTime();
        cout << "\n";
    }
}