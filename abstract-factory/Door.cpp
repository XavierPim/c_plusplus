#include "Door.hpp"

void DystopianDoor::addRoomA(Room *A) {
    // Check the type of room if needed
    DystopianRoom *dystopianRoom = dynamic_cast<DystopianRoom *>(A);
    if (dystopianRoom) {
        this->A = dystopianRoom;
    }
}

void DystopianDoor::addRoomB(Room *B) {
    // Check the type of room if needed
    DystopianRoom *dystopianRoom = dynamic_cast<DystopianRoom *>(B);
    if (dystopianRoom) {
        this->B = dystopianRoom;
    }
}

void DystopianDoor::printDoor(int id) {
    cout << "This door has a pipe for a handle\n" <<
         "This door connects Dystopian Room " << id << " and Dystopian Room  " << ++id<< endl;
}


void FairyDoor::addRoomA(Room *A) {
    // Check the type of room if needed
    FairyRoom *fairyRoom = dynamic_cast<FairyRoom *>(A);
    if (fairyRoom) {
        this->A = fairyRoom;
    }
}

void FairyDoor::addRoomB(Room *B) {
    // Check the type of room if needed
    FairyRoom *fairyRoom = dynamic_cast<FairyRoom *>(B);
    if (fairyRoom) {
        this->B = fairyRoom;
    }
}

void FairyDoor::printDoor(int id) {
    cout << "This door has a fairy wing for a handle\n" <<
         "This door connects fairy Room " << id << " and fairy Room " << ++id << endl;
}
