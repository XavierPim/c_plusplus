
#include <iostream>
#include "Catalog.hpp"
#include "Item.hpp"
#include "ItemGenerator.hpp"
#include <limits>

void Catalog::clean_cin() {
    cin.clear(); //clearing out bad bits
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clearing garbage in buffer
}

vector<Item *> Catalog::find_items(string title) {
    vector<Item *> title_list;
    for (Item *library_book: item_list) {
        if (title == library_book->get_title()) {
            title_list.push_back(library_book);
        }
    }
    return title_list;
}

bool Catalog::reduce_item_count(string call_number) {
    Item *library_book = retrieve_item_by_call_number(call_number);
    if (library_book != nullptr) {
        library_book->decrement_number_of_copies();
        return true;
    }
    return false;
}

bool Catalog::increment_item_count(string call_number) {
    return false;
}

void Catalog::display_available_items() {
    cout << "Books List" << endl;
    cout << "--------------" << endl << endl;
    for (Item *library_book: item_list) {
        cout << *library_book << endl;
    }
}

void Catalog::remove_item(string call_number) {
    Item *found_book = retrieve_item_by_call_number(call_number);
    if (found_book != nullptr) {
        cout << "Successfully removed " << found_book->get_title() <<
             " with call number: " << found_book->get_call_number() << endl;

        for (size_t i = 0; i < item_list.size(); i++) {
            if (item_list[i] == found_book) {
                item_list.erase(item_list.begin() + i);
                break;
            }
        }
        delete found_book;
    } else {
        cout << "book with call number: " << call_number << " not found." << endl;
    }
}

void Catalog::add_item() {
    cout << "Enter the type of item (1 for Book, 2 for DVD, 3 for Journal): " << endl;
    int item_type;
    cin >> item_type;

    if (item_type < 1 || item_type > 3) {
        cout << "Invalid item type." << endl;
        return;
    }

    cout << "Enter Call Number: " << endl;
    string call_number;
    cin >> call_number;

    cout << "Enter title: " << endl;
    string title;
    clean_cin();
    getline(cin, title);

    cout << "Enter number of copies (positive number): " << endl;
    int num_copies;
    cin >> num_copies;

    Item* new_item = nullptr;

    if (item_type == 1) {
        cout << "Enter Author Name: " << endl;
        string author;
        clean_cin();
        getline(cin, author);
        new_item = ItemGenerator::generateItem(item_type, call_number, title, num_copies, author);
    } else if (item_type == 2) {
        cout << "Enter the number of CDs: " << endl;
        int num_CDs;
        cin >> num_CDs;
        new_item = ItemGenerator::generateItem(item_type, call_number, title, num_copies, "", num_CDs);
    } else if (item_type == 3) {
        cout << "Enter Journal Author: " << endl;
        string author;
        clean_cin();
        getline(cin, author);
        new_item = ItemGenerator::generateItem(item_type, call_number, title, num_copies, author);
    }

    if (new_item) {
        bool found_item = retrieve_item_by_call_number(new_item->get_call_number());
        if (found_item) {
            cout << "Could not add item with call number " << new_item->get_call_number()
                 << ". It already exists." << endl;
            delete new_item; // Clean up memory
        } else {
            item_list.push_back(new_item);
            cout << "Item added successfully! Item details:" << endl;
            cout << *new_item;
        }
    }
}



Item *Catalog::retrieve_item_by_call_number(string call_number) {
    Item *found_book = nullptr;
    for (Item *library_book: item_list) {
        if (library_book->get_call_number() == call_number) {
            found_book = library_book;
            break;
        }
    }
    return found_book;
}

const vector<Item *> &Catalog::getItemList() const {
    return item_list;
}


