#ifndef BST_TPP
#define BST_TPP

#include "bst.h"
#include <iostream>
#include <stdexcept>
#include <limits> // for clearing input buffer

using namespace std;


namespace ds {
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
      cerr << "Memory allocation failed: " << e.what() << std::endl;
      return false;
    }
  }

  template <typename T>
  typename bst<T>::Node * bst<T>::search_helper(const unique_ptr<typename bst<T>::Node> & node, const T & key) const {
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
        return node.get();
      }
    }
    catch (const exception & e) {
      cerr << "Exception occured : " << e.what() << std::endl;
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
      cerr << "Exception occured: " << e.what() << std::endl;
      return false;
    }
  }

  template <typename T>
  void bst<T>::print_helper(bst<T>::Node * root, size_t level, std::string prefix) const {
    if(root != nullptr) {
      if(level == 0) {
        std::cout << prefix << root -> data << std::endl;
      }
      else {
        std::string indent(level * 4, ' ');
        std::cout << indent << "└── " << prefix << root -> data << std::endl;
      }

      if(root -> left != nullptr || root -> right != nullptr) {
        print_helper(root -> left.get(), level + 1, "Left: ");
        print_helper(root -> right.get(), level + 1, "Right: ");
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
      cerr << "Memory allocation failed: " << e.what() << std::endl;
      return false;
    }
  }

  template <typename T>
  void bst<T>::print() const {
    if(root != nullptr)
      print_helper(root.get(), 0, "Root: ");
    else
      std::cout << "Binary-Search Tree is empty!" << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  template <typename T>
  T * bst<T>::search(const T & key) {
    try {
      return & search_helper(root, key)->data;
    }
    catch (const exception & e) {
      cerr << "Exception occured : " << e.what() << std::endl;
      return nullptr;
    }
  }

  template <typename T>
  typename bst<T>::Node * bst<T>::search_node(const T & key) {
    try {
      return search_helper(root, key);
    }
    catch(const exception & e) {
      cerr << "Exception occured : " << e.what() << std::endl;
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
      cerr << "Exception occured: " << e.what() << std::endl;
      return false;
    }
  }


  template <typename T>
  bool bst<T>::is_empty() const {
    return count == 0;
  }

  template <typename T>
  bool bst<T>::is_full_helper(const unique_ptr<bst<T>::Node> & node) const {
    try {
      if(!node)
        return true;
      if((node->left && !node->right) || (!node->left && node->right))
        return false;
      return is_full_helper(node->left) && is_full_helper(node->right);
    }
    catch (const exception & e) {
      cerr << "Exception occured: " << e.what() << std::endl;
    }
  }

  template <typename T>
  bool bst<T>::is_full() const {
    try {
      return is_full_helper(root);
    }
    catch (const exception & e) {
      cerr << "Exception occured: " << e.what() << std::endl;
    }
  }

  template <typename T>
  size_t bst<T>::get_count() const {
    return count;
  }

  template <typename T>
  typename bst<T>::Node * bst<T>::get_root() const {
    return root.get();
  }
}

#endif
