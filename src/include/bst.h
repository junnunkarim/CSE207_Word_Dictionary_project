/*
  Header file for Binary Search Tree (BST).
  It contains structural definitions and
  prototypes for BST.

  Written by : Md Murad Khan Limon
  Date       : 18 August, 2023
*/
//#pragma once
#ifndef BST_H
#define BST_H

#include <memory>
#include <cstddef>
using namespace std;

template <typename T>
class BST {
private:
  struct Node {
    T data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node();
    Node(const T& value);
  };
  size_t count;
  unique_ptr<Node> root;

  bool insert_helper(unique_ptr<Node>& node, const T& value);
  //void traverse_helper(unique_ptr<Node>& node, void (*callback)(const T& value));
  //void print_bst(const T& value) const;
  T*   search_helper(const unique_ptr<Node>& node, const T& key) const;
  bool remove_helper(unique_ptr<Node>& node, const T& value);
  //void print_bst_helper(unique_ptr<Node>& node) const;
  void print_bst_helper(BST<T>::Node* node) const;
public:
  //template <typename T>
  /*struct Node {
    T data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node();
    Node(const T& value);
  };*/

  BST();
  ~BST();

  bool   insert(const T& value);
  bool   remove(const T& value);
  T*     search(const T& key);
  //void   traverse(void (*callback)(const T& value)) const;
  bool   is_empty() const;
  bool   is_full() const;
  size_t get_count() const;
  //void   print_bst(const T& value) const;
  void print_bst() const;

};
#include "bst.tpp"
#endif // BST_H
