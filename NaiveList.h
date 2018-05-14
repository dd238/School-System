#ifndef NAIVELIST_H
#define NAIVELIST_H

#include <string>
#include "ListNode.h"
using namespace std;

template <class T>
class NaiveList
{
  private:
    ListNode<T>* front; //pointer to front of LL
    ListNode<T>* back;
    unsigned int size;

  public:
    NaiveList();
    ~NaiveList();
    unsigned int getSize();
    void insertFront(T data);
    void insertBack(T data);
    void printList();

    T removeFront();
    int find(T d);
    void removeNode(T val);


    //bool isEmpty();
    //T deletePos(int pos);
};

template <class T>
NaiveList<T>::NaiveList()
{
  this->size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
NaiveList<T>::~NaiveList()
{
}

template <class T>
unsigned int NaiveList<T>::getSize()
{
  return this->size;
}

template <class T>
void NaiveList<T>::insertFront(T data)
{
  ListNode<T>* node = new ListNode<T>(data);
  if(this->getSize() == 0)
  {
    this->back = node;
    this->front = node;
  }
  else
  {
    node->next = front;
    node->next->prev = node;
    front = node;
  }
  ++size;
}

template <class T>
void NaiveList<T>::insertBack(T data)
{
  //need to check if list is empty
  size++;
  ListNode<T>* node = new ListNode<T>(data);

  if(front == NULL)
    front = node;
  else
    back->next = node;
}

template <class T>
void NaiveList<T>::printList()
{
  if(front == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  ListNode<T> *current  = front;
  while(true)
  {
    cout << current->data << endl;
    if(current->next == NULL)
    {
        break;
    }
    current = current->next;
  }
}

template <class T>
T NaiveList<T>::removeFront()
{
  T temp = front->data;
  ListNode<T>* oldFront = front;
  if (front->next == NULL)
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front = front->next;
  delete oldFront;
  --size;
  return temp;
}

template <class T>
int NaiveList<T>::find(T data)//finds first instance of data, or returns -1 if none are found
{
  //make necessary checks
  int idx = -1;
  ListNode<T>* current = front;
  while(current->next != NULL)
  {
    ++idx;
    if(current->data == data)
    {
      break;
    }
    else
    {
      current = current->next;
    }
  }
  return idx;
}

/*
template <class T>
T NaiveList<T>::deletePos(int pos)
{
  int idx = 0;
  ListNode* current = front;
  ListNode* prev = front;
  while(idx != pos)//keep looping until finding node that needs to be deleted
  {
    ++idx;
    prev = current;
    current = current->next;
    //dont ever want to move front
  }
  //found our position/node
  prev->next = current->next;
  current->next = NULL;
  int d = current->data;
  delete current;
  size--;

  return d;
}
*/

template <class T>
void NaiveList<T>::removeNode(T val)
{
  ListNode<T>* current = front;
  while(current->data != val)
  {
    current = current->next;
    if(current == NULL)
    {
      return;
    }
  }
  if(current == front)
  {
    front = current->next;
  }
  else
  {
    current->prev->next = current->next;
  }
  if(current == back)
  {
    back = current->prev;
  }
  else
  {
    current->next->prev = current->prev;
  }
  current->next = NULL;
  current->prev = NULL;
  size--;
}

#endif