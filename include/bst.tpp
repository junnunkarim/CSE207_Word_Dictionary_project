/**
 * @file bst.tpp
 * @brief Implementation of a Binary Search Tree (BST) template class.
 */

#ifndef BST_TPP
#define BST_TPP

#include "bst.h"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <limits> // for clearing input buffer

namespace ds {

  /**
   * @brief Default constructor for Node.
   * Initializes a new Node with default values.
   */
  template <typename T>
  bst<T>::Node::Node() : data({}), left(nullptr), right(nullptr) {}

  /**
   * @brief Constructor for Node with initial value.
   * Initializes a new Node with the given value.
   * @param value The initial value to set.
   */
  template <typename T>
  bst<T>::Node::Node(const T & value) : data(value), left(nullptr), right(nullptr) {}

  /**
   * @brief Default constructor for Binary Search Tree.
   * Initializes a new BST with default values.
   */
  template <typename T>
  bst<T>::bst() : count(0), root(nullptr) {}

  /**
   * @brief Destructor for Binary Search Tree.
   * Cleans up memory used by the BST.
   */
  template <typename T>
  bst<T>::~bst() {}

  /**
   * @brief Helper function to insert a value into the Binary Search Tree.
   * Inserts the given value into the tree.
   * @param node Reference to the current node.
   * @param value The value to insert.
   * @return True if the insertion was successful, false otherwise.
   */
  template <typename T>
  bool bst<T>::insert_helper(std::unique_ptr<typename bst<T>::Node> & node, const T & value) {
    try {
      if(!node) {
        node = std::make_unique<typename bst<T>::Node>(value);
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
    catch(const std::bad_alloc & e) {
      std::cerr << "Memory allocation failed: " << e.what() << std::endl;
      return false;
    }
  }

  /**
   * @brief Helper function to search for a value in the Binary Search Tree.
   * Recursively searches for the given value in the tree.
   * @param node Pointer to the current node.
   * @param key The value to search for.
   * @return Pointer to the node containing the value, or nullptr if not found.
   */
  template <typename T>
  typename bst<T>::Node * bst<T>::search_helper(const std::unique_ptr<typename bst<T>::Node> & node, const T & key) const {
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
    catch (const std::exception & e) {
      std::cerr << "Exception occured : " << e.what() << std::endl;
      return nullptr;
    }
  }

  /**
   * @brief Helper function to remove a value from the Binary Search Tree.
   * Recursively removes the given value from the tree.
   * @param node Reference to the current node.
   * @param value The value to remove.
   * @return True if the removal was successful, false otherwise.
   */
  template <typename T>
  bool bst<T>::remove_helper(std::unique_ptr<typename bst<T>::Node> & node, const T & value) {
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
    catch (const std::exception & e) {
      std::cerr << "Exception occured: " << e.what() << std::endl;
      return false;
    }
  }

  /**
   * @brief Helper function to print the Binary Search Tree.
   * Recursively prints the structure of the tree.
   * @param root Pointer to the root of the tree.
   * @param level Current level in the tree traversal.
   * @param prefix Prefix to display for each node.
   */
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

  /**
   * @brief Insert a value into the Binary Search Tree.
   * Inserts the given value into the tree.
   * @param value The value to insert.
   * @return True if the insertion was successful, false otherwise.
   */
  template <typename T>
  bool bst<T>::insert(const T & value) {
    try {
      if (insert_helper(root, value)) {
        count++;
        return true;
      }
      return false;
    }
    catch (const std::bad_alloc & e) {
      std::cerr << "Memory allocation failed: " << e.what() << std::endl;
      return false;
    }
  }

  /**
   * @brief Print the Binary Search Tree.
   * Prints the structure of the tree.
   */
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
    catch (const std::exception & e) {
      std::cerr << "Exception occured : " << e.what() << std::endl;
      return nullptr;
    }
  }

  template <typename T>
  typename bst<T>::Node * bst<T>::search_node(const T & key) {
    try {
      return search_helper(root, key);
    }
    catch(const std::exception & e) {
      std::cerr << "Exception occured : " << e.what() << std::endl;
      return nullptr;
    }
  }

  /**
   * @brief Remove a value from the Binary Search Tree.
   * Removes the given value from the tree.
   * @param value The value to remove.
   * @return True if the removal was successful, false otherwise.
   */
  template <typename T>
  bool bst<T>::remove(const T & value) {
    try {
      if (remove_helper(root, value)) {
        count--;
        return true;
      }
      return false;
    }
    catch (const std::exception & e) {
      std::cerr << "Exception occured: " << e.what() << std::endl;
      return false;
    }
  }

  /**
   * @brief Check if the Binary Search Tree is empty.
   * @return True if the tree is empty, false otherwise.
   */
  template <typename T>
  bool bst<T>::is_empty() const {
    return count == 0;
  }

  template <typename T>
  bool bst<T>::is_full_helper(const std::unique_ptr<bst<T>::Node> & node) const {
    try {
      if(!node)
        return true;
      if((node->left && !node->right) || (!node->left && node->right))
        return false;
      return is_full_helper(node->left) && is_full_helper(node->right);
    }
    catch (const std::exception & e) {
      std::cerr << "Exception occured: " << e.what() << std::endl;
    }
  }

  /**
   * @brief Check if the Binary Search Tree is a full binary tree.
   * @return True if the tree is a full binary tree, false otherwise.
   */
  template <typename T>
  bool bst<T>::is_full() const {
    try {
      return is_full_helper(root);
    }
    catch (const std::exception & e) {
      std::cerr << "Exception occured: " << e.what() << std::endl;
    }
  }

  /**
   * @brief Get the count of nodes in the Binary Search Tree.
   * @return The number of nodes in the tree.
   */
  template <typename T>
  size_t bst<T>::get_count() const {
    return count;
  }


  /**
   * @brief Get a pointer to the root node of the Binary Search Tree.
   * @return Pointer to the root node, or nullptr if the tree is empty.
   */
  template <typename T>
  typename bst<T>::Node * bst<T>::get_root() const {
    return root.get();
  }
}

#endif
