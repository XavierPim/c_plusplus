#pragma once

#include <iostream>
#include <random>

using namespace std;

class Auctioneer; //forward declaration

inline double generateRandom(double min_value, double max_value) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_real_distribution<double> uni(min_value, max_value);
    return uni(rng);
}

class Bidder {
    const double MIN_BID = 0;
    const double MAX_BID = 100;
    string name;
public:
    const string &getName() const;

    ~Bidder() {
        cout << name << " left auction" << endl;
    };
    double getHighestBid() const;
    double getBudget() const;
private:
    double budget;
    double bid_probability;
    double bid_increase_perc;
    double highest_bid;

public:
    Bidder(string name, double budget = 100, double bid_probability = 0.35, double bid_increase_perc = 1.1) :
            name(name), budget(budget), bid_probability(bid_probability), bid_increase_perc(bid_increase_perc),
            highest_bid(0) {}

    /*
     * update is called by the auctioneer when they need to notify
     * the bidder of something important
     */
    void update(Auctioneer *auctioneer);

    /*
     * The toBidOrNot method determines whether the bidder will attempt to make a bid based on a random
     * chance compared to their bid probability.
     */
    bool toBidOrNot();

// Overloads the << operator to allow easy printing of Bidder objects to an output stream
    friend ostream &operator<<(ostream &os, const Bidder &bidder) {
        os << "Bidder: "<< bidder.name
        <<", Highest Bid: "<< bidder.getHighestBid();
        return os;
    }
};

