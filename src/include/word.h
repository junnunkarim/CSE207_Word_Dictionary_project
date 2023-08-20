/*
  Header file for user defined data type word.
  It contains structural definitions and
  prototypes for bst.

  Written by : Md Murad Khan Limon
  Date       : 20 August, 2023
*/

#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;

class word {
private:  
  string term;
  string definition;
  //dynamic arraylist for similar words pointer

public:
  word();
  word(string & term, const string & definition);

  string get_term() const;
  string get_definition() const;
  short compare(const word & other_word) const;
  void display() const;
};

#include "word.tpp"

#endif //WORD_H