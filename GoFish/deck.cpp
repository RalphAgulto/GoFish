//
// Created by agult on 11/5/2018.
//

#include "deck.h"
#include "card.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <time.h>

Deck::Deck()
{
    int idx=0;
    srand(unsigned(time(NULL)));
    for(int i=0; i<4; i++) {
        for (int j = 1; j < 14; j++) {
            Card c(j, (Card::Suit) i);
            myCards[idx] = c;
            idx++;
        }
    }
    myIndex=0;
}

void Deck::shuffle()
{
    int k=250;
    while(k!=0){
        int l=rand()%52;
        Card temp=myCards[l];
        Card temp2=myCards[0];
        myCards[0]=temp;
        myCards[l]=temp2;
        k--;
    }
}

Card Deck::dealCard()
{
    Card c;
    c=this->myCards[myIndex];
    this->myIndex++;
    return c;
}

int Deck::size()const
{
    return SIZE-this->myIndex;
}

