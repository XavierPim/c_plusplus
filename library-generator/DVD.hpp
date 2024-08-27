#pragma once
#include <cstdlib>
#include <iosfwd>
#include <string>
#include <iostream>
#include "Item.hpp"
using namespace std;

class DVD : public Item {
private:
    int num_CDs;
public:
    DVD(string call_num, string title, int num_copies, int num_CDs)
            : Item(call_num, title, num_copies), num_CDs(num_CDs) {}


    int get_numCDs() const{
        return num_CDs;
    }
    std::ostream& printDetails(std::ostream& os) const override {
        Item::printDetails(os);
        os << "Number of CDs: " << num_CDs << std::endl;

        return os;
    }

    ~DVD(){};
};

