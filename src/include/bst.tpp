#include "bst.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
BST<T>::Node::Node() : data({}), left(nullptr), right(nullptr) {}

template <typename T>
BST<T>::Node::Node(const T& value) : data(value), left(nullptr), right(nullptr) {}

template <typename T>
BST<T>::BST() : count(0), root(nullptr) {}

template <typename T>
BST<T>::~BST() {}


template <typename T>
bool BST<T>::insert_helper(unique_ptr<typename BST<T>::Node>& node, const T& value) {
  try {
    if(!node) {
      node = make_unique<typename BST<T>::Node>(value);
      return true;
    }

    if(value < node->data) {
      return insert_helper(node->left, value);
    } else if (value > node->data) {
      return insert_helper(node->right, value);
    } else {
      return false;
    }
  } catch(const bad_alloc& e) {
      cerr << "Memory allocation failed: " << e.what() << endl;
      return false;
  }
}

template <typename T>
bool BST<T>::insert(const T& value) {
  try {
    if (insert_helper(root, value)) {
      count++;
      return true;
    }
    return false;
  } catch (const bad_alloc& e) {
      cerr << "Memory allocation failed: " << e.what() << endl;
      return false;
  }
}
/* -001
// in-order traversal
template <typename T>
void BST<T>::traverse_helper(unique_ptr<typename BST<T>::Node>& node, void (*callback)(const T& value)) {
  if (node) { //if nullptr prnit --> empty tree
    try {
      traverse_helper(node->left.get(), callback);
      callback(node->data);
      traverse_helper(node->right.get(), callback);
    }
    catch (const exception& e) {
      cerr << "Exception occured : " << e.what() << endl;
    }
  }
}
*/
/*
template <typename T>
void BST<T>::traverse_helper(unique_ptr<typename BST<T>::Node>& node, void (*callback)(const T& value)) {
  if (node) { //if nullptr prnit --> empty tree
    try {
      traverse_helper(node->left.get(), callback);
      callback(node->data);
      traverse_helper(node->right.get(), callback);
    }
    catch (const exception& e) {
      cerr << "Exception occured : " << e.what() << endl;
    }
  }
}
*/
/* -001
template <typename T>
void BST<T>::traverse(void (*callback)(const T& value)) const {
  try {
    traverse_helper(root.get(), callback);
  }
  catch (const exception& e) {
    cerr << "Exception occured : " << e.what() << endl;
  }
}
*/
/*
template <typename T>
void BST<T>::print_bst(const T& value) const {
  try {
    cout << value << " ";
  }
  catch (const exception& e) {
    cerr << "Exception occured : " << e.what() << endl;
  }
}
*/
template <typename T>
//void BST<T>::print_bst_helper(unique_ptr<BST<T>::Node>& node) const {
void BST<T>::print_bst_helper(BST<T>::Node* node) const {
  if(node) {
    try{
      print_bst_helper(node->left.get());
      cout << node->data << " ";
      print_bst_helper(node->right.get());
    }
    catch(const exception& e){
      cerr << "Exception occured : " << e.what() << endl;
    }
  }
}

template <typename T>
void BST<T>::print_bst() const {
  print_bst_helper(root.get());
}

template <typename T>
T* BST<T>::search_helper(const unique_ptr<typename BST<T>::Node>& node, const T& key) const {
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
      return &(node->data);
    }
  }
  catch (const exception& e) {
    cerr << "Exception occured : " << e.what() << endl;
    return nullptr;
  }
}

template <typename T>
T* BST<T>::search(const T& key) {
  try {
    return search_helper(root, key);
  }
  catch (const exception& e) {
    cerr << "Exception occured : " << e.what() << endl;
    return nullptr;
  }
}

template <typename T>
bool BST<T>::remove_helper(unique_ptr<typename BST<T>::Node>& node, const T& value) {
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
        Node* successor = node->right.get();
        while (successor->left) {
          successor = successor->left.get();
        }
        node->data = successor->data;
        remove_helper(node->right, successor->data);
      }
      return true;
    }
  }
  catch (const exception& e) {
    cerr << "Exception occured: " << e.what() << endl;
    return false;
  }
}

template <typename T>
bool BST<T>::remove(const T& value) {
  try {
    if (remove_helper(root, value)) {
      count--;
      return true;
    }
    return false;
  }
  catch (const exception& e) {
    cerr << "Exception occured: " << e.what() << endl;
    return false;
  }
}

template <typename T>
bool BST<T>::is_empty() const {
  return count == 0;
}

/*
template <typename T>
bool BST<T>::is_full() const {

}
*/

template <typename T>
size_t BST<T>::get_count() const {
  return count;
}
