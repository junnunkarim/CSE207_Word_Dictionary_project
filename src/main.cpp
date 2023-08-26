#include <cstdlib>
#include <iostream>
#include <string>
#include <vector> // for std::vector
#include <stack> // for std::stack

#include "../include/bst.h"
#include "../include/word.h"
#include "../include/utility.h"


void print_menu();
int choice();
ds::bst<word>::Node * find_closest_node(ds::bst<word>::Node * node, const char & letter, const int index);
void print_suggestions_helper(
  const ds::bst<word>::Node * subtree,
  ds::list<string> & suggestion_list,
  std::string matching_substr);
void print_suggestions(word & search);
void add_synonym(string terminology);

void add_word_helper(std::string message,
  bool synonym = false,
  word defined_word = {});

void add_word();
void search_word();
void delete_word();
void update_word();
void print_tree();


static ds::bst<word> WORD_TREE;


int main() {
  util::load_database(WORD_TREE);

  while(1) {
    print_menu();

    switch (choice()) {
      case 1:
        add_word();
        break;
      case 2:
        search_word();
        break;
      case 3:
        delete_word();
        break;
      case 4:
        update_word();
        break;
      case 5:
        print_tree();
        break;
      case 6:
        util::clear_screen();
        exit(0);
      default:
        cout << "Invalid input!" << endl;
        break;
    }
  }

  return 0;
}

//################################################//
//------------------------------------------------//
void print_menu() {
  util::clear_screen();

  std::cout << "                                 Word Dictionary" << endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;
  std::cout << "1. Add Word" << endl;
  std::cout << "2. Search Word" << endl;
  std::cout << "3. Delete Word" << endl;
  std::cout << "4. Update Word" << endl;
  std::cout << "5. Display Word-Tree" << endl;
  std::cout << "6. Quit" << endl;
  std::cout << std::endl;
}

int choice() {
  int choice = {};

  do {
    std::cout << "Please enter a corresponding number: " << std::endl;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 6) {
      std::cout << "Invalid input. Please try again." << std::endl;

      util::clear_input_buffer();
    }
    else {
      break;
    }
  } while (true);

  return choice;
}

ds::bst<word>::Node * find_closest_node(ds::bst<word>::Node * node, const char & letter, const int index) {
  try {
    if (!node) {
      return nullptr;
    }

    string current_word = node->data;

    if ( (index + 1) > current_word.size() || letter > current_word[index]) {
      return find_closest_node(node->right.get(), letter, index);
    }
    else if (letter < current_word[index]) {
      return find_closest_node(node->left.get(), letter, index);
    }
    else {
      return node;
    }
  }
  catch (const exception & e) {
    cerr << "Exception occured : " << e.what() << std::endl;
    return nullptr;
  }
}

void print_suggestions_helper(
  const ds::bst<word>::Node * subtree,
  ds::list<string> & suggestion_list,
  std::string matching_substr) {

  try {
    if (!subtree) {
      return;
    }

    print_suggestions_helper(subtree->left.get(), suggestion_list, matching_substr);

    print_suggestions_helper(subtree->right.get(), suggestion_list, matching_substr);

    if(subtree->data.get_term().find(matching_substr) == 0) {
        suggestion_list.insert_front(subtree->data.get_term());
    }
  }
  catch (const exception & e) {
    std::cerr << "Exception occured : " << e.what() << std::endl;
  }
}

void print_suggestions(word & search) {
  util::clear_screen();

  string target_str = search;
  string matching_substr = "";
  ds::bst<word>::Node * current_node = WORD_TREE.get_root();
  ds::bst<word>::Node * temp_node = nullptr;

  for(int i = 0; i < target_str.size(); i++) {
    char letter = target_str[i];

    temp_node = find_closest_node(current_node, letter, i);

    if(temp_node == nullptr && i == 0) {
      //std::cout << "No closest suggestions of '" << search << "' was found.";

      return;
    }
    else if(temp_node == nullptr) {
      break;
    }
    else {
      current_node = temp_node;
      matching_substr += letter;
    }
  }

  int count = 5;
  ds::list<string> suggestion_list;

  print_suggestions_helper(current_node, suggestion_list, matching_substr);

  std::cout << "                                     Suggestions" << std::endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;
  std::cout << "The word '" << search << "' was not found!" << std::endl << std::endl;

  if(suggestion_list.get_size() < count)
    count = suggestion_list.get_size();

  if(suggestion_list.get_size() != 0) {
    std::cout << "Did you mean:" << std::endl;

    std::cout << "[ ";
    for(int index = 0; index < count; index++) {
      std::cout << suggestion_list[index];

      if(index != count - 1)
        std::cout << ", ";
    }
    std::cout << " ]";
  }
  //std::cout << std::endl;
  //suggestion_list.print();
}

void add_synonym(string terminology) {
  std::string message = "Do you want to add synonym to the word '" + terminology + "' (Yes/No): ";

  if(util::confirmation_check(message)) {
    std::string message_next = "Enter the synonym: ";
    std::string message_next_2 = "Enter the synonym you want to add: ";
    std::string synonym;
    bool quit = false;

    do {
      synonym = util::input_word(message_next);

      word synonym_word(synonym, {});
      word * word_found = WORD_TREE.search(synonym_word);

      if(!word_found) {
        std::string msg = "The word '" + synonym +
          "' is not found in the Binary Search Tree!\n" +
          "Would you like to add it (Yes/No)? ";

        if(util::confirmation_check(msg)) {
          add_word_helper({}, true, msg);
        }
        else
      }

    } while(!quit);
  }
}
//------------------------------------------------//
//################################################//


void add_word_helper(std::string message,
  bool synonym,
  word defined_word) {

  if(defined_word.is_empty() || !synonym) {
    //std::cout << message;
    std::string terminology = util::input_word(message);

    std::cout << "Enter the definition of the word: " << std::endl;
    definition = util::input_sentence();
    add_synonym(terminology);
  }

  // instantiate a word object named 'new_word'
  word new_word(terminology, definition);

  if (WORD_TREE.insert(new_word)) {
    if(synonym) {

    }

    std::cout << std::endl;
    std::cout << "Added the word '" << terminology << "' to the Binary Search Tree." << std::endl;

    util::wait_for_input();

    return;
  }
  else {
    std::cout << "Error! Could not add the word '" << terminology << "'." << std::endl;
  }
}


//################################################//
//------------------------------------------------//
void add_word() {
  util::clear_screen();

  std::cout << "                                        Add Word" << std::endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;
  std::string message = "Enter the word you want to add: ";

  add_word_helper(message);
}

void search_word() {
  util::clear_screen();

  std::string target_str = {};
  std::string message = "Enter the word you want to search: ";
  ds::bst<word>::Node * root = WORD_TREE.get_root();

  std::cout << "                                          Search" << std::endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;

  target_str = util::input_word(message);

  // instantiate a word object named 'target'
  word target(target_str, {});
  ds::bst<word>::Node * found_node = WORD_TREE.search_node(target);

  if(root != nullptr) {
    if(found_node == nullptr) {
      //std::cout << "The word '" << target_str << "' was not found." << std::endl;
      print_suggestions(target);

      util::wait_for_input();
    }
    else {
      std::cout << std::endl;
      std::cout << "Search result:" << std::endl;

      (*found_node).data.display();

      util::wait_for_input();
    }
  }
}

void delete_word() {
  util::clear_screen();

  std::string terminology = {};
  std::string message = "Enter the word you want to delete: ";

  std::cout << "                                     Delete Word" << std::endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;

  std::cout << "Word Tree:" << std::endl;
  WORD_TREE.print();
  std::cout << std::endl;

  terminology = util::input_word(message);

  word new_word(terminology, {});

  if(!WORD_TREE.search(new_word)) {
    std::cout << "The word '" << terminology << "' was not found!" << std::endl;

    util::wait_for_input();
  }
  else {
    if (WORD_TREE.remove(new_word)) {
      std::cout << "The word '" << terminology << "' was deleted successfully!" << std::endl;

      util::wait_for_input();

      return;
    }
    else {
      std::cout << "Error! The word '" << terminology << "' could not be deleted!" << std::endl;

      util::wait_for_input();
    }
  }
}

void update_word() {
  util::clear_screen();

  std::string target_terminology = {};
  std::string terminology = {};
  std::string message = "Enter the word you want to update: ";

  std::cout << "                                     Update Word" << std::endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;

  std::cout << "Word Tree:" << std::endl;
  WORD_TREE.print();
  std::cout << std::endl;

  target_terminology = util::input_word(message);
  word target_word(target_terminology, {});

  if(!WORD_TREE.search(target_word)) {
    std::cout << "Error! The word '" << target_terminology << "' was not found!" << std::endl;

    util::wait_for_input();
  }
  else {
    word word_to_delete = WORD_TREE.search_node(target_word)->data;
    std::string message_next = "Enter the updated word";

    std::cout << std::endl;
    std::cout << "Updating the following word:" << std::endl;

    word_to_delete.display();

    WORD_TREE.remove(word_to_delete);

    std::cout << std::endl;
    add_word_helper(message_next);
  }
}

void print_tree() {
  util::clear_screen();

  std::cout << "                                         Display" << std::endl;
  std::cout << "────────────────────────────────────────────────" << std::endl;

  WORD_TREE.print();

  util::wait_for_input();
}
//------------------------------------------------//
//################################################//
