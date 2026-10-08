

#include <ostream>
#include <string>
# pragma once


class Card {
public:
    Card(const std::string& color, const std::string& rank)
        : color_(color), rank_(rank) {
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        out << card.color_ << " " << card.rank_;
        return out;
    }

private:
    std::string color_;
    std::string rank_;
};