#include "word.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

word::word() : term({}), definition({}) {}

word::word(string & term, const string & definition) : definition(definition) {
  for(char & c : term) {
    c = tolower(c);
  }
  word::term = term; //is valid??
}

string word::get_term() const {
  return term;
}

string word::get_definition() const {
  return definition;
}

short word::compare(const word & other_word) const {
  if(term > other_word.term)
    return 1;
  if(term < other_word.term)
    return -1;
  else
    return 0;
}

void word::display() const {
  cout << term << " : " << definition << endl;
}