/**
 * @file word.cpp
 * @brief Contains the implementation of the word class.
 */
#include "../include/word.h"

#include <iostream>
#include <string>
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower

/**
 * @brief Default constructor for the word class.
 */
word::word() : term({}), definition({}) {}

/**
 * @brief Parameterized constructor for the word class.
 * @param term The term associated with the word.
 * @param definition The definition of the word.
 */
word::word(const std::string & term, const std::string & definition) : definition(definition) {
  this->term = term;

  std::transform(this->term.begin(), this->term.end(), this->term.begin(),
    [](unsigned char c) {return std::tolower(c);} );
}

/**
 * @brief Destructor for the word class.
 */
word::~word() {}


/**
 * @brief Get the term associated with the word.
 * @return The term as a string.
 */
std::string word::get_term() const {
  return term;
}

/**
 * @brief Get the definition of the word.
 * @return The definition as a string.
 */
std::string word::get_definition() const {
  return definition;
}

/**
 * @brief Set the term associated with the word.
 * @param term The term to set.
 */
void word::set_term(const std::string & term) {
  this->term = term;
}

/**
 * @brief Set the definition of the word.
 * @param definition The definition to set.
 */
void word::set_definition(const std::string & definition) {
  this->definition = definition;
}

/**
 * @brief Display the word and its definition.
 */
void word::display() const {
  std::cout << "\t" << term << " -" << std::endl;
  std::cout << "\t\t" << "definition: " << definition << std::endl;
}


/**
 * @brief Overloaded function call operator to set term and definition.
 * @param term The term to set.
 * @param definition The definition to set.
 */
void word::operator()(const std::string & term, const std::string & definition) {
  this->term = term;
  this->definition = definition;

  std::transform(this->term.begin(), this->term.end(), this->term.begin(),
    [](unsigned char c) {return std::tolower(c);} );
}

/**
 * @brief Overloaded equality operator.
 * @param other Another word object to compare with.
 * @return True if the words are equal, otherwise false.
 */
bool word::operator==(const word & other) const {
  return term == other.term;
}

/**
 * @brief Inequality operator to compare two words for inequality.
 * @param other The other word to compare with.
 * @return True if the words are not equal, false otherwise.
 */
bool word::operator!=(const word & other) const {
  return !(*this == other);
}

/**
 * @brief Less than operator to compare two words.
 * @param other The other word to compare with.
 * @return True if this word is less than the other word, false otherwise.
 */
bool word::operator<(const word & other) const {
  return term < other.term;
}

/**
 * @brief Greater than operator to compare two words.
 * @param other The other word to compare with.
 * @return True if this word is greater than the other word, false otherwise.
 */
bool word::operator>(const word & other) const {
  return term > other.term;
}

/**
 * @brief Output stream operator to display a word.
 * @param os The output stream.
 * @param w The word to display.
 * @return The output stream.
 */
std::ostream & operator<<(std::ostream & os, const word & w) {
  os << w.term;

  return os;
}

/**
 * @brief Conversion operator to convert word to string.
 * @return The term of the word as a string.
 */
word::operator std::string() const {
  return term;
}
