#ifndef UTILITY_CPP
#define UTILITY_CPP

#include <iostream>
#include <string>
#include <limits> // for clearing input buffer
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower

#include "../include/utility.h"

namespace util {
  void initialize() {

  }

  void clear_input_buffer() {
    // Clear the input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  void wait_for_input() {
    std::string line = {};

    std::cout << std::endl;
    std::cout << "Press [ENTER]";

    std::getline(std::cin, line); // wait for Enter key
  }

  void clear_screen() {
    #ifdef _WIN32
      system("cls"); // clear the screen on windows
    #else
      system("clear"); // clear the screen on linux
    #endif
  }

  bool word_is_alpha(const std::string & word) {
    for (char c : word) {
      if (!std::isalpha(c)) {
          return false; // If a non-alphabetic character is found, return false
      }
    }
    return true; // All characters are alphabetic
  }

  std::string input_word() {
    std::string str = {};

    // take input until string contains only alphabets
    do {
      std::cout << "Enter a word: " << std::endl;
      std::cin >> str;

      clear_input_buffer();

      if(!word_is_alpha(str)) {
        std::cout << "Error! Word should only contain Alphabets!" << std::endl;
        std::cout << "Please try again!" << std::endl;

        wait_for_input();
      }
      else {
        break;
      }
    } while(true);

    // convert the input string to lowercase using lamda function
    std::transform(str.begin(), str.end(), str.begin(),
      [](unsigned char c) {return std::tolower(c);} );

    return str;
  }

  std::string input_sentence() {
    std::string sentence = {};
    std::getline(std::cin, sentence);

    return sentence;
  }
}

#endif
