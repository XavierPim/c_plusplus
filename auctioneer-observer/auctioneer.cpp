#include "auctioneer.hpp"

void Auctioneer::register_bidder(Bidder * newGuy) {
//    cout<<*newGuy;
    bidders.push_back(newGuy);
}

void Auctioneer::reset_auctioneer() {}

void Auctioneer::notify_bidders() {
    bool anyBidsPlaced = true;

    while (anyBidsPlaced) {
        anyBidsPlaced = false; // Assume no bids will be placed in this iteration

        for (Bidder *bidder: bidders) {
            // Skip the notification for the highest bidder to prevent self-outbidding
            if (bidder == getHighestBidder()) continue;

            double previousBudget = bidder->getBudget();
            bidder->update(this);

            // A bid was placed if the budget changed
            if (previousBudget != bidder->getBudget()) {
                anyBidsPlaced = true;
            }
        }

    }
}

void Auctioneer::accept_bid(double bid, Bidder *bidder) {
        setHighestBid(bid);
        notify_bidders();
}

double Auctioneer::getHighestBid() const {
    return highest_bid;
}

void Auctioneer::setHighestBid(double highestBid) {
    highest_bid = highestBid;
}

Bidder *Auctioneer::getHighestBidder() const {
    return highest_bidder;
}

void Auctioneer::setHighestBidder(Bidder *highestBidder) {
    highest_bidder = highestBidder;
}

const vector<Bidder *> &Auctioneer::getBidders() const {
    return bidders;
}




