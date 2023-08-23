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

class word {
  private:
    std::string term;
    std::string definition;

    ds::list<ds::bst<std::string>::Node *> similar_words;

  public:
    word();
    word(const std::string & term, const std::string & definition);
    ~word();

    std::string get_term() const;
    std::string get_definition() const;
    void set_term(const std::string & term);
    void set_definition(const std::string & definition);
    void set_similar_words(const ds::list<ds::bst<std::string>::Node *> similar_words);
    void display() const;

    bool operator==(const word & other) const;
    bool operator!=(const word & other) const;
    bool operator<(const word & other) const;
    bool operator>(const word & other) const;
    friend ostream& operator<<(ostream& os, const word& w);

    operator std::string() const;
};

#endif //WORD_H
