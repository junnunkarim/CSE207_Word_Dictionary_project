/*
  Header file for user defined data type word.
  It contains structural definitions and
  prototypes for bst.

  Written by : Md Murad Khan Limon
  Date       : 20 August, 2023
*/

#ifndef WORD_H
#define WORD_H

#include <memory>
#include <string>

#include "bst.h"
#include "list.h"

using std::string;

class word {
  private:
    string term;
    string definition;

    ds::list<ds::bst<string>::Node *> similar_words;

  public:
    word();
    word(const string & term, const string & definition);
    ~word();

    string get_term() const;
    string get_definition() const;
    void set_term(const string & term);
    void set_definition(const string & definition);
    void set_similar_words(const ds::list<ds::bst<string>::Node *> similar_words);
    void display() const;

    bool operator==(const word & other) const;
    bool operator!=(const word & other) const;
    bool operator<(const word & other) const;
    bool operator>(const word & other) const;
    friend ostream& operator<<(ostream& os, const word& w);
};

#endif //WORD_H
