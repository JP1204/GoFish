//
// Created by peter on 4/4/2019.
//

#include "card.h"
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
    switch (s) {
        case spades:
            return "Spades";
        case hearts:
            return "Hearts";
        case diamonds:
	    return "Diamonds";
        case clubs:
            return "Clubs";
        default:
            return "Invalid Suit";
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


// outputs the Suit and the Rank
ostream& operator << (ostream& out, const Card &c){
    out << c.toString();
    return out;
}

