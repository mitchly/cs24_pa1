//cards.h
//Joshua Thomas, Michelle Ly
//All class declarations go here

#include <iostream>
#include <string>
#ifndef CARDS_H
#define CARDS_H

#endif

using std::cout;

class CardList{ //mimics a linked list
   private:
       struct Card{ //mimics a node in a linked list
           std::string info; // suit and value of the card
           Card* next;
           Card* prev;
           };
       void clear(Card* c); // we can impliment
       std::string player;
       Card* head;
       Card* tail;
       Card* Location(std::string value, Card* thisCard) const;

   public: //UNFINISHED
       CardList();
       ~CardList(); // non recursive implimentation
       CardList(const CardList& source); // copy constructor
       Card* getHead(){
           return head;
       }
       void print(Card* c) const;
       void append(std::string value); // add a card to the list
       bool remove(Card thisCard);
       bool search(Card* p1head, CardList& p2); //could be the search function, i guess?
       bool contains(std::string value) const; // do note this references cards in a normal 52 deck
       CardList& operator=(const CardList& source);
       void setName(std::string name);
       bool game(CardList p2);
       friend std::ostream& operator<< (std::ostream& os, const CardList& random) {
           os << "My name is: " << random.player;
           return os; // !!!!! Don't forget this return !!!!!
           }
       void assertEquals(Card* head1, Card* head2){
           if(head1 == head2){
               cout << "they are equivalent";
               return;
               }
           cout << "there is an error";
           }

};