/*
  Header file for Linked-List.
  It contains structural definitions and
  prototypes for Linked-List.

  Written by : Junnun Mohamed Karim
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstddef>

namespace ds {
  template <typename T>
  class list {
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
      list();
      ~list();


      bool insert_front(const T & data);
      bool insert_back(const T & data);
      bool delete_front();
      bool delete_back();
      bool delete_key(const T & key);
      bool search(const T & key);
      void print();
      node * begin() const;
      node * end() const;
      int get_size() const;

      T & operator[](int index);
  };
}

#include "list.tpp"

#endif
