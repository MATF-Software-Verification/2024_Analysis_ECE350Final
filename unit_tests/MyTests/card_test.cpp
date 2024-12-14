//#define CATCH_CONFIG_MAIN
#include<vector>
#include<sstream>
#include "../../catch.hpp"
#include "../../src/Card.h"


TEST_CASE("Testing setVal"){
    Card card;
    SECTION("Testing valid numbers"){
        for(int i = 6;i <=9;i++){
        REQUIRE(card.setVal(char(i+48)));
        }
    }
    SECTION("Testing valid char"){
        REQUIRE(card.setVal('0'));
        REQUIRE(card.setVal('J'));
        REQUIRE(card.setVal('Q'));
        REQUIRE(card.setVal('K'));
        REQUIRE(card.setVal('A'));
    }
    SECTION("Testing invalid values"){
        REQUIRE(!card.setVal(15));
        REQUIRE(!card.setVal('!'));
        REQUIRE(!card.setVal('@'));
        REQUIRE(!card.setVal(' '));
        REQUIRE(!card.setVal('4'));
    }
}

TEST_CASE("Testing getNumValue"){
    Card card;

    SECTION("Valid card values"){
        card.setVal('A');
        REQUIRE(card.getNumValue() == 14);
    
        card.setVal('K');
        REQUIRE(card.getNumValue() == 13);
        
        card.setVal('Q');
        REQUIRE(card.getNumValue() == 12);
    
        card.setVal('J');
        REQUIRE(card.getNumValue() == 11);
        
        card.setVal('0');
        REQUIRE(card.getNumValue() == 10);
        
        card.setVal('X');
        REQUIRE(card.getNumValue() == -1);
     
        for(int i = 6;i <= 9;i++){
            card.setVal(char(i+48));
            REQUIRE(card.getNumValue()  == i);
        }
    }
    SECTION("Invalid card values"){
            
        card.setVal('a');
        REQUIRE(card.getNumValue() != 14);
    
        card.setVal('k');
        REQUIRE(card.getNumValue() != 13);
        
        card.setVal('x');
        REQUIRE(card.getNumValue() != 0);
    }
}

TEST_CASE("Testing setVal(value)"){
       Card card;
       REQUIRE(card.setVal('8'));
       REQUIRE(card.setVal('A'));
       REQUIRE(card.setVal('X'));
}
TEST_CASE("Testing setSuit"){
    Card card;
    SECTION("Valid card suit"){
      REQUIRE(card.setSuit('H'));
      REQUIRE(card.setSuit('h'));
      REQUIRE(card.setSuit('D'));
      REQUIRE(card.setSuit('d'));
      REQUIRE(card.setSuit('C'));
      REQUIRE(card.setSuit('c'));
      REQUIRE(card.setSuit('S'));
      REQUIRE(card.setSuit('s'));
    }
    SECTION("Invalid card suit"){
      REQUIRE(!card.setSuit('m'));
      REQUIRE(!card.setSuit('M'));
      REQUIRE(!card.setSuit('6'));
    }
}
TEST_CASE("Testing getSuit"){
    Card card;
    SECTION("Valid card suit"){
        card.setSuit('H');
        REQUIRE(card.getSuit() == 'H');
        card.setSuit('h');
        REQUIRE(card.getSuit() == 'H');
        
        card.setSuit('D');
        REQUIRE(card.getSuit() == 'D');
        card.setSuit('d');
        REQUIRE(card.getSuit() == 'D');
        
        card.setSuit('C');
        REQUIRE(card.getSuit() == 'C');
        card.setSuit('c');
        REQUIRE(card.getSuit() == 'C');
        
        card.setSuit('s');
        REQUIRE(card.getSuit() == 'S');
        card.setSuit('s');
        REQUIRE(card.getSuit() == 'S');
    }
    SECTION("Invalid card suit"){
        card.setSuit('x');
        REQUIRE(card.getSuit() != 'x') ;
    }
    
}
void testPrint(Card& card, char suit, const vector<pair<char, string>>& testCases) {
    for (const auto& testCase : testCases) {
        char inputVal = testCase.first;

        card.setVal(inputVal);
        card.setSuit(suit);
       
        // Preusmeravanje standardnog izlaza
        std::ostringstream output;
        std::streambuf* oldBuf = std::cout.rdbuf(output.rdbuf());

        card.print();

        // Vraćanje std::cout na originalni tok
        std::cout.rdbuf(oldBuf);

        // Provera rezultata
        REQUIRE(output.str() == testCase.second);
    }
}

TEST_CASE("Testing print card") {
    Card card;

    SECTION("Testing print hearts") {
        vector<pair<char, string>> testCases = {
            {'A', "A of hearts "},
            {'K', "K of hearts "},
            {'Q', "Q of hearts "},
            {'J', "J of hearts "},
            {'0', "10 of hearts "},
            {'6', "6 of hearts "}
        };
        testPrint(card, 'H', testCases);
    }

    SECTION("Testing print diamonds") {
        vector<pair<char, string>> testCases = {
            {'A', "A of diamonds "},
            {'K', "K of diamonds "},
            {'Q', "Q of diamonds "},
            {'J', "J of diamonds "},
            {'0', "10 of diamonds "},
            {'6', "6 of diamonds "}
        };
        testPrint(card, 'D', testCases);
    }

    SECTION("Testing print spades") {
        vector<pair<char, string>> testCases = {
            {'A', "A of spades "},
            {'K', "K of spades "},
            {'Q', "Q of spades "},
            {'J', "J of spades "},
            {'0', "10 of spades "},
            {'6', "6 of spades "}
        };
        testPrint(card, 'S', testCases);
    }

    SECTION("Testing print clubs") {
        vector<pair<char, string>> testCases = {
            {'A', "A of clubs "},
            {'K', "K of clubs "},
            {'Q', "Q of clubs "},
            {'J', "J of clubs "},
            {'0', "10 of clubs "},
            {'6', "6 of clubs "}
        };
        testPrint(card, 'C', testCases);
    }
}

TEST_CASE("Testing operator =="){
    Card c1('0','S');
    Card c2('0','S');
    Card c3('J','S');
    REQUIRE(c1==c2);
    REQUIRE(c1 != c3);
}	
TEST_CASE("Testing isEmpty"){
    Card c1('0','S');
    REQUIRE(!c1.isEmpty());
    Card c2;
    REQUIRE(c2.isEmpty());
}
