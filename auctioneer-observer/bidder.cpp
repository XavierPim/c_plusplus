#include "Auctioneer.hpp"
#include "bidder.hpp"

void Bidder::update(Auctioneer *auctioneer) {
    double potentialBid = auctioneer->getHighestBid() *  bid_increase_perc;
    bool iCanBid = budget >= potentialBid; // Check if the bidder has enough budget to place the new bid

    if (toBidOrNot() && iCanBid) {
        highest_bid = potentialBid; // The new bid is based on the highest bid plus the increase percentage
        budget -= highest_bid; // Deduct the bid from the budget

        // Check if there's a highest bidder before trying to print their name
        if (auctioneer->getHighestBidder() != nullptr) {
            cout << name << " bidded $" << highest_bid << " in response to "
                 << auctioneer->getHighestBidder()->name << "\'s bid of $"
                 << auctioneer->getHighestBid() << endl;
        } else {
            cout << name << " bidded " << highest_bid << " at the starting bid's bid of "
            << auctioneer->getHighestBid()<< endl;
        }

        auctioneer->setHighestBid(highest_bid);
        auctioneer->setHighestBidder(this);
    } else {
//        cout << name << " cannot bid or chooses not to bid." << endl;
    }
}


const string &Bidder::getName() const {
    return name;
}

double Bidder::getHighestBid() const {
    return highest_bid;
}

bool Bidder::toBidOrNot() {
    // Generate a random value between MIN_BID and MAX_BID
    double randomValue = generateRandom(MIN_BID, MAX_BID);

    // Compare the random value to bid_probability
    return randomValue <= bid_probability;
}

double Bidder::getBudget() const {
    return budget;
}

