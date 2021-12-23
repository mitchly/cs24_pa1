
// testcards.h
//Authors: Josh Thomas, Michelle Ly
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_constructor();
void test_append();
void test_equal();
void test_card();
void test_remove();
void test_destructor();
void test_search_and_remove();
void test_append_empty_list(); // A test case for append
void test_append_single_element_list(); // Tests cases should be independent, small, fast, orthogonal
void test_equal_empty_list();
//void test_card_operator_double_equal();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

#endif