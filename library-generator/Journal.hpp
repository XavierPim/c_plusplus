#pragma once
#include <cstdlib>
#include <iosfwd>
#include <string>
#include <iostream>
#include "Item.hpp"
using namespace std;

class Journal : public Item{
private:
    string author;

    /*
    Returns the author of the book
    :return: a string
    */
    string get_author() const{
        return author;
    }

    std::ostream& printDetails(std::ostream& os) const override {
        Item::printDetails(os);
        os << "Author: " << author << std::endl;
        return os;
    }

public:
    Journal(string call_num, string title, int num_copies, string author)
    : Item(call_num, title, num_copies), author(author) {}
};

