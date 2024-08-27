
#pragma once

#include <vector>
#include "bidder.hpp"

using namespace std;

/*
The auctioneer acts as the "subject". This class is responsible for
tracking the highest bid and notifying the bidders if it changes.
*/
class Auctioneer {
    vector<Bidder *> bidders;
private:
    double highest_bid = 0; // Tracks the current highest bid in the auction
    Bidder *highest_bidder = nullptr; // Points to the Bidder object that has the current highest bid

public:
    // Constructor declaration (defined as default)
    Auctioneer() = default;

    // Getter for the list of bidders
    const vector<Bidder *> &getBidders() const;

    // Getter for the highest bid
    double getHighestBid() const;

    // Setter for the highest bid
    void setHighestBid(double highestBid);

    // Getter for the highest bidder
    Bidder *getHighestBidder() const;

    // Setter for the highest bidder
    void setHighestBidder(Bidder *highestBidder);

    /*
    Registers a new bidder to participate in the auction.
    :param bidder: A pointer to a Bidder object that wishes to join the auction.
     */
    void register_bidder(Bidder *bidder);

    /*
    Resets the auctioneer to its initial state. This is typically used to start a new auction. It clears the list of bidders and sets the highest bid to 0.
     */
    void reset_auctioneer();

    /*
    Notifies all registered bidders of a change in the highest bid. Each bidder is given the opportunity to respond to the new highest bid by placing a higher bid.
     */
    void notify_bidders();

    /*
    Accepts a new bid and, if it is higher than the current highest bid, updates the highest bid and the highest bidder. All bidders are then notified of the new highest bid.
    :param bid: The value of the new bid being placed.
    :param bidder: A pointer to the Bidder object placing the new bid. Defaults to nullptr if not provided.
    :precondition bid: The new bid must be higher than the current highest bid to be accepted.
    */
    void accept_bid(double bid, Bidder *bidder = nullptr);
};


