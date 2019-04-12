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
    int round = 1;

    Card bookCard1;
    Card bookCard2;
   
    Player* p[3] = {&p1, &p2, &p3};
    int playerIndex = 0;
    Player currPlayer;	// initialize who goes first
    Player nextPlayer;	// player that is being asked

    while(!winner){
	currPlayer = *p[playerIndex];
	nextPlayer = *p[playerIndex+1];

        while(p1.checkHandForBook(bookCard1, bookCard2)){
	    p1.bookCards(bookCard1, bookCard2);
	}
        while(p2.checkHandForBook(bookCard1, bookCard2)){
	    p2.bookCards(bookCard1, bookCard2);
	}
	while(p3.checkHandForBook(bookCard1, bookCard2)){
	    p3.bookCards(bookCard1, bookCard2);
	}

	cout << "Player 1 books\n";
	cout << p1.showBooks() << endl;

	cout << "Player 2 books\n";
	cout << p2.showBooks() << endl;

	cout << "Player 3 books\n";
	cout << p3.showBooks() << endl;

	cout << "Player 1 hand\n";
	cout << p1.showHand() << endl;

	cout << "Player 2 hand\n";
	cout << p2.showHand() << endl;

	cout << "Player 3 hand\n";
	cout << p3.showHand() << endl;

	
	// current player chooses card
	Card chosenCard = currPlayer.chooseCardFromHand();
cout << chosenCard << endl;

        result_file << currPlayer.getName() << " asked " << nextPlayer.getName() << " for a " << chosenCard << endl;
	// current player asks
	bool foundPair = nextPlayer.sameRankInHand(chosenCard);
        Card matchingCard;

	// asks until they get it wrong
	while(foundPair){	

	    matchingCard = nextPlayer.removeCardFromHand(chosenCard);
	    currPlayer.bookCards(chosenCard, matchingCard);
	    
	    result_file << nextPlayer.getName() << " gives " << currPlayer.getName() << " the " << matchingCard << endl;

	    // check if the current player's hand is empty
	    if(currPlayer.getHandSize()){
	    	// if found, take the card and book them
            	chosenCard = currPlayer.chooseCardFromHand();
            
                result_file << currPlayer.getName() << " asked " << nextPlayer.getName() << " for a " << chosenCard << endl;
	    	// current player asks
            	foundPair = nextPlayer.sameRankInHand(chosenCard);
	    }
	    else{
	        foundPair = false;
	    }
	}

	// once current player has to go fish	
        result_file << nextPlayer.getName() << " says go fish" << endl;
	    
        // current player draws a card
        currPlayer.addCard(d.dealCard());



	// Joe's Turn
	
        (playerIndex+1) % 3;
	winner = true;
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


