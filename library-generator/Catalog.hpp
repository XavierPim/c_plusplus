#pragma once

#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include "Item.hpp"
#include "Catalog.hpp"

using namespace std;

class Catalog {
protected:
    vector<Item *> item_list;
public:

    explicit Catalog(const vector<Item *> &itemList) : item_list(itemList) {}

    const vector<Item *> &getItemList() const;

    static void clean_cin();

/*
   A private method that encapsulates the retrieval of an book with
           the given call number from the library.
   :param call_number: a string
   :return: book pointer
   */
    Item *retrieve_item_by_call_number(string call_number);

/*
Find items with the same title.
:param title: a string
:return: a vector of book pointers.
*/
    vector<Item *> find_items(string title);

/*
Add a brand new book to the library with a unique call number.
*/
    void add_item();

/*
Remove an existing book from the library
        :param call_number: a string
        :precondition call_number: a unique identifier
*/
    void remove_item(string call_number);

//Display all the items in the library.
    void display_available_items();

/*
Decrement the book count for an book with the given call number
        in the library.
:param call_number: a string
:precondition call_number: a unique identifier
        :return: True if the book was found and count decremented, false
otherwise.
*/
    bool reduce_item_count(string call_number);

/*
Increment the book count for an book with the given call number
        in the library.
:param call_number: a string
:precondition call_number: a unique identifier
        :return: True if the book was found and count incremented, false
otherwise.
*/
    bool increment_item_count(string call_number);
    /*
    Returns True if the book is available and False otherwise
            :return: A Boolean
    */
};