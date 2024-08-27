#include "Course.hpp"

using namespace std;

Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time)
        : title(title), day(day), start_time(start_time), finish_time(finish_time) {

}

Course::Course(const Course &m) : title(m.title), day(m.day), start_time(m.start_time), finish_time(m.finish_time) {
}

Course &Course::operator=(const Course &m) {
    if (this != &m) { // Check for self-assignment
        title = m.title;
        day = m.day;
        start_time = m.start_time;
        finish_time = m.finish_time;
    }
    return *this;
}

bool Course::operator==(const Course &m) const {
    // Check for the same day and overlapping time ranges
    return (day == m.day) && (
            (start_time >= m.start_time && start_time < m.finish_time) ||  // Course 1's start time is during Course 2
            (finish_time > m.start_time && finish_time <= m.finish_time) ||  // Course 1's end time is during Course 2
            (m.start_time >= start_time && m.start_time < finish_time) ||  // Course 2's start time is during Course 1
            (m.finish_time > start_time && m.finish_time <= finish_time)  // Course 2's end time is during Course 1
    );
}

bool Course::operator<(const Course &m) const {
    return start_time < m.start_time;
}


ostream &operator<<(ostream &os, const Course &course) {
    os <<
       course.getTitle() << " " <<
       Course::toAlpha(course.getDay()) << " " <<
       course.getStartTime() << " " <<
       course.getFinishTime();
    return os;
}


const string &Course::getTitle() const {
    return title;
}

Course::dayOfWeek Course::getDay() const {
    return day;
}

unsigned int Course::getStartTime() const {
    return start_time;
}

unsigned int Course::getFinishTime() const {
    return finish_time;
}

char Course::toAlpha(const Course::DOW day) {
    switch (day) {
        case MON:
            return 'M';
        case TUE:
            return 'T';
        case WED:
            return 'W';
        case THUR:
            return 'R';
        case FRI:
            return 'F';
        default:
            cout << "invalid Day";
            return 'M';
    }
}
//test
