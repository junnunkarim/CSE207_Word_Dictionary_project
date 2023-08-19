#include "bst.h"
#include <iostream>
#include <stdexcept>

using namespace std;


template <typename T>
bst<T>::Node::Node() : data({}), left(nullptr), right(nullptr) {}

template <typename T>
bst<T>::Node::Node(const T & value) : data(value), left(nullptr), right(nullptr) {}

template <typename T>
bst<T>::bst() : count(0), root(nullptr) {}

template <typename T>
bst<T>::~bst() {}


template <typename T>
bool bst<T>::insert_helper(unique_ptr<typename bst<T>::Node> & node, const T & value) {
  try {
    if(!node) {
      node = make_unique<typename bst<T>::Node>(value);
      return true;
    }

    if(value < (node->data)) {
      return insert_helper(node->left, value);
    }
    else if (value > (node->data)) {
      return insert_helper(node->right, value);
    }
    else {
      return false;
    }
  }
  catch(const bad_alloc & e) {
    cerr << "Memory allocation failed: " << e.what() << endl;
    return false;
  }
}

template <typename T>
T * bst<T>::search_helper(const unique_ptr<typename bst<T>::Node> & node, const T & key) const {
  try {
    if (!node) {
      return nullptr;
    }

    if (key < node->data) {
      return search_helper(node->left, key);
    }
    else if (key > node->data) {
      return search_helper(node->right, key);
    }
    else {
      return & (node->data);
    }
  }
  catch (const exception& e) {
    cerr << "Exception occured : " << e.what() << endl;
    return nullptr;
  }
}

template <typename T>
bool bst<T>::remove_helper(unique_ptr<typename bst<T>::Node> & node, const T & value) {
  try {
    if (!node) {
      return false;
    }

    if (value < node->data) {
      return remove_helper(node->left, value);
    }
    else if (value > node->data) {
      return remove_helper(node->right, value);
    }
    else {
      if (!node->left) {
        node = move(node->right);
      }
      else if (!node->right) {
        node = move(node->left);
      }
      else {
        Node * successor = node->right.get();
        while (successor->left) {
          successor = successor->left.get();
        }
        node->data = successor->data;
        remove_helper(node->right, successor->data);
      }
      return true;
    }
  }
  catch (const exception & e) {
    cerr << "Exception occured: " << e.what() << endl;
    return false;
  }
}

template <typename T>
void bst<T>::print_bst_helper(bst<T>::Node * node) const {
  if(node) {
    try{
      print_bst_helper(node->left.get());
      cout << node->data << " ";
      print_bst_helper(node->right.get());
    }
    catch(const exception & e){
      cerr << "Exception occured : " << e.what() << endl;
    }
  }
}


template <typename T>
bool bst<T>::insert(const T & value) {
  try {
    if (insert_helper(root, value)) {
      count++;
      return true;
    }
    return false;
  }
  catch (const bad_alloc & e) {
    cerr << "Memory allocation failed: " << e.what() << endl;
    return false;
  }
}

template <typename T>
void bst<T>::print_bst() const {
  print_bst_helper(root.get());
}

template <typename T>
T * bst<T>::search(const T & key) {
  try {
    return search_helper(root, key);
  }
  catch (const exception & e) {
    cerr << "Exception occured : " << e.what() << endl;
    return nullptr;
  }
}

template <typename T>
bool bst<T>::remove(const T & value) {
  try {
    if (remove_helper(root, value)) {
      count--;
      return true;
    }
    return false;
  }
  catch (const exception & e) {
    cerr << "Exception occured: " << e.what() << endl;
    return false;
  }
}


template <typename T>
bool bst<T>::is_empty() const {
  return count == 0;
}

template <typename T>
size_t bst<T>::get_count() const {
  return count;
}
