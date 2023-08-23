#include <cstdlib>
#include <iostream>
#include <string>
#include <vector> // for std::vector
#include <stack> // for std::stack

#include "../include/bst.h"
#include "../include/word.h"
#include "../include/utility.h"

static ds::bst<word> WORD_TREE;

void print_menu();
int choice();
void print_suggestions(ds::bst<word>::Node * subtree);

void add_word_helper();

void add_word();
void search_word();
void delete_word();
void update_word();
void print_tree();

int main() {
  util::initialize();

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
  std::cout << "------------------------------------------------" << std::endl;
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

void print_suggestions(ds::bst<word>::Node * subtree) {
  std::vector<word> data;
  std::stack<ds::bst<word>::Node *> node_stack;

  ds::bst<word>::Node * current = subtree;

  while(current || !node_stack.empty()) {
    while(current) {
      node_stack.push(current);
      current = current->left.get();
    }

    current = node_stack.top();
    node_stack.pop();

    data.push_back(current->data);
    current = current->right.get();
  }

  int count = 0;

  // print the suggestions for the nearest words.
  std::cout << "Did you mean: ";

  for(const word & item : data){
    if(count >= 5){
      break;
    }

    std::cout << "\"" << item << "\"" << " ";
    count++;
  }

  std::cout << std::endl;
}
//------------------------------------------------//
//################################################//


void add_word_helper() {
  std::string terminology = {};
  std::string definition = {};

  terminology = util::input_word();

  std::cout << "Enter the definition of the word: " << std::endl;
  definition = util::input_sentence();

  // instantiate a word object named 'new_word'
  word new_word(terminology, definition);

  if (WORD_TREE.insert(new_word)) {
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
  std::cout << "------------------------------------------------" << std::endl;

  std::cout << "Enter the word you want to add: ";
  add_word_helper();
}

void search_word() {
  util::clear_screen();

  std::string target_str = {};
  ds::bst<word>::Node * root = WORD_TREE.get_root();

  std::cout << "                                          Search" << std::endl;
  std::cout << "------------------------------------------------" << std::endl;

  std::cout << "Enter the word you want to search: ";
  target_str = util::input_word();

  // instantiate a word object named 'target'
  word target(target_str, {});
  ds::bst<word>::Node * result = WORD_TREE.search_node(target);

  if(root != nullptr) {
    if(result == nullptr) {
      std::cout << "The word '" << target_str << "' was not found." << std::endl;

      util::wait_for_input();

      print_suggestions(result);
    }
    else {
      std::cout << std::endl;
      std::cout << "Search result:" << std::endl;

      (*result).data.display();

      util::wait_for_input();
    }
  }
}

void delete_word() {
  util::clear_screen();

  std::string terminology = {};

  std::cout << "                                     Delete Word" << std::endl;
  std::cout << "------------------------------------------------" << std::endl;

  std::cout << "Enter the word you want to delete: ";
  terminology = util::input_word();

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

  std::cout << "                                     Update Word" << std::endl;
  std::cout << "------------------------------------------------" << std::endl;

  print_tree();

  std::cout << "Enter the word you want to update: " << std::endl;

  target_terminology = util::input_word();
  word target_word(target_terminology, {});

  if(!WORD_TREE.search(target_word)) {
    std::cout << "Error! The word '" << target_terminology << "' was not found!" << std::endl;

    util::wait_for_input();
  }
  else {
    word word_to_delete = WORD_TREE.search_node(target_word)->data;

    std::cout << std::endl;
    std::cout << "Updating the following word:" << std::endl;

    word_to_delete.display();

    WORD_TREE.remove(word_to_delete);

    std::cout << std::endl;
    std::cout << "Enter the updated word: ";
    add_word_helper();
  }
}

void print_tree() {

}
//------------------------------------------------//
//################################################//
