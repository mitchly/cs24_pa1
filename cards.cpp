//cards.cpp
//Joshua Thomas, Michelle Ly
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <vector>
using namespace std;

CardList::~CardList() { // Non-recursive destructor;
    while(head){
      Card* nxt = head->next;
      delete head;
      head = nxt;
    }
}

CardList::CardList(){ //default constructor
  head = NULL;
  player = "I have no name";
}

CardList::CardList(const CardList& source) { // copy constructor to get card list
    head = nullptr;
    Card *curr = source.head;
    while (curr) {
      std::string thisval = curr->info;
      append(thisval);
      curr = curr->next;
  }
}

bool CardList::contains(std::string value) const { // contains function
  bool cont = false;
  if(head==nullptr){
    return false;
  }
  if(head->info == value) {
    cont = true;
    return cont;
  };
  Card *curr = head->next;
  while(curr) {
    if(value == curr->info) {
      cont = true;
      return cont;
    }
    curr = curr->next;
  }
  return cont;
}

CardList::Card* CardList::Location(std::string value, Card* thisCard) const{ //gives location of a card, recursively
  while(thisCard != NULL){
    if(thisCard->info == value){ // return card if location is found (through value comparison)
        return thisCard;
    }
    else{
        thisCard = thisCard->next; //if value doesn't match move on to the next card
    }
  }
  return NULL;
}

bool CardList::remove(Card thisCard){ //removes card from a cardlist, helper function for search
  Card* delthis = Location(thisCard.info, head);
  if(delthis == nullptr){ // no need to remove anything when null
    return false;
  }
  if (delthis->info == head->info) { // if card you want to remove is at head
    delthis->next->prev = NULL;
    head = delthis->next;
    delete delthis;
    return true;
  }
  else if (delthis->info == tail->info) { // if card you want to remove is at tail
    delthis->prev->next = NULL;
    tail = delthis->prev;
    delete delthis;
    return true;
  }
  else{ // if card is anywhere else
    delthis->prev->next = delthis->next;
    delthis->next->prev = delthis->prev;
    delete delthis;
    return true;
  }
}

void CardList::append(std::string value){ // appends new card to cardlist
    if (head == 0) { // empty list
        head = new Card;
        head->info = value;
        head->next = 0;
        tail = head;
    }
    else { // if cards are already in list...
      tail->next = new Card;
      Card *n = tail->next;
      n->prev = tail;
      tail = n;
      tail->info = value;
      tail->next = 0;
    }
}

CardList& CardList::operator=(const CardList& source){
  if(this==&source){
    return *this;
  }
  this->~CardList(); // delete the existing thing
  this->head = nullptr;
  Card *curr = source.head;
  while (curr) { // give new values/info to obj that had info deleted
      std::string thisval = curr->info;
      this->append(thisval);
      curr = curr->next;
}
return *this;
}

void CardList::setName(std::string name){ // sets the name of a player
  this->player = name;
}

bool CardList::search(Card* p1head, CardList& p2) {
  /*Logic:
      1) start at this->head, search p2 hand for this->head
      2) if contains == T: delete this->head from both p2 and p1(this)
      3) else: call search again with modified linked list (p1head = head+1)
  */
  if(p1head == nullptr) {
    p1head = head;
  }
  bool result = p2.remove(*p1head); // run remove function on p2
  if(result != true && p1head->next != nullptr){ // if it does not work:
    search(p1head->next, p2); // search again next value
    return true; // end this function
  }
  if(result) {
    cout << this->player<<" picked matching card " << p1head->info<< endl;
    remove(*p1head); // remove card
    return true; // end this function
  }
  else{ //else
    return false;
  };
};

void CardList::print(Card* c) const { // prints all cards in list
  if(c == NULL){
    return;
  }
  cout << c->info << endl;
  print(c->next);
}