#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

template <class T>

class TreeNode
{
public:
  TreeNode();
  TreeNode(T value);
  ~TreeNode(); 
  T person;
  T getData();
  TreeNode *left;
  TreeNode *right;
};

template <class T>
TreeNode<T>::TreeNode()
{
  
}
template <class T>
TreeNode<T>::TreeNode(T value)
{
  left = NULL;
  right = NULL;
  person = value;
}
template <class T>
TreeNode<T>::~TreeNode()
{
  
}
template <class T>
T TreeNode<T>::getData()
{
  return person;
}

#endif