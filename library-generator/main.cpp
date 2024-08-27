//Name:
//Student# :

#include <iostream>
#include "library.hpp"
#include "DVD.hpp"
#include "Journal.hpp"

/*
Return a list of books with dummy data.
:return: a vector of book pointers
*/
vector<Item *> generate_test_books() {
    vector<Item *> book_list;
    book_list.push_back(new Book("100.200.300", "Harry Potter 1", 2, "J K Rowling"));
    book_list.push_back(new Book("999.224.854", "Harry Potter 2", 5, "J K Rowling"));
    book_list.push_back(new Book("631.495.302", "Harry Potter 3", 4, "J K Rowling"));
    book_list.push_back(new Book("123.02.204", "The Cat in the Hat", 1, "Dr. Seuss"));
    book_list.push_back(new DVD("111.11.111", "BingBong", 1, 2));
    book_list.push_back(new Journal("111.11.132", "wingWong", 1, "hololo"));

        return book_list;
}



//Creates a library with dummy data and prompts the user for input.
int main() {
    vector<Item *>item_list = generate_test_books();
    Catalog* catalog = new Catalog(item_list);

    Library my_epic_library(catalog);
    my_epic_library.display_library_menu();
    delete catalog;


//    deleteVectorOfPointers(item_list);
    //is book_list causing a memory leak? Now it's not
    return 0;
}
