#include "bst.h"
#include <iostream>
using namespace std;

// Function to print a value
/*
template <typename T>
void print_value(const T& value) {
  std::cout << value << " ";
}
*/
int main() {
  // Create an instance of the BST
  //BST<int>* bst = new BST<int>();
  BST<int> bst;
  int a = 1;
  // Insert some elements into the BST
  for(int i = 1; i < 999; i++) {
    bst.insert(i);
  }
  /*
  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
*/
  // Print the elements using the traverse method
  std::cout << "In-order traversal: ";
  bst.print_bst();
  //bst.traverse([](const int& value) { std::cout << value << " "; });
  std::cout << std::endl;

  // Search for an element
  int key = 30;
  int* result = bst.search(key);
  if (result) {
    std::cout << "Element " << key << " found in the BST." << std::endl;
  }
  else {
    std::cout << "Element " << key << " not found in the BST." << std::endl;
  }

  // Remove an element
  int to_remove = 30;
  if (bst.remove(to_remove)) {
    std::cout << "Element " << to_remove << " removed from the BST." << std::endl;
  }
  else {
    std::cout << "Element " << to_remove << " not found in the BST or removal failed." << std::endl;
  }

  // Print the count of elements
  std::cout << "Number of elements in the BST: " << bst.get_count() << std::endl;

  // Check if the BST is empty
  if (bst.is_empty()) {
    std::cout << "The BST is empty." << std::endl;
  }
  else {
    std::cout << "The BST is not empty." << std::endl;
  }

  // Check if the BST is full (assuming it's always false)
 /* if (bst.is_full()) {
    std::cout << "The BST is full." << std::endl;
  }
  else {
    std::cout << "The BST is not full." << std::endl;
  }*/

  return 0;
}
