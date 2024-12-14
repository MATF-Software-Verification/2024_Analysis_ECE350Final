#pragma once
#include <iostream>

using namespace std;

class Card{
public:
  Card(){ val = 'X'; suit = 'X'; }; //default constructor, should not be called
  Card(char v, char s){ val = v; suit = s; }; //constructor
  char getSuit(){ return suit; };
  char getValue(){ return val; };
  int getNumValue();
  bool setSuit(char);
  bool setVal(char);
  bool setVal(int);
  void print();
  bool isEmpty();
      
  //ja dodala
bool operator==(const Card& other) const{
     //return this->getSuit() == other.getSuit() && this->getValue() == other.getValue();
     return (val == other.val && suit == other.suit);
}
bool operator!=(const Card& other) const {
    return !(*this == other);
}
bool operator<(const Card& other) const{
    return (val < other.val);
}/*
bool operator<(const Card& other) const {
    if (suit != other.suit) {
        return suit < other.suit;
    }
    return val < other.val;
}
*/
private:
  char val, suit;
  
};
