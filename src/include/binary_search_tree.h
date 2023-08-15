#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

// change it to include only the specific headers
//#include<bits/stdc++.h>
#include <stdexcept>

#define endl "\n"

namespace tree {
  template<typename T>
  class binary_tree {
    private:
      struct node {
        T data;
        node * left;
        node * right;

        node(T data);
      };

      node root;

      node * insert_core(node * current_root, T data);

    public:
      binary_tree();
      ~ binary_tree();

      void insert(T data);
  };
}
#endif
