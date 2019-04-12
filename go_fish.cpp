// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdio>
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
    freopen("gofish_results.txt", "w", stdout);

    int numCards;	// number of cards to deal depending on amount of players
    int numPlayers = 0;

    Player p1("Joe");
    numPlayers++;
    Player p2;
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

    // start of the game
    // loop through until there is a winner
    bool winner = false;
    bool foundPair;

    Card bookCard1;
    Card bookCard2;

    Card chosenCard;
    Card matchingCard;

    while(!winner){
        // current player chooses card
        chosenCard = p1.chooseCardFromHand();

        cout << p1.getName() << " asks " << p2.getName() << " do you have any " << chosenCard.rankString(chosenCard.getRank()) << "'s?"<< endl;

        // current player asks
        foundPair = p2.sameRankInHand(chosenCard);

        // asks until they get it wrong
        while(foundPair){
            cout << "Yes!" << endl;

            matchingCard = p2.removeCardFromHand(chosenCard);

            p1.addCard(matchingCard);
            p1.bookCards(chosenCard, matchingCard);

            // check if the current player's hand is empty
            if(p1.getHandSize()){
                // if found, take the card and book them
                chosenCard = p1.chooseCardFromHand();

                cout << p1.getName() << " asks " << p2.getName() << " do you have any " << chosenCard.rankString(chosenCard.getRank()) << "'s?"<< endl;

                // current player asks
                foundPair = p2.sameRankInHand(chosenCard);
            }
            else{
                foundPair = false;
            }
        }
        cout << "No, Go Fish!" << endl;

        // current player draws a card
        p1.addCard(d.dealCard());

        if(p1.checkHandForBook(bookCard1, bookCard2)){
            p1.bookCards(bookCard1, bookCard2);
        }

        if(d.size()==0){
            winner = true;
        }

        //-----------------------------------------------------------------------------------

        // current player chooses card
        chosenCard = p2.chooseCardFromHand();

        cout << p2.getName() << " asks " << p1.getName() << " do you have any " << chosenCard.rankString(chosenCard.getRank()) << "'s?"<< endl;

        // current player asks
        foundPair = p1.sameRankInHand(chosenCard);


        // asks until they get it wrong
        while(foundPair){
            cout << "Yes!" << endl;

            matchingCard = p1.removeCardFromHand(chosenCard);

            p2.addCard(matchingCard);
            p2.bookCards(chosenCard, matchingCard);

            // check if the current player's hand is empty
            if(p2.getHandSize()){
                // if found, take the card and book them
                chosenCard = p2.chooseCardFromHand();

                cout << p1.getName() << " asks " << p2.getName() << " do you have any " << chosenCard.rankString(chosenCard.getRank()) << "'s?"<< endl;

                // current player asks
                foundPair = p1.sameRankInHand(chosenCard);
            }
            else{
                foundPair = false;
            }
        }
        cout << "No, Go Fish!" << endl;

        // current player draws a card
        p2.addCard(d.dealCard());

        if(p2.checkHandForBook(bookCard1, bookCard2)){
            p2.bookCards(bookCard1, bookCard2);
        }

        if(d.size()==0){
            winner = true;
        }

        cout << endl;

    }
    cout << p1.getName() << " : Book : " << p1.showBooks() << endl;
    cout << p2.getName() << " : Book : " << p2.showBooks() << endl;

    if(p1.getBookSize()>p2.getBookSize()){
        cout << p1.getName() << " has won!" << endl;
    }
    else if(p1.getBookSize()>p2.getBookSize()){
        cout << p2.getName() << " has won!" << endl;
    }
    else{
        cout << p1.getName() << " and " << p2.getName() << " have tied!" << endl;
    }

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


