
#include "split.h"
#include <iostream>

int main()
{
  Node* tail= new Node(2,nullptr);
  Node* one= new Node(4,tail);
  Node* head= new Node(7,one);
  
  Node* odds= nullptr;
  Node* evens= nullptr; 

  split(head, odds, evens);

  while(odds)
  {
    std:: cout<< odds-> value <<", ";
    odds= odds-> next; 
  }
  while(evens)
  {
    std::cout<<evens->value << ", ";
    evens= evens->next;
  }
  delete tail;
  delete one;
  delete head;

  return 0; 
}