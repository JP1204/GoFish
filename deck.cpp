//
// Created by peter on 4/4/2019.
//

#include "deck.h"
#include <chrono>


Deck::Deck(){
    myIndex = 0;

    // creates the sorted deck
    for(int i = 0; i <= 3; i++){
	auto suit = (Card::Suit) i;

        for(int j = 1; j<=13; j++){
            Card c(j, suit);
            myCards[myIndex]=c;
            myIndex++;
        }
    }
}

void Deck::shuffle(){
    srand((unsigned)time(nullptr));

    for(int i = 0; i<SIZE; i++){
        Card temp;
        int r = rand()%SIZE;
        temp = myCards[r];
        myCards[r] = myCards[i];
        myCards[i] = temp;
    }

}

Card Deck::dealCard(){
    Card c;

    if(myIndex>0){
        myIndex--;
        c = myCards[myIndex];
    }
    else{
        cout<< "The Deck is Empty." << endl;
    }
    return c;
}

int  Deck::size() const{

    return myIndex;

}
