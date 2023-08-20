/*
  Header file for Binary Search Tree (bst).
  It contains structural definitions and
  prototypes for bst.

  Written by : Md Murad Khan Limon
  Date       : 18 August, 2023
*/

#ifndef BST_H
#define BST_H

#include <memory>
#include <cstddef>

using namespace std;

template <typename T>
class bst {
  public:
    struct Node {
      T data;
      unique_ptr<Node> left;
      unique_ptr<Node> right;

      Node();
      Node(const T & value);
    };

  private:
    size_t count;
    unique_ptr<Node> root;

    bool insert_helper(unique_ptr<Node> & node, const T & value);
    T *  search_helper(const unique_ptr<Node> & node, const T & key) const;
    bool remove_helper(unique_ptr<Node> & node, const T & value);
    void print_bst_helper(bst<T>::Node * node) const;
    bool is_full_helper(const unique_ptr<Node> & node) const;

  public:
    bst();
    ~bst();

    bool insert(const T& value);
    bool remove(const T& value);
    T *  search(const T& key);
    void print_bst() const;

    bool is_empty() const;
    bool is_full() const;
    size_t get_count() const;
    Node * get_root() const;
};

#include "bst.tpp"

#endif // bst_H
