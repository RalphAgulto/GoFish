//
// Created by agult on 11/5/2018.
//

#include "card.h"


string Card::toString()const
{
    string s;
    string suit;
    suit=suitString(mySuit);
    s=rankString(myRank);
    s=s+suit;
    return s;
}

bool Card::sameSuitAs(const Card& c)const
{return(mySuit==c.mySuit);}

int Card::getRank()const
{return this->myRank;}

string Card::suitString(Suit s)const
{
    string p;
    if(s==spades){
        p="s";
    }
    else if(s==diamonds){
        p="d";
    }
    else if(s==hearts){
        p="h";
    }
    else if(s==clubs){
        p="c";
    }
    return p;
}

string Card::rankString(int r)const
{
    string p;
    if(r==1){
        p="A";
    }
    else if(r==2){
        p="2";
    }
    else if(r==3){
        p="3";
    }
    else if(r==4){
        p="4";
    }
    else if(r==5){
        p="5";
    }
    else if(r==6){
        p="6";
    }
    else if(r==7){
        p="7";
    }
    else if(r==8){
        p="8";
    }
    else if(r==9){
        p="9";
    }
    else if(r==10){
        p="10";
    }
    else if(r==11){
        p="J";
    }
    else if(r==12){
        p="Q";
    }
    else if(r==13){
        p="K";
    }
    return p;
    /*std::string s = std::to_string(r);
    return s;*/
}

bool Card::operator == (const Card& rhs) const
{return myRank==rhs.myRank && mySuit==rhs.mySuit;}

bool Card::operator != (const Card& rhs) const
{return !(myRank==rhs.myRank && mySuit==rhs.mySuit);}

ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString();
    return out;
}