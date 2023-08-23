#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace util {
  void initialize();
  void clear_input_buffer();
  void wait_for_input();
  void clear_screen();
  bool word_is_alpha(const std::string & word);
  std::string input_word();
  std::string input_sentence();
}

#endif
