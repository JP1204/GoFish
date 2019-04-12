//
// Created by peter on 4/4/2019.
//
#include "player.h"
#include <chrono>


Player::Player(){
    myName = "Jeff";
    srand((unsigned)time(nullptr));
}


Player::Player(string const &name) {
    myName = name;
    srand((unsigned)time(nullptr));
}


string Player::getName() const {
    return myName;
}


void Player::addCard(Card const&c){
    myHand.push_back(c);
}


void Player::bookCards(Card const &c1, Card const &c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}


bool Player::checkHandForBook(Card &c1, Card &c2){

    for(auto i = myHand.begin(); i!= myHand.end(); ++i){
        if((i+1)!=myHand.end()){
            for(auto j = i+1; j!=myHand.end();++j){
                if((*i).getRank()==(*j).getRank()) {
                    c1=*i;
                    c2=*j;
                    return true;
                }
            }
        }
    }
    return false;
}


bool Player::sameRankInHand(Card c) const{
    for(const auto &i : myHand){
        if(c.getRank()==(i).getRank()){
            return true;
        }
    }
    return false;
}


Card Player::chooseCardFromHand() const{
    int card = rand()%getHandSize();
    return myHand[card];
}


bool Player::cardInHand(Card c) const {
    for (const auto &i : myHand) {
        if (c.toString() == (i).toString()) {
            return true;
        }
    }
    return false;
}


Card Player::removeCardFromHand(Card c){
    int place = 0;
    Card rem;
    for (auto &i : myHand) {
        if(c.getRank() == i.getRank()) {
            rem = i;
            myHand.erase(myHand.begin() + place);
            return rem;
        }
        place++;
    }
    return c;
}


string Player::showHand() const{
    string hand;

    if(myHand.begin()==myHand.end()){
        cout << "Empty Hand" << endl;
	return hand;
    }

    for(const auto &i : myHand) {
        hand += i.toString() + ", ";
    }

    hand.pop_back();	// deletes last 2 char ", "
    hand.pop_back();


    return hand;
}


string Player::showBooks() const{
    string book;

    if(myBook.begin()==myBook.end()){
        cout << "Empty Book" << endl;
	return book;
    }

    for(const auto &i : myBook) {
        book += i.toString() + ", ";
    }

    book.pop_back();
    book.pop_back();

    return book;
}


int Player::getHandSize() const{
    int size = 0;
    for(const auto &i : myHand) {
        size++;
    }
    
    return size;

}


int Player::getBookSize() const{
    int size = 0;
    for(const auto &i : myBook) {
        size ++;
    }
    return size;
}
