#ifndef UTILITY_CPP
#define UTILITY_CPP

#include <iostream>
#include <limits> // for clearing input buffer
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower
#include <string>
#include <fstream>
#include <sstream>

#include "../include/list.h"
#include "../include/bst.h"
#include "../include/utility.h"

namespace util {
  ds::list<string> str_split(std::string * line, char delimeter) {
    std::istringstream line_stream(*line);
    std::string token = {};
    ds::list<std::string> token_list;

    while(std::getline(line_stream, token, delimeter)) {
      token_list.insert_back(token);
    }

    return token_list;
  }

  void load_database(ds::bst<word> * WORD_TREE) {
    std::string filename = "../data/database";

    std::ifstream input_file(filename);

    if(!input_file) {
      std::cerr << "Error loading database from file!" << std::endl;

      wait_for_input();
    }
    else {
      std::string line;
      char delimeter = '|';

      while(std::getline(input_file, line)) {
        ds::list<string> token_list = str_split(&line, delimeter);
        word new_word;

        if(token_list.get_size() == 1) {
          new_word(token_list[0], {});
        }
        else if(token_list.get_size() >= 2) {
          new_word(token_list[0], token_list[1]);
        }
        else {
          break;
        }

        (*WORD_TREE).insert(new_word);
      }
      input_file.close();
    }
  }

  void store_database_helper(ds::bst<word>::Node * node, std::ofstream * output_file_ptr) {
    if (node == nullptr)
      return;

    // pre-order traversal
    (*output_file_ptr) << node->data.get_term() << "|" << node->data.get_definition() << "\n";
    store_database_helper(node -> left.get(), output_file_ptr);
    store_database_helper(node -> right.get(), output_file_ptr);

  }

  void store_database(ds::bst<word> * WORD_TREE) {
    std::string filename = "../data/database";

    std::ofstream output_file(filename);

    if(!output_file) {
      std::cerr << "Error loading database from file!" << std::endl;

      wait_for_input();
    }
    else {
      store_database_helper((*WORD_TREE).get_root(), &output_file);

      output_file.close();
    }
  }

  void save_changes(ds::bst<word> * WORD_TREE) {
    std::string message = "Do you want to save the changes to the Binary Search Tree (Yes/No): ";

    if(util::confirmation_check(&message))
      util::store_database(WORD_TREE);
    else
      std::cout << "Changes were not saved." << std::endl;
  }

  void clear_input_buffer() {
    // Clear the input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  void wait_for_input() {
    std::string line = {};

    std::cout << std::endl;
    std::cout << "────────────────────────────────── Press [ENTER]";
    std::cout << std::endl;

    std::getline(std::cin, line); // wait for Enter key
  }

  std::string to_lowercase(const std::string * str) {
    std::string lowercase = *str;

    // convert the input string to lowercase using lamda function
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(),
      [](unsigned char c) {return std::tolower(c);} );

    return lowercase;
  }

  void clear_screen() {
    #ifdef _WIN32
      system("cls"); // clear the screen on windows
    #else
      system("clear"); // clear the screen on linux
    #endif
  }

  bool word_is_alpha(const std::string * word) {
    for (char c : (*word)) {
      if (!std::isalpha(c)) {
          return false; // If a non-alphabetic character is found, return false
      }
    }
    return true; // All characters are alphabetic
  }

  std::string input_word(std::string * message) {
    std::string str = {};

    // take input until string contains only alphabets
    do {
      if(message == nullptr)
        std::cout << "Enter a word: " << std::endl;
      else
        std::cout << (*message);

      std::cin >> str;

      clear_input_buffer();

      if(!word_is_alpha(&str)) {
        std::cout << std::endl;
        std::cout << "Error! Word should only contain Alphabets!" << std::endl;
        std::cout << "Please try again!" << std::endl;

        wait_for_input();
      }
      else {
        break;
      }
    } while(true);

    str = to_lowercase(&str);

    return str;
  }

  std::string input_sentence() {
    std::string sentence = {};
    std::getline(std::cin, sentence);

    return sentence;
  }

  bool confirmation_check(std::string * message) {
    std::string confirmation;

    do {
      confirmation = util::input_word(message);

      if(confirmation == "y" || confirmation == "yes")
        return true;
      else if(confirmation == "n" || confirmation == "no")
        return false;
      else {
        std::cout << "Please answer with either `yes` or `no`!" << std::endl;
      }
    } while(true);
  }
}

#endif
