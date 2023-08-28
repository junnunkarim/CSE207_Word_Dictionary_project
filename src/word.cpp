#include "../include/word.h"
#include <iostream>
#include <string>
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower

word::word() : term({}), definition({}) {}

word::word(const std::string & term, const std::string & definition) : definition(definition) {
  this->term = term;

  std::transform(this->term.begin(), this->term.end(), this->term.begin(),
    [](unsigned char c) {return std::tolower(c);} );
}

word::~word() {}


std::string word::get_term() const {
  return term;
}

std::string word::get_definition() const {
  return definition;
}

void word::set_term(const std::string & term) {
  this->term = term;
}

void word::set_definition(const std::string & definition) {
  this->definition = definition;
}

void word::display() const {
  std::cout << "\t" << term << " -" << std::endl;
  std::cout << "\t\t" << "definition: " << definition << std::endl;
}



void word::operator()(const std::string & term, const std::string & definition) {
  this->term = term;
  this->definition = definition;

  std::transform(this->term.begin(), this->term.end(), this->term.begin(),
    [](unsigned char c) {return std::tolower(c);} );
}

bool word::operator==(const word & other) const {
  return term == other.term;
}
bool word::operator!=(const word & other) const {
  return !(*this == other);
}
bool word::operator<(const word & other) const {
  return term < other.term;
}
bool word::operator>(const word & other) const {
  return term > other.term;
}

std::ostream & operator<<(std::ostream & os, const word & w) {
  os << w.term;

  return os;
}


word::operator std::string() const {
  return term;
}
