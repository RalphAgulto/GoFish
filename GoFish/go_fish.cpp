//
// Created by agult on 11/5/2018.
//
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
        ofstream myFile ("GoFish_results.txt");

        int numCards = 5;

        Player p1("Joe");
        Player p2("Jane");

        Deck d;  //create a deck of cards
        d.shuffle();

        dealHand(d, p1, numCards);
        dealHand(d, p2, numCards);
        cout << p1.getName() <<" has : " << p1.showHand() << endl;
        myFile << p1.getName() <<" has : " << p1.showHand() << endl;
        cout << p2.getName() <<" has : " << p2.showHand() << endl;
        myFile << p2.getName() <<" has : " << p2.showHand() << endl;

        Card c1;
        Card c2;

        while(p1.checkHandForBook(c1,c2)){ //checks p1's hand for book
            p1.bookCards(p1.removeCardFromHand(c1),p1.removeCardFromHand(c2)); //removes pair and adds into book
            cout << p1.getName() << " books " << c1 << " and " << c2 << endl; //prints pair
            myFile << p1.getName() << " books " << c1 << " and " << c2 << endl;
        }
        while(p2.checkHandForBook(c1,c2)){ //check p2's hand for book
            p2.bookCards(p2.removeCardFromHand(c1),p2.removeCardFromHand(c2)); //remove pair and adds into book
            cout << p2.getName() << " books " << c1 << " and " << c2 << endl; //prints pair
            myFile << p2.getName() << " books " << c1 << " and " << c2 << endl;
        }

        //main engine
        while((p1.getBookSize() + p2.getBookSize()) != 26){
            //player 1 turn
                cout << p1.getName() << " asks, Do you have a " << p1.chooseCardFromHand().rankString(
                        p1.chooseCardFromHand().getRank())<< "?" << endl;
                myFile << p1.getName() << " asks, Do you have a " << p1.chooseCardFromHand().rankString(
                    p1.chooseCardFromHand().getRank())<< "?" << endl;
                if (p2.sameRankInHand(p1.chooseCardFromHand())) { //case of player with same rank
                    Card temp = p2.removeRankFromHand(p1.chooseCardFromHand());
                    cout << p2.getName() << " says, Yes I have a " << temp.getRank() << endl;
                    myFile << p2.getName() << " says, Yes I have a " << temp.getRank() << endl;
                    p1.addCard(temp);
                } else { //go fish
                    if (d.size()) {
                        cout << p2.getName() << " says, Go Fish" << endl;
                        myFile << p2.getName() << " says, Go Fish" << endl;
                        Card tempCard = d.dealCard();
                        cout << p1.getName() << " draws " << tempCard << endl;
                        myFile << p1.getName() << " draws " << tempCard << endl;
                        p1.addCard(tempCard);
                    } else { //no cards left in deck
                        cout << "No cards in the deck." << endl;
                        myFile << "No cards in the deck." <<  endl;
                    }
                }
                while (p1.checkHandForBook(c1, c2)) { //check p1's hand for book
                    p1.bookCards(p1.removeCardFromHand(c1),
                                 p1.removeCardFromHand(c2)); //removes pair and adds into book
                    cout << p1.getName() << " booked " << c1 << " and " << c2 << endl;
                    myFile << p1.getName() << " booked " << c1 << " and " << c2 << endl;
                }
                cout << p1.getName() << " has : " << p1.showHand() << endl;//shows current hand
                myFile << p1.getName() << " has : " << p1.showHand() << endl;
                cout << p1.getName() << " has : " << p1.getBookSize() << " books; " << p1.showBooks() << endl
                     << endl;//shows books
                myFile << p1.getName() << " has : " << p1.getBookSize() << " books; " << p1.showBooks() << endl
                 << endl;
                cout<< p2.getName() << "'s turn" << endl;
                myFile<< p2.getName() << "'s turn" << endl;

//player2 turn
         cout << p2.getName() << " asks, Do you have a " << p2.chooseCardFromHand().rankString(p2.chooseCardFromHand().getRank()) << "?" << endl;
         myFile << p2.getName() << " asks, Do you have a " << p2.chooseCardFromHand().rankString(p2.chooseCardFromHand().getRank()) << "?" << endl;
                    if(p1.sameRankInHand(p2.chooseCardFromHand())){ //case of player with same rank
                        Card temp = p1.removeRankFromHand(p2.chooseCardFromHand());
                        cout << p1.getName() << " says, Yes I have a " << temp.getRank() << endl;
                        myFile << p1.getName() << " says, Yes I have a " << temp.getRank() << endl;
                        p2.addCard(temp);
                    }
                    else{ //go fish
                        if(d.size()){
                            cout << p1.getName() << " says, Go Fish" << endl;
                            myFile << p1.getName() << " says, Go Fish" << endl;
                            Card tempCard = d.dealCard();
                            cout << p2.getName() << " draws " << tempCard << endl;
                            myFile << p2.getName() << " draws " << tempCard << endl;
                            p2.addCard(tempCard);
                        }
                        else{ //no cards left in deck
                            cout << "No cards in the deck. " << endl;
                            myFile << "No cards in the deck. " << endl;
                        }
                    }
                    while(p2.checkHandForBook(c1,c2)){ //check p1's hand for book
                        p2.bookCards(p2.removeCardFromHand(c1),p2.removeCardFromHand(c2)); //removes pair and adds into book
                        cout << p2.getName() << " booked " << c1 << " and " << c2 << endl;
                        myFile << p2.getName() << " booked " << c1 << " and " << c2 << endl;
                    }
                    cout << p2.getName() <<" has : " << p2.showHand() << endl; //shows current hand
                    myFile << p2.getName() <<" has : " << p2.showHand() << endl;
                    cout << p2.getName() <<" has : " << p2.getBookSize() << " books; " << p2.showBooks() << endl << endl;//shows books
                    myFile << p2.getName() <<" has : " << p2.getBookSize() << " books; " << p2.showBooks() << endl << endl;
                    if((p1.getBookSize() + p2.getBookSize()) != 26) {
                        cout << p1.getName() << "'s turn" << endl;
                        myFile << p1.getName() << "'s turn" << endl;
                    }
            }


        cout << endl;
        myFile << endl;
        cout << p1.getName() << "'s books : " << p1.showBooks() << endl; //prints p1's list of books
        myFile << p1.getName() << "'s books : " << p1.showBooks() << endl;
        cout << p2.getName() << "'s books: " << p2.showBooks() <<endl; //prints p2's list of books
        myFile << p2.getName() << "'s books: " << p2.showBooks() <<endl;
        if(p1.getBookSize() > p2.getBookSize()){
            cout << p1.getName() << " wins with " << p1.getBookSize() << " books." << endl;//p1 wins
            myFile << p1.getName() << " wins with " << p1.getBookSize() << " books." << endl;
        }
        else if(p1.getBookSize() < p2.getBookSize()) {
            cout << p2.getName() << " wins with " << p2.getBookSize() << " books.";//p2 wins
            myFile << p2.getName() << " wins with " << p2.getBookSize() << " books.";
        }
        else{
            cout << p2.getName() << " and " << p1.getName() << " tie with an equal amount of books." << endl;//tie
            myFile << p2.getName() << " and " << p1.getName() << " tie with an equal amount of books.";
        }
        return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}




