#include "word.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string t1 = "Apple";
  string t2 = "Banana";
  string t3 = "Cat";
  string d1 = "A fruit.";
  string d2 = "Another fruit.";
  string d3 = "An animal.";

  word w1(t1, d1);
  word w2(t2, d2);
  word w3(t3, d3);

  cout << "Displaying words:" << endl;
  w1.display();
  w2.display();
  w3.display();
  
  cout << "Comparing words:" << endl;
  cout << "w1 compare w2: " << w1.compare(w2) << endl;
  cout << "w1 compare w3: " << w1.compare(w3) << endl;
  cout << "w2 compare w3: " << w2.compare(w3) << endl;

  return 0;
}
