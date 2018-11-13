//
// Created by agult on 11/5/2018.
//

#include "player.h"

void Player::addCard(Card c)
{
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);
    //this->myHand.erase(myHand.end(), myHand.end()-2);
}

bool Player::checkHandForBook(Card &c1, Card &c2)
{
    vector<Card>::const_iterator iter, iter1;
    int i=0;
    Card c;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++) {
        c=*(myHand.begin()+i);
        int j=0;
        for(iter1=myHand.begin(); iter1!=myHand.end(); iter1++) {
            if(i!=j) {
                if (c.getRank() == (*(myHand.begin() + j)).getRank()) {
                    c1 = c;
                    c2 = *(myHand.begin() + j);
                    //removeCardFromHand(c);
                    //removeCardFromHand(*(myHand.begin() + j));
                    return true;
                }
            }
            j++;
        }
        i++;
    }
    return false;
}

bool Player::rankInHand(Card c)const
{
    int rank=c.getRank();
    vector<Card>::const_iterator iter;
    int i=0;
    Card c1;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++) {
        c1=*(myHand.begin()+i);
        int r1=c1.getRank();
        if(r1==rank){
            return true;
        }
        i++;
    }
    return false;
}

Card Player::chooseCardFromHand()const
{
    if(getHandSize()==0){
        return *myBook.begin();
    }
    return *myHand.begin();
}

bool Player::cardInHand(Card c)const
{
    vector<Card>::const_iterator iter;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++){
        if(*iter==c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c)
{
    vector<Card>::const_iterator iter;
    int i=0;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++){
        if(*iter==c){
            myHand.erase(myHand.begin()+i);
            return c;
        }
        i++;
    }
    return c;
}

Card Player::removeRankFromHand(Card c)
{
    vector<Card>::const_iterator iter;
    int i=0;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++){
        if(iter->getRank()==c.getRank()){
            Card c1=*iter;
            myHand.erase(myHand.begin()+i);
            return c1;
        }
        i++;
    }
    return c;
}

string Player::showHand()const
{
    vector<Card>::const_iterator iter;
    Card c;
    string s, s1;
    int i=0;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++) {
        c=*(myHand.begin()+i);
        s1=c.toString();
        if(i!=0) {
            s+=", ";
        }
        s += s1;
        i++;
    }
    return s;
}

string Player::showBooks()const
{
    vector<Card>::const_iterator iter;
    Card c1, c2;
    string s, s1, s2;
    int i=0;
    for(iter=myBook.begin(); myBook.begin()+i!=myBook.end(); iter++) {
        c1=*(myBook.begin()+i);
        s1=c1.toString();
        c2=*(myBook.begin()+i+1);
        s2=c2.toString();
        if(i!=0) {
            s+=", ";
        }
        s += (s1+s2);
        i+=2;
    }
    return s;
}

int Player::getHandSize()const
{
    int size=myHand.size();
    return size;
}

int Player::getBookSize()const
{
    int size=myBook.size()/2;
    return size;
}

/*bool Player::checkHandForPair(Card &c1, Card &c2)
{

}*/

bool Player::sameRankInHand(Card c)const
{
    int rank=c.getRank();
    vector<Card>::const_iterator iter;
    int i=0;
    Card c1;
    for(iter=myHand.begin(); iter!=myHand.end(); iter++) {
        c1=*(myHand.begin()+i);
        int r1=c1.getRank();
        if(r1==rank){
            return true;
        }
        i++;
    }
    return false;
}