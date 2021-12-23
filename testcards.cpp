
// This file should contain unit tests for all the
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_constructor();
  test_append();
  test_equal();
  test_card();
  test_destructor();
  test_search_and_remove();
  test_append_empty_list();
  test_append_single_element_list();
  test_equal_empty_list();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  //test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){
// A test case for append single card node to LinkedList
  START_TEST("test_append_empty_list");
  CardList c1, c2;
  c1.append("c 5");
  c2.append("h 9");

  cout << "expected value (c1): " << endl;
  cout << "c 5" << endl;
  cout << "actual value (c1):" << endl;
  c1.print(c1.getHead());
  cout << endl;

  cout << "expected value (c2):" << endl;
  cout << "h 9" << endl;
  cout << "actual value (c2):" << endl;
  c2.print(c2.getHead());
  cout << endl;
  END_TEST("test_append_empty_list");
}

void test_append_single_element_list(){
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)
  START_TEST("test_append_single_element_list");
  CardList c1, c2;
  c1.append("c 5");
  c1.append("d a");//diamond ace
  c2.append("h 9");
  c2.append("s k");//spade king
  c2.append("d 2");
  c2.append("c 7");

  cout << "expected value (c1): " << endl;
  cout << "c 5" << endl;
  cout << "d a" << endl;
  cout << "actual value (c1): " << endl;
  c1.print(c1.getHead());
  cout << endl;

  cout << "expected value (c2):" << endl;
  cout << "h 9" << endl;
  cout << "s k" << endl;
  cout << "d 2" << endl;
  cout << "c 7" << endl;
  cout << "actual value (c2): " << endl;
  c2.print(c2.getHead());
  cout << endl;
  END_TEST("test_append_single_element_list");
}

void test_equal_empty_list(){
  START_TEST("test_equal_empty_list");
  string testname = "case 0: [], []";
  CardList c1, c2;
  c1.assertEquals(c1.getHead(), c2.getHead());
  cout << endl;
  END_TEST("test_equal_empty_list");
}

void test_constructor(){
  START_TEST("test_constructor");
  cout << "Ensure the other testers work properly. "
       << "If they do, that means the (main) constructor functions correctly (nothing would work if it didn't)." << endl;
  cout << "test copy constructor..." << endl;
  CardList c1;
  CardList c2 = c1;
  cout << "If assert equals is true, the copy constructor worked correctly" << endl;
  c1.assertEquals(c1.getHead(), c2.getHead());
  cout << endl;
  END_TEST("test_constructor");
}

void test_destructor(){
  START_TEST("test_destructor");
  cout << "Printing card lists should result in nothing." << endl;
  CardList c1, c2;
  c2.append("h 9");
  c2.append("s k");
  c2.append("c q");
  c2.append("d 10");

  cout << "Before destructor (empty list): " << endl; //empty list
  c1.print(c1.getHead());
  cout << endl;
  c1.~CardList();
  cout << "After destructor (empty list): " << endl;
  c1.print(c1.getHead());
  cout << endl;

  cout << "Before destructor (filled list): " << endl; //filled list
  c2.print(c2.getHead());
  cout << endl;
  c2.~CardList();
  cout << "After destructor (filled list): " << endl;
  c2.print(c2.getHead());
  cout << endl;
  END_TEST("test_destructor");
}

void test_search_and_remove(){ //checks for both search AND remove
  START_TEST("test_search_and_remove");
  CardList c1, c2, c3;
  c1.append("d 8");
  c1.append("h 5");
  cout << "c1 card list: " << endl;
  c1.print(c1.getHead());

  c2.append("h 9");
  c2.append("s k");
  c2.append("c q");
  c2.append("d 10");
  cout << endl;

  cout << "c2 card list: " << endl;
  c2.print(c2.getHead());
  c3.append("s 6");
  c3.append("h 5");
  c3.append("s k");
  cout << endl;

  cout << "c3 card list:" << endl;
  c3.print(c3.getHead());
  cout << endl;

  cout << "NOTE: The 1 in termal denotes true (search is bool)," << endl;
  cout << "meaning both card lists are successfully parsed through" << endl;
  cout << endl;

  cout << "Head of c1 should not match any of c2's card, everything stays the same, nothing prints" << endl;
  cout << "Result of search: " << endl;
  cout << c1.search(c1.getHead(), c2) << endl;
  cout << "Check for correct removal (should stay the same): " << endl;
  cout << "c1 card list (new): " << endl;
  c1.print(c1.getHead());
  cout << endl;
  cout << "c2 card list (new): " << endl;
  c2.print(c2.getHead());
  cout << endl;

  cout << "Head of c3 should match a card in c2 (s k), similar cards deleted from both decks" << endl;
  cout << "Result of search: " << endl;
  cout << c3.search(c3.getHead(), c2) << endl;
  cout << "Check for correct removal (same card should be removed in both): " << endl;
  cout << "c2 card list (new): " << endl;
  c2.print(c2.getHead());
  cout << endl;
  cout << "c3 card list (new): " << endl;
  c3.print(c3.getHead());
  cout << endl;
  END_TEST("test_search_and_remove");
}