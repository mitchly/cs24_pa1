
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined
  // to contain two sets of cards in two input files
  CardList Alice;
  CardList Bob;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    Alice.append(line); // This will add a card with 'line 'value in the list
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    Bob.append(line); // Same as before
  }
  cardFile2.close();
  Bob.setName("Bob");
  Alice.setName("Alice");
  // Start the game
  bool run = true;
  int count = 1;
  while(run && count != 100){
    if(count%2!=0){
      run = Alice.search(nullptr, Bob);
    }
    else{
      run = Bob.search(nullptr, Alice);
    }
    count++;
  }
  cout<<endl;
  cout<< "Alice's cards:" << endl;
  Alice.print(Alice.getHead());
  cout << endl;
  cout<< "Bob's cards:" << endl;
  Bob.print(Bob.getHead());
  return 0;
}