// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "Card.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{
    int numCards;
    int numPlayers = 0;

    Player p1("Joe");
    numPlayers++;
    Player p2("Jane");
    numPlayers++;
    Player p3;
    numPlayers++;

    if(numPlayers>2){
        numCards=5;
    }
    else{
        numCards=7;
    }

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    dealHand(d, p3, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    cout << p3.getName() <<" has : " << p3.showHand() << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


