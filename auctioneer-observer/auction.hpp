
#pragma once

#include "bidder.hpp"
#include "auctioneer.hpp"

#include <vector>


/*
Simulates an auction. Is responsible for driving the auctioneer and
        the bidders.
*/

class Auction {
public:
    enum magicNumbers {
        ONE = 1, TWO = 2, MIN_BID = 0, MAX_BID = 100
    };
    /*
     * singleton instance of auctioneer*/
    Auctioneer newAuctioneer;

    /*
    Initialize an auction. Requires a list of bidders that are
    attending the auction and can bid.
    :param bidders: vector of Bidder pointers
    */
    Auction(vector<Bidder *> bidders);

    /*
    Starts the auction for the given item at the given starting
    price. Drives the auction till completion and prints the results.
    :param item: string, name of item.
    :param start_price: float
     */
    void simulate_auction(string item, double start_price);

};
