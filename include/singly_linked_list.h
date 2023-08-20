/*
  Header file for Linked-List.
  It contains structural definitions and
  prototypes for Linked-List.

  Written by : Junnun Mohamed Karim
*/

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include <cstddef>

using namespace std;

template <typename T>
class singly_linked_list {
  private:
    struct node {
      T data;
      node * next;

      node();
      node(const T & data);
    };

    node * head;
    int size;

  public:
    singly_linked_list();
    ~singly_linked_list();


    bool insert_front(const T & data);
    bool insert_back(const T & data);
    bool delete_front();
    bool delete_back();
    bool delete_key(const T & key);
    bool search(const T & key);
    void print();
    node * begin() const;
    node * end() const;
};

#include "singly_linked_list.tpp"

#endif
