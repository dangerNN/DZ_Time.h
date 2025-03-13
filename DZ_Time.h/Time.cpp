#include "Time.h"

Time_::Time_() {
    time_t now = time(0);
    tm* obj = new tm;
    localtime_s(obj, &now);

    hour = obj->tm_hour;
    minutes = obj->tm_min;
    seconds = obj->tm_sec;
    format = true;

    delete obj;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
    : hour(hour), minutes(minutes), seconds(seconds), format(format) {}

Time_::Time_(const Time_& obj) {
    hour = obj.hour;
    minutes = obj.minutes;
    seconds = obj.seconds;
    format = obj.format;
}

Time_& Time_::operator=(const Time_& obj) {
    if (this != &obj) {
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}

Time_::~Time_() {}

void Time_::setHour(int hour) { this->hour = hour; }
int Time_::getHour() const { return hour; }
void Time_::setMinutes(int minutes) { this->minutes = minutes; }
int Time_::getMinutes() const { return minutes; }
void Time_::setSeconds(int seconds) { this->seconds = seconds; }
int Time_::getSeconds() const { return seconds; }
void Time_::setFormat(bool format) { this->format = format; }
bool Time_::getFormat() const { return format; }

bool Time_::valid() const {
    return hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60;
}

void Time_::tickTime() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hour++;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
}

void Time_::untickTime() {
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hour--;
            if (hour < 0) {
                hour = 23;
            }
        }
    }
}

void Time_::showTime() const {
    if (format) {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    } else {
        string period = (hour < 12) ? "AM" : "PM";
        int displayHour = (hour % 12 == 0) ? 12 : hour % 12;
        cout << setw(2) << setfill('0') << displayHour << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << " " << period << endl;
    }
}

bool Time_::operator==(const Time_& obj) const {
    return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds;
}

bool Time_::operator!=(const Time_& obj) const {
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const {
    if (hour > obj.hour) return true;
    if (hour == obj.hour && minutes > obj.minutes) return true;
    if (hour == obj.hour && minutes == obj.minutes && seconds > obj.seconds) return true;
    return false;
}

bool Time_::operator<(const Time_& obj) const {
    return !(*this > obj) && !(*this == obj);
}

bool Time_::operator>=(const Time_& obj) const {
    return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const {
    return (*this < obj) || (*this == obj);
}

Time_& Time_::operator+=(int s) {
    for (int i = 0; i < s; i++) tickTime();
    return *this;
}

Time_& Time_::operator-=(int s) {
    for (int i = 0; i < s; i++) untickTime();
    return *this;
}

Time_& Time_::operator+=(float m) {
    int minutesToAdd = static_cast<int>(m);
    *this += minutesToAdd * 60;
    return *this;
}

Time_& Time_::operator-=(float m) {
    int minutesToSubtract = static_cast<int>(m);
    *this -= minutesToSubtract * 60;
    return *this;
}

Time_& Time_::operator+=(long h) {
    *this += h * 3600;
    return *this;
}

Time_& Time_::operator-=(long h) {
    *this -= h * 3600;
    return *this;
}

Time_ Time_::operator+(int s) const {
    Time_ temp(*this);
    temp += s;
    return temp;
}

Time_ Time_::operator-(int s) const {
    Time_ temp(*this);
    temp -= s;
    return temp;
}

Time_ Time_::operator+(float m) const {
    Time_ temp(*this);
    temp += m;
    return temp;
}

Time_ Time_::operator-(float m) const {
    Time_ temp(*this);
    temp -= m;
    return temp;
}

Time_ Time_::operator+(long h) const {
    Time_ temp(*this);
    temp += h;
    return temp;
}

Time_ Time_::operator-(long h) const {
    Time_ temp(*this);
    temp -= h;
    return temp;
}