#pragma once

#include <vector>
#include <sstream>
#include "book.hpp"
#include "Catalog.hpp"

using namespace std;
/*
The Library consists of a list of books and provides an
interface for users to check out, return and find books.
*/
class Library {

    Catalog* catalog;
public:
    /*
    Intialize the library with a list of books.
    :param book_list: a vector of book pointers
    */
    Library(Catalog* catalog) : catalog(catalog) {}

    /*
    Check out a book with the given call number from the library.
    :param call_number: a string
    :precondition call_number: a unique identifier
    */
    void check_out(string call_number);

    /*
    Return an book with the given call number from the library.
    :param call_number: a string
    :precondition call_number: a unique identifier
    */
    void return_book(string call_number);


    /*
    Display the library menu allowing the user to either access the
    list of books, check out, return, find, add, remove a book.
    */
    void display_library_menu();

    ~Library(){};

};
//static void deleteVectorOfPointers(std::vector<Item*>& vec);