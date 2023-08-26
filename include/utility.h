#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "bst.h"
#include "word.h"

namespace util {
  ds::list<string> str_split(string line, char delimeter);
  void load_database(ds::bst<word> & WORD_TREE);
  void store_database();
  void clear_input_buffer();
  void wait_for_input();
  void clear_screen();
  bool word_is_alpha(const std::string & word);
  std::string input_word();
  std::string input_sentence();
}

#endif
