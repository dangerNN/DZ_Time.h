#include "Time.h"
#include <iostream>
#include <vector>

using namespace std;

struct LessonSchedule {
    Time_ start;
    Time_ end;
};

int main() {
    setlocale(LC_ALL, "");
    int lessonDuration, shortBreak, longBreak, longBreakPosition, lessonCount;
    int hour, minute;

    cout << "Введите время начала (часы и минуты): ";
    cin >> hour >> minute;
    cout << "Введите длительность пары (в минутах): ";
    cin >> lessonDuration;
    cout << "Введите длительность обычной перемены (в минутах): ";
    cin >> shortBreak;
    cout << "Введите длительность большой перемены (в минутах): ";
    cin >> longBreak;
    cout << "Введите позицию большой перемены: ";
    cin >> longBreakPosition;
    cout << "Введите количество пар: ";
    cin >> lessonCount;

    vector<LessonSchedule> schedule;
    Time_ current(hour, minute, 0);

    for (int i = 0; i < lessonCount; i++) {
        LessonSchedule lesson;
        lesson.start = current;
        current += lessonDuration * 60;
        lesson.end = current;
        schedule.push_back(lesson);

        if (i + 1 == longBreakPosition) {
            current += longBreak * 60;
        }
        else if (i + 1 < lessonCount) {
            current += shortBreak * 60;
        }
    }

    cout << "\nРасписание звонков:" << endl;
    for (size_t i = 0; i < schedule.size(); i++) {
        cout << "Пара " << i + 1 << ": ";
        schedule[i].start.showTime();
        cout << " - ";
        schedule[i].end.showTime();
        cout << endl;
    }

    return 0;
}

