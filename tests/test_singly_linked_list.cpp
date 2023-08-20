#include "../include/singly_linked_list.h"
#include<bits/stdc++.h>

int main() {
  ds::singly_linked_list<int> list;

  std::cout << "insert" << endl;
  list.insert_front(4);
  list.insert_front(2);
  list.print();
  std::cout << endl;

  std::cout << "delete key" << endl;
  if(list.delete_key(2))
    std::cout << "deleted 2" << endl;
  else
    std::cout << "2 not found" << endl;

  if(list.delete_key(3))
    std::cout << "deleted 3" << endl;
  else
    std::cout << "3 not found" << endl;
  list.print();
  std::cout << endl;

  std::cout << "insert front" << endl;
  list.insert_front(2);
  list.insert_front(3);
  list.insert_front(4);
  list.insert_front(5);
  list.insert_front(6);
  list.insert_front(7);
  list.insert_front(8);
  list.print();
  std::cout << endl;

  std::cout << "insert back" << endl;
  list.insert_back(10);
  list.insert_back(11);
  list.insert_back(12);
  list.insert_back(12);
  list.insert_back(12);
  list.print();
  std::cout << endl;

  std::cout << "delete front" << endl;
  list.delete_front();
  list.print();
  std::cout << endl;

  std::cout << "delete back" << endl;
  list.delete_back();
  list.print();
  std::cout << endl;

  std::cout << "delete key" << endl;
  list.delete_key(2);
  list.delete_key(12);
  list.print();
  std::cout << endl;

  std::cout << "search key" << endl;
  if(list.search(12))
    std::cout << "found 12" << endl;
  else
    std::cout << "12 is not found" << endl;

  if(list.search(344))
    std::cout << "found 344" << endl;
  else
    std::cout << "344 is not found" << endl;


  ds::singly_linked_list<float> list_other;

  list_other.insert_front(9.434);
  list_other.insert_front(4.232);
  list_other.print();

  ds::singly_linked_list<std::string> list_string;

  list_string.insert_back("something");
  list_string.insert_back("another");
  list_string.print();
}
