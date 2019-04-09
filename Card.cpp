//
// Created by peter on 4/4/2019.
//

#include "Card.h"
#include <string>

Card::Card(){
    this->myRank = 1;
    this->mySuit = spades;
}

Card::Card(int rank, Suit s){
    this->myRank = rank;
    this->mySuit = s;
}

string Card::toString() const{
    return rankString(myRank) + " of " + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const{
    return this->mySuit == c.mySuit;
}

int Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const {
    string card = "Invalid Suit.";

    switch (s) {
        case 0:
            card = "Spades";
            return card;
        case 1:
            card = "Hearts";
            return card;
        case 2:
            card = "Diamonds";
            return card;
        case 3:
            card = "Clubs";
            return card;
        default:
            return card;
    }
}

string Card::rankString(int r) const{
    if(r<=NUM_CARDS&&r>0){
        return Rank[r-1];
    }
    else{
        return "Invalid Rank";
    }
}

bool Card::operator == (const Card& rhs) const{

    return this->toString() == rhs.toString();

}

bool Card::operator != (const Card& rhs) const{

    return this->toString() != rhs.toString();

}