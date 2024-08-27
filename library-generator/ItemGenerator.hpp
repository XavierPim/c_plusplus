#pragma once
#include <cstdlib>
#include <iostream>
#include "Item.hpp"
#include "Catalog.hpp"
#include "Journal.hpp"
#include "DVD.hpp"
#include "book.hpp"
#include <limits>


using namespace std;

class ItemGenerator {
public:
    static Item* generateItem(int item_type, const string& call_number, const string& title, int num_copies, const string& author = "", int num_CDs = 0) {
        switch (item_type) {
            case 1: // Book
                return new Book(call_number, title, num_copies, author);
            case 2: // DVD
                return new DVD(call_number, title, num_copies, num_CDs);
            case 3: // Journal
                return new Journal(call_number, title, num_copies, author);
            default:
                return nullptr;
        }
    }
};
