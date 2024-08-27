#pragma once
#include <cstdlib>
#include <string>
#include <ostream>

using namespace std;

class Item{
private:
    string call_num;
    string title;
    int num_copies;
public:
    /*
   :param call_num: a string
   :param title: a string
   :param num_copies: an int
   :param author: a string
   :precondition call_num: a unique identifier
   :precondition num_copies: a positive integer
   */
    Item(string call_num, string title, int num_copies):
    call_num(call_num), title(title), num_copies(num_copies){};

    /*
    Returns the title of the book
    :return: a string
    */
    string get_title() const{
        return title;
    }

    /*
    Returns the call number of the book
    :return: a string
    */
    string get_call_number() const{
        return call_num;
    }

    /*
    Adds the number of copies of a book
    */
    void increment_number_of_copies() {
        num_copies += 1;
    }

    /*
    Decrements the number of copies of a book
    */
    void decrement_number_of_copies() {
        num_copies -= 1;
    }

    /*
    Returns the number of copies that are available for this
    specific book.
    :return: an int
    */
    int get_num_copies() const {
        return num_copies;
    }
/*
    Returns True if the book is available and False otherwise
            :return: A Boolean
    */
    bool check_availability() const;

    virtual std::ostream& printDetails(std::ostream& os) const {
        os << "---- Item: " << title << " ----" << std::endl
           << "Call Number: " << call_num << std::endl
           << "Number of Copies: " << num_copies << std::endl;
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        return item.printDetails(os);
    }

    virtual ~Item(){};
};