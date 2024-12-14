#include <iostream>
#include "Card.h"

using namespace std;

int Card::getNumValue(){
  int card; //to store numerical value

  switch(val){ //use char representing value
  case 'A':
    card = 14;
    break;
  case 'K':
    card = 13;
    break;
  case 'Q':
    card = 12;
    break;
  case 'J':
    card = 11;
    break;
  case '0':
    card = 10;
    break;
  case 'X':
      card = -1;
      break;
  default: //for any other value, conver the char to int by subtracting 48 from the ASCII code
    card = (int)val - 48;
    break;
  }
  return card;
}

bool Card::setSuit(char s){
  
  switch(s){
  case 'H':
  case 'h':
    suit = 'H';
    break;
  case 'D':
  case 'd':
    suit = 'D';
    break;
  case 'C':
  case 'c':
    suit = 'C';
    break;
  case 'S':
  case 's':
    suit = 'S';
    break;
  case 'X':
      suit = 'X';
      break;
  default: //if invalid suit
    return false; 
  }
  return true; //if successful
}
//za setValue(char), koristim fju setValue(int)
//ovde sam uocila bag, a to je da je moguce bilo postaviti da  neki nevalidan char npr 'x' ili '@' bude isto postavljen, sto ne bi trebalo
//pokrivenost testovima je 100% sada
//Koriste se karte od 6-14, pa je i to promenjeno
bool Card::setVal(char value){

  if((value - '0') >= 6 && (value - '0') <= 9){
  return setVal(value - '0');
  }
   if(value == '0'){
      return setVal(10);
   }
   if(value == 'J'){
      return setVal(11);
   }

  if(value == 'Q'){
      return setVal(12);
  }
  if(value == 'K'){
      return setVal(13);
  }
  if(value == 'A'){
      return setVal(14);
  }
  if(value == 'X'){
      return setVal(-1);
}
  return false;
}

bool Card::setVal(int value){
  //1 thru 9, normal. ten is represented with 0. face cards A, K, Q, J are 14, 13, 12, 11
//  if(value > 14 || value < 0) //out of range
 //   return false;
  if(value >= 6 && value <= 9) {
      val = value + 48;
      return true;
}
  switch(value){
  case 10:
    val = '0';
    return true;
  case 11:
    val = 'J';
    return true;
  case 12:
    val = 'Q';
    return true;
  case 13:
    val = 'K';
    return true;
  case 14:
    val = 'A';
    return true;
  case -1:
      val = 'X';
      return true;

  }
  return false;
}

void Card::print(){
  if(val == '0')
    cout << "10";
  else
    cout << val;
  
  cout << " of ";
  switch(suit){
  case 'H':
    cout << "hearts ";
    break;
  case 'D':
    cout << "diamonds ";
    break;
  case 'S':
    cout << "spades ";
    break;
  case 'C':
    cout << "clubs ";
    break;
  }
}
bool Card::isEmpty() {
    return val == 'X' && suit == 'X';
}
