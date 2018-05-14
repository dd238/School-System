#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>
using namespace std;

template <class T>
class ListNode
{
 public:
    T data;
    ListNode *next;
 	ListNode *prev;
    ListNode();
    ListNode(T data);
    ~ListNode();
};

template <class T>
ListNode<T>::ListNode()
{

}

template <class T>
ListNode<T>::ListNode(T data)
{
  this->data = data;
  this->next = NULL;
  this->prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{}

#endif