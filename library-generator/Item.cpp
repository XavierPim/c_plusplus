#include "Item.hpp"

bool Item::check_availability() const {
    if (num_copies > 0) {
        return true;
    } else {
        return false;
    }
}

