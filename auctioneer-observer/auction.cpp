
#include "auction.hpp"

Auction::Auction(vector<Bidder *> bidders) {
    int option;
    srand(time(0));
    do {
        cout << "Would you like to add new bidders? \n 1: Yes\n 2: No" << endl;
        cin >> option;

        switch (option) {
            case ONE: {
                string name;
                double budget;
                double bid_probs;
                double bid_inc_perc;


                cout << "New bidder's name:" << endl;
                cin >> name;
                cout << "New bidder's budget:" << endl;
                cin >> budget;
                cout << "New bidder's bid increase %:" << endl;
                cin >> bid_inc_perc;

                // Generate a random value for bid_probs
                bid_probs = generateRandom(MIN_BID, MAX_BID);
                cout << "New bidder's bid % threshold will be: " << bid_probs << endl;

                Bidder *newGuy = new Bidder(name, budget, bid_probs, bid_inc_perc);
                bidders.push_back(newGuy);
                break;
            }

            case TWO: {
                string item;
                double start_price;
                for (Bidder *bidder: bidders) {
                    newAuctioneer.register_bidder(bidder);
                }
                cout << "What item are we auctioning: ";
                cin >> item;
                cout << "What is the starting price: ";
                cin >> start_price;
                simulate_auction(item, start_price);
                break;
            }
            default:
                cout << "Invalid option. Please enter 1 or 2." << endl;
        }
    } while (option != TWO);
}

void Auction::simulate_auction(string item, double start_price) {
    cout << "Auction for " << item << " starting at $" << start_price << "\n" << endl;
    newAuctioneer.accept_bid(start_price, newAuctioneer.getBidders().at(0));
    cout << "\nThe " << item << " goes to " << newAuctioneer.getHighestBidder()->getName()
         << " for $" << newAuctioneer.getHighestBid() << endl;
    for (Bidder *bidder: newAuctioneer.getBidders()) {
        cout << *bidder << endl;
    }
}





