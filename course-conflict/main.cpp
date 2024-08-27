#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include "Course.hpp"

using namespace std;

typedef Course::dayOfWeek DOW;

// Print the course schedule to the screen
void printSchedule(const vector<Course> &courses);

// Convert a character representing a day to its enum value
Course::dayOfWeek dayAlpha(char letter);

// Open and return an input file stream for a given file path
ifstream filestreamer(const string file_path);

// Check if there is a schedule conflict between two courses
bool isConflict(const Course &course1, const Course &course2);

// Print out schedule conflicts among a list of courses
void printConflicts(const vector<Course> &courses);

// Compare two courses to determine their order based on day and time
bool compareCourses(const Course &course1, const Course &course2);

// Read course data from an input file stream and return a vector of Course objects
vector<Course> readCourse(ifstream &fs);

int main() {
    ifstream fs;
    // TODO read from courses.txt
    fs = filestreamer("./courses.txt");

    // TODO store data in an STL container
    vector<Course> courseList = readCourse(fs);

    // TODO sort your STL container with the sort algorithm
    sort(courseList.begin(), courseList.end(), compareCourses);

    // TODO implement code to determine schedule conflicts AND
    // TODO print out schedule conflicts
    printConflicts(courseList);

    // TODO print out schedule
    printSchedule(courseList);

    return 0;
}

ifstream filestreamer(const string file_path) {
    ifstream fs;
    fs.open(file_path);
    if (!fs.is_open()) {
        cerr << "file not opened " << file_path << endl;
    }
    return fs;
}

vector<Course> readCourse(ifstream &fs) {
    string line;
    vector<Course> courseList;
    //gets each line then assigns to a string
    while (getline(fs, line)) {
        istringstream iss(line);
        string title;
        char day;
        unsigned int start;
        unsigned int end;
        //assignment from iss to each variable
        iss >> title >> day >> start >> end;
        Course course = Course(title, dayAlpha(day), start, end);
        courseList.push_back(course);
    }
    return courseList;
}

//checks each course other courses and with == in isConflict() to see if it falls in range
// if sorted dont really need to but meh
void printConflicts(const vector<Course> &courses) {
    for (auto it1 = courses.begin(); it1 != courses.end(); ++it1) {
        for (auto it2 = it1 + 1; it2 != courses.end(); ++it2) {
            if (isConflict(*it1, *it2)) {
                cout << "Conflict:\n" <<
                     *it1 << "\n" <<
                     *it2 << "\n" <<
                     endl;
            }
        }
    }
}

//using copy algo it the assigning result to cout as the ostream iterator
void printSchedule(const vector<Course> &courses) {
    cout << "Course Schedule:" << endl;
    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout, "\n"));
}

DOW dayAlpha(char letter) {
    switch (letter) {
        case 'M':
            return DOW::MON;
        case 'T':
            return DOW::TUE;
        case 'W':
            return DOW::WED;
        case 'R':
            return DOW::THUR;
        case 'F':
            return DOW::FRI;
        default:
            cout << "invalid day";
            return DOW::MON;
    }
}
//custom Comparator for the sort()
bool compareCourses(const Course &course1, const Course &course2) {
    if (course1.getDay() == course2.getDay()) {
        // Sort by time within the same day
        return course1.getStartTime() < course2.getStartTime();
    }
    // Sort by day when days are different
    return course1.getDay() < course2.getDay();
}
//time range conflict check
bool isConflict(const Course &course1, const Course &course2) {
    return course1 == course2;  // Check if the two courses overlap using the operator==
}
