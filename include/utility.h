#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "bst.h"
#include "word.h"

namespace util {
  ds::list<string> str_split(std::string *line, char delimeter);
  void load_database(ds::bst<word> * WORD_TREE);
  void store_database_helper(ds::bst<word>::Node * node, std::ofstream * output_file_ptr);
  void store_database(ds::bst<word> * WORD_TREE);
  void save_changes(ds::bst<word> * WORD_TREE);
  void clear_input_buffer();
  void wait_for_input();
  std::string to_lowercase(const std::string * str);
  void clear_screen();
  bool word_is_alpha(const std::string * word);
  std::string input_word(std::string * message = nullptr);
  std::string input_sentence();
  bool confirmation_check(std::string * message = nullptr);
}

#endif
