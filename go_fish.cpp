// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>     // Allows to write into result file
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    int numCards;	// number of cards to deal depending on amount of players
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

    Deck d; 	 //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    dealHand(d, p3, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    cout << p3.getName() <<" has : " << p3.showHand() << endl;

    
    // create stream to write into result file
    ofstream result_file;
    result_file.open("gofish_results.txt");

    result_file << "Players are " << p1.getName() << ", " << p2.getName() << ", " << p3.getName() << endl << endl;	// print players names in order
    result_file << "Results of Go Fish Game:\n\n";


    // start of the game
    // loop through until there is a winner
    bool winner = false;

    while(!winner){
	Card c1(13, Card::hearts);
	Card c2(13, Card::spades);

	p1.addCard(c1);
	p1.addCard(c2);

	
	Card c3;
	Card c4;

	bool foundPair = p1.checkHandForBook(c3, c4);

	if(foundPair){
	    cout << "found a pair\n";
	}

       
	cout << c3 << " and " << c4 << " are a pair" << endl;

	winner = true;
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


