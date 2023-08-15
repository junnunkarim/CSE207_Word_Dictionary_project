#include "binary_search_tree.h"
#include <stdexcept>

#define endl "\n"

namespace tree {
  template<typename T>
  binary_tree<T>::node::node(T data) : data(data), left(nullptr), right(nullptr) {}

  template<typename T>
  binary_tree<T>::binary_tree() : root(nullptr) {}

  template<typename T>
  binary_tree<T>::~binary_tree() {}

  template<typename T>
  typename binary_tree<T>::node * binary_tree<T>::insert_core(node * current_root, T data) {
    try {
      if(current_root == nullptr) {
        node * new_node = new node(data);
        return new_node;
      }
      else if( data < (current_root -> data) )
        insert_core(current_root -> left, data);
      else
        insert_core(current_root -> right, data);

      return current_root;
    }
    catch(const bad_alloc & e) {
      throw runtime_error("Cannot allocate space!");
    }
  }
}
