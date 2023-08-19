#include "../src/include/bst.h"
#include <iostream>

using namespace std;

int main() {
  bst<int> bst;
  int a = 1;

  for(int i = 1; i < 999; i++) {
    bst.insert(i);
  }

  // Print the elements using the traverse method
  std::cout << "In-order traversal: ";
  bst.print_bst();
  std::cout << std::endl;

  // Search for an element
  int key = 30;
  int* result = bst.search(key);
  if (result) {
    std::cout << "Element " << key << " found in the bst." << std::endl;
  }
  else {
    std::cout << "Element " << key << " not found in the bst." << std::endl;
  }

  // Remove an element
  int to_remove = 30;
  if (bst.remove(to_remove)) {
    std::cout << "Element " << to_remove << " removed from the bst." << std::endl;
  }
  else {
    std::cout << "Element " << to_remove << " not found in the bst or removal failed." << std::endl;
  }

  // Print the count of elements
  std::cout << "Number of elements in the bst: " << bst.get_count() << std::endl;

  // Check if the bst is empty
  if (bst.is_empty()) {
    std::cout << "The bst is empty." << std::endl;
  }
  else {
    std::cout << "The bst is not empty." << std::endl;
  }

  return 0;
}
