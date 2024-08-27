// Course.h
#include <iostream>

using namespace std;

class Course {

public:
    enum dayOfWeek {
        MON, TUE, WED, THUR, FRI
    };
    typedef dayOfWeek DOW;

    // Constructor to create a Course object with the given attributes
    Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);

// Copy constructor to create a Course object by copying another Course
    Course(const Course &m);

// Assignment operator to copy the attributes from another Course
    Course &operator=(const Course &m);

// Comparison operator to determine if this course is scheduled before another course
    bool operator<(const Course &m) const;

// Comparison operator to check if two courses have overlapping schedules
    bool operator==(const Course &m) const;

// Static method to convert a dayOfWeek enum value to a character representation
    static char toAlpha(const dayOfWeek day);


    // Helper operator for output
    friend ostream &operator<<(std::ostream &os, const Course &course);
//getters
    const string &getTitle() const;

    dayOfWeek getDay() const;

    unsigned int getStartTime() const;

    unsigned int getFinishTime() const;

private:
    string title; // Name of Course
    dayOfWeek day; // Day of Course
    unsigned int start_time; // Course start time in HHMM format
    unsigned int finish_time; // Course finish time in HHMM format
};
