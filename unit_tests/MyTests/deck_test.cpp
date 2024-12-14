#define CATCH_CONFIG_MAIN
#include<vector>
#include "../../catch.hpp"
#include "../../src/Deck.h"

bool isFinded(vector<Card>&cards,Card &card){
  bool finded = false;
   if(std::find(cards.begin(), cards.end(),card) != cards.end()){
     finded = true;
   }
   return finded;
}
 
bool isFindedInDeck(Deck &deck,Card &card){
   bool finded = false;
   vector<Card>cards = deck.getCards();
   if(std::find(cards.begin(), cards.end(),card) != cards.end()){
      finded = true;
  }
  return finded;
}

void redirectStreams(std::istringstream& fakeInput, std::ostringstream& fakeOutput, std::streambuf*& oldCin, std::streambuf*& oldCout) {
    oldCin = std::cin.rdbuf(fakeInput.rdbuf());
    oldCout = std::cout.rdbuf(fakeOutput.rdbuf());
}

void restoreStreams(std::streambuf* oldCin, std::streambuf* oldCout) {
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);
}
void validateOutput(const std::string& output, const std::vector<std::string>& expectedMessages) {
    for (const auto& message : expectedMessages) {
        REQUIRE(output.find(message) != std::string::npos);
    }
}

TEST_CASE("Testing default constructor"){
    Deck deck;
    vector<Card>cards = deck.getCards();
    Card card;
    SECTION("Testing  constructor size"){
      REQUIRE(deck.getSize() == 36);
    }    
    SECTION("Testing valid cards in deck"){
      card.setVal(6);
      card.setSuit('H');
      REQUIRE(isFinded(cards,card));
        
      card.setVal(0);
      card.setSuit('C');
      REQUIRE(isFinded(cards,card));
    }
    SECTION("Testing invalid cards in deck"){
      
      card.setVal(1);
      card.setSuit('H');
      REQUIRE(!isFinded(cards,card));
     
      card.setVal(6);
      if(!card.setSuit('m')){
      REQUIRE(true);
      }
      //ako smo uspeli da napravimo kartu, onda ima smisla proveravati da li je u spilu ili ne
      else{
      REQUIRE(!isFinded(cards,card));
      }
    }
}
TEST_CASE("Testing constuctor with vector cards"){
    vector<Card> cards;
    cards.push_back(Card('0','H'));
    cards.push_back(Card('J','S'));
    cards.push_back(Card('A','C'));
    Deck deck(cards);
    REQUIRE(deck.getSize() == cards.size());
    SECTION("Testing exsisting cards"){
      int n = cards.size();
      for(int i = 0;i<n;i++){
         REQUIRE(isFindedInDeck(deck,cards[i]));
     }
  }
    SECTION("Test unexsisting cards"){
      Card unexsisting = Card('J','C');
      REQUIRE(!isFindedInDeck(deck,unexsisting));
  }
}
TEST_CASE("Testing  deck(size)"){
    Deck deck = Deck(5);
    REQUIRE(deck.getSize() == 5);
}

TEST_CASE("Testing draw card"){
    
    SECTION("Testing empty deck"){
        //pravimo spil od jedne karte koju zatim uklanjamo, da bi simulirali sta se desava ako iz praznog spila pokusamo da uzmemo kartu
      vector<Card>cards;
      Card c = Card('A','H');
      cards.push_back(c);
      Deck deck(cards);
        
      deck.removeCard(c);
      Card taken = deck.drawCard();
      REQUIRE(taken.isEmpty());
    }
    
    SECTION("Testing deck with one card"){
      vector<Card>cards;
      Card c = Card('A','H');
      cards.push_back(c);
      Deck deck(cards);
      Card taken = deck.drawCard();
      REQUIRE(taken == c);
      REQUIRE(deck.getSize() == 0);                
  }
    SECTION("Testing deck with more than one card"){
      vector<Card>cards;
      cards.push_back(Card('A','C'));
      cards.push_back(Card('5','H'));
      cards.push_back(Card('J','C'));
      Deck deck(cards);
      Card taken = deck.drawCard();
      Card excepted_taken = Card('J','C');
      REQUIRE(taken == excepted_taken);
    }
}
TEST_CASE("Testing remove card"){
    vector<Card>cards;
    cards.push_back(Card('A','C'));
    cards.push_back(Card('5','H'));
    cards.push_back(Card('J','C'));
    SECTION("Testing remove exsisting card"){
      Deck deck(cards);
      Card exsisting('A','C');
      deck.removeCard(exsisting);
      REQUIRE(!isFindedInDeck(deck,exsisting));
      REQUIRE(deck.getSize() == 2);
    }
    SECTION("Testing remove unexsisting card"){
      Deck deck(cards);
      Card unexsisting('6','C');
      deck.removeCard(unexsisting);
      REQUIRE(deck.getSize() == 3);
    }   
}
TEST_CASE("Testing shuffle cards"){
    Deck deck;
    vector<Card>originalCards = deck.getCards();
    Deck originalDeck(originalCards);
    deck.shuffleCards();
    SECTION("Testing size"){
        REQUIRE(deck.getSize() == originalDeck.getSize());
    }
}
TEST_CASE("Testing add card"){
    vector<Card>cards;
    cards.push_back(Card('A','C'));
    cards.push_back(Card('5','H'));
    cards.push_back(Card('J','C'));
    
    Deck deck(cards);
    Card added('8','H');

    REQUIRE(!isFindedInDeck(deck,added));
        
    deck.addCard(added);
    REQUIRE(isFindedInDeck(deck,added));
}
TEST_CASE("Testing print deck"){
    vector<Card>cards;
    cards.push_back(Card('0','H'));
    cards.push_back(Card('K','S'));
    Deck deck(cards);

    std::ostringstream outputBuffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(outputBuffer.rdbuf()); // Preusmeri std::cout

    deck.print(); // Ispis u `outputBuffer` umesto standardnog izlaza

    std::cout.rdbuf(oldCoutBuffer); // Vrati std::cout na originalni izlaz

    // Provera da li je ispis ispravan
    std::string expectedOutput = "10 of hearts \nK of spades \n\n";
    REQUIRE(outputBuffer.str() == expectedOutput);
}

TEST_CASE("Testing draw hand"){
    
    Deck d;
    Deck hand = d.drawHand();
    SECTION("Testing size"){
        REQUIRE(hand.getSize() == 6);
    }    
}
TEST_CASE("Testing first player function"){
    int player;
    vector<Card>hand1;
    hand1.push_back(Card('5','H'));
    hand1.push_back(Card('6','H'));
    hand1.push_back(Card('A','S'));

    vector<Card>hand2;
    hand2.push_back(Card('0','H'));
    hand2.push_back(Card('K','S'));
    hand2.push_back(Card('A','C'));

    SECTION("No one have suit = trump suit"){
      player = Deck::firstPlayer(hand1, hand2, 'D');
      REQUIRE(player == 1);
    }
    SECTION("First have trump suit"){
      hand1.push_back(Card('J','D'));
      player = Deck::firstPlayer(hand1, hand2, 'D');
      REQUIRE(player == 1);      
    }
    SECTION("Both have trump suit"){
        hand2.push_back(Card('1','D'));
        player = Deck::firstPlayer(hand1, hand2, 'D');
        //prvi igrac treba da bude 2,jer on ima manju kartu
        REQUIRE(player == 2);      
    }
    SECTION("Only second have trump suit"){
        hand2.push_back(Card('J','D'));     
        player = Deck::firstPlayer(hand1, hand2, 'D');
        REQUIRE(player == 2);   
    }
}
TEST_CASE("Testing askCard") {
    vector<Card> cards = {Card('A', 'S'), Card('K', 'H'), Card('Q', 'D')};
    Deck deck(cards);

    std::istringstream fakeInput("0\n4\n2\n");
    std::ostringstream fakeOutput;

    std::streambuf* oldCin;
    std::streambuf* oldCout;

    redirectStreams(fakeInput, fakeOutput, oldCin, oldCout);

    Card chosenCard = deck.askCard();

    restoreStreams(oldCin, oldCout);

    std::string output = fakeOutput.str();

    std::vector<std::string> expectedMessages = {
      "Choose a card:",
      "Invalid choice!\nChoose a card:\n",
      "1. A of spades",
      "2. K of hearts",
      "3. Q of diamonds"
    };

    validateOutput(output, expectedMessages);

    Card expectedCard('K', 'H');
    REQUIRE(chosenCard == expectedCard);
    REQUIRE(deck.getSize() == 2);
}

TEST_CASE("Testing askCard(Deck)") {
    vector<Card> cards = {Card('A', 'S'), Card('K', 'H'), Card('Q', 'D')};
    Deck table(cards);

    vector<Card> hand = {Card('A', 'C'), Card('0', 'H'), Card('7', 'H')};
    Deck ourCards(hand);

    std::istringstream fakeInput("0\n2\n1\n");
    std::ostringstream fakeOutput;

    std::streambuf* oldCin;
    std::streambuf* oldCout;

    redirectStreams(fakeInput, fakeOutput, oldCin, oldCout);

    Card chosenCard = ourCards.askCard(table);

    restoreStreams(oldCin, oldCout);

    std::string output = fakeOutput.str();

    std::vector<std::string> expectedMessages = {
      "Choose a card:",
      "Your Hand:\n",
      "1. A of clubs",
      "2. 10 of hearts",
      "3. 7 of hearts",
      "Invalid choice!\nChoose a card:\n",
      "Card must be a value on the table!\nChoose a card:\n"
    };

    validateOutput(output, expectedMessages);

    Card expectedCard('A', 'C');
    REQUIRE(chosenCard == expectedCard);
    REQUIRE(ourCards.getSize() == 2);
}

TEST_CASE("Testing askCard() with situations") {
    vector<Card> cards = {Card('A', 'S'), Card('K', 'H'), Card('Q', 'D')};
    Deck deck(cards);

    SECTION("Situation when trump wins") {
      Card c1('J', 'C');
      std::istringstream fakeInput("0\n2\n1\n");
      std::ostringstream fakeOutput;

      std::streambuf* oldCin;
      std::streambuf* oldCout;

     redirectStreams(fakeInput, fakeOutput, oldCin, oldCout);

      Card chosenCard = deck.askCard(c1, 'S');

      restoreStreams(oldCin, oldCout);
      
      std::string output = fakeOutput.str();

      std::vector<std::string> expectedMessages = {
        "Your Hand:\n",
         "1. A of spades",
          "2. K of hearts",
          "3. Q of diamonds",
          "Invalid choice!\nChoose a card:\n",
          "Card must beat the "
        };

      validateOutput(output, expectedMessages);

      Card expectedCard('A', 'S');
      REQUIRE(chosenCard == expectedCard);
      REQUIRE(deck.getSize() == 2);
    }

    SECTION("Situation when don't win") {
      Card c2('A', 'S');
      Card chosenCard = deck.askCard(c2, 'S');
      REQUIRE(chosenCard.isEmpty());
    }
}
TEST_CASE("Tesing check value"){
    vector<Card>cards1;
    cards1.push_back(Card('A', 'S'));
    cards1.push_back(Card('K', 'H'));
    cards1.push_back(Card('Q', 'D'));
    Deck deck(cards1);
    
    vector<Card>cards2;
    cards2.push_back(Card('7', 'S'));
    cards2.push_back(Card('0', 'H'));
    cards2.push_back(Card('9', 'H'));
  
    SECTION("Testing invalid"){
      Deck values(cards2);
      REQUIRE(!deck.checkValue(values));
   }  
    SECTION("Testing valid"){
      cards2.push_back(Card('A','S'));
      Deck values(cards2);
      REQUIRE(deck.checkValue(values));
}
}
TEST_CASE("Tesing clear"){
    Deck deck;
    deck.clear();
    REQUIRE(deck.getSize() == 0);
}
TEST_CASE("Testing findHigh(suit)"){
    vector<Card>cards; 
    char suit = 'S';
    SECTION("Tesing empty deck"){
      Deck deck(cards);
      Card higest = deck.findHigh(suit);
      REQUIRE(higest.isEmpty());
  }
    cards.push_back(Card('J','C'));
    cards.push_back(Card('0','D'));
    cards.push_back(Card('7','H'));
  SECTION("Testing when in deck don't exists card with suit"){
    //trebalo bi da karta bude jednaka prvoj sa stola
      Deck deck(cards);
      Card higest = deck.findHigh(suit);
      Card exceptedCard = Card('J','C');
      REQUIRE(higest == exceptedCard);
}
  SECTION("Tesing when in deck exists card with suit"){
      cards.push_back(Card('0','S'));
      Deck deck(cards);
      Card higest = deck.findHigh(suit);
      Card exceptedCard = Card('0','S');
      REQUIRE(higest == exceptedCard);
}
}

TEST_CASE("Tesing find high"){
    vector<Card>cards; 
    SECTION("Tesing empty deck"){
    Deck deck(cards);
    Card higest = deck.findHigh();
    REQUIRE(higest.isEmpty());
  }  
  SECTION("Tesing deck with cards"){
    cards.push_back(Card('J','C'));
    cards.push_back(Card('0','D'));
    cards.push_back(Card('Q','H'));
    Deck deck(cards);
    Card higest = deck.findHigh();
    Card exceptedCard = Card('Q','H');
    REQUIRE(exceptedCard == higest);
  }
}

TEST_CASE("Testing pickUp"){
    vector<Card>tableCards;
    tableCards.push_back(Card('J','C'));
    tableCards.push_back(Card('0','D'));
    tableCards.push_back(Card('Q','H'));
    Deck table(tableCards);
    Deck tableCopy = table;
    Deck deck(0);
    deck.pickUp(table);
    REQUIRE(tableCopy == deck);
    REQUIRE(table.getSize() == 0);
}

TEST_CASE("Testing replenish") {
    vector<Card> handCards;
    handCards.push_back(Card('J', 'C'));
    handCards.push_back(Card('0', 'D'));
    handCards.push_back(Card('Q', 'H'));
    Deck hand(handCards);

    vector<Card> deckCards;

    SECTION("When replenishing is not available") {
        deckCards.push_back(Card('9', 'C'));  
        deckCards.push_back(Card('9', 'D'));  
        Deck deck(deckCards);
        REQUIRE(!hand.replenish(deck));  // Not enough cards in deck
    }

    SECTION("When replenishing is available") {
        deckCards.push_back(Card('K', 'S'));
        deckCards.push_back(Card('A', 'H'));  
        deckCards.push_back(Card('2', 'D'));  
        Deck deck(deckCards);
        REQUIRE(hand.replenish(deck));  
    }
}
