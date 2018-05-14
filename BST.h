#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <class T>
class BST
{
public:
  BST();
  ~BST();
  void insert(T value); //should be thinking templates though, not just int
  TreeNode<T>* search(T value);
  TreeNode<T>* searchHelper(T value, TreeNode<T>* n);
  bool deleteNode(T value);
  bool isEmpty();
  TreeNode<T>* getMin();//left most
  TreeNode<T>* getMax();//right most
  TreeNode<T>* getSuccessor(TreeNode<T>* d); //for deleteNode, helper function
  TreeNode<T>* getRoot();
  void print();
  void inOrder(TreeNode<T> * n);
private:
  TreeNode<T>* root;
};

template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
BST<T>::~BST()
{
  //iterate and delete
  //linear
}

template <class T>
void BST<T>::insert(T value) //like a failed search, here it is done iteratively, but could be faster recursively
{
  TreeNode<T>* person = new TreeNode<T>(value);
  if (root == NULL)//tree is empty
  {
    root = person;
  }
  else
  {
    TreeNode<T>* current = root; //start at the root
    TreeNode<T>* parent; //empty for now

    while(true)
    {
      parent = current;
      if(value < current->getData())
      {
        current = current->left;
        if(current == NULL)//found our position
        {
          parent->left = person;
          break;
        }//finish this on going to the right

      }
      else//go right
      {
        current = current->right;
        if(current == NULL)//found our position
        {
          parent->right = person;
          break;
        }
      }


    }
  }
}


template <class T>
TreeNode<T>* BST<T>::search(T value)
{
  return searchHelper(value, root);
}

template <class T>
TreeNode<T>* BST<T>::searchHelper(T value, TreeNode<T>* n)
{
  if (value == n->getData())
  {
    return n;
  }
  else if (value < n->getData())
  {
    return searchHelper(value, n->left);
  }  
  else 
  {
    return searchHelper(value, n->right);
  }
    
}

template <class T>
bool BST<T>::deleteNode(T value)
{
    if(root == NULL)
    {
      return false;
    }

    TreeNode<T>* current = root; //always start at root
    TreeNode<T>* parent = NULL;
    bool isLeft; //which way the parent is pointing towards

    while(current->getData() != value)
    {
        parent = current;

        if(value < current->getData()) //go left
        {
            isLeft = true;
            current = current->left;
        }
        else //go right
        {
            isLeft = false;
            current = current->right;
        }

        if(current == NULL)
        {
          return false;
        }
    }
    //we found what needs to be deleted

    //case 1: no childeren
    if(current->left == NULL && current->right == NULL)
    {
      if(current->getData() == root->getData())
          root = NULL;
      else if(isLeft) //need to delete it from the parent, and this shows which side to delete
      {
          parent->left = NULL;
      }
      else
      {
          parent->right = NULL;
      }
    }
    //case 2: has one child
    else if (current->right == NULL) //no right child
    {
        if(current->getData() == root->getData())
            root = current->left;
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
          parent->right = current->left;
        }
    }
    else if (current->left == NULL) //no left child
    {
        if(current->getData() == root->getData())
            root = current->right;
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else
        {
          parent->right = current->right;
        }
    }
    //case 3: has two children/////
    else
    {
        TreeNode<T>* successor = getSuccessor(current);
        if(current->getData() == root->getData())
        {
          root = successor;
        }
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
          parent->right = successor;

        successor->left = current->left;
    }

    current->right = NULL;
    current->left = NULL;

    return true;

}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d) //the one in the parenthesis is the one we're going to delete
{
  TreeNode<T>* sp = d; //successor's parentss
  TreeNode<T>* successor = d; //will be one right, all the way left
  TreeNode<T>* current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;

}

template <class T>
TreeNode<T>* BST<T>::getRoot()
{
  return root;
}

template <class T>
TreeNode<T>* BST<T>::getMin()
{
  TreeNode<T>* current = root;
  if(root == NULL)
  {
    return NULL;
  }

  while(current->left != NULL)
  {
    current = current->left;
  }

  return current; //returning the (pointer to the) node, not the actual value, then you can do what you want with the node
}

template <class T>
TreeNode<T>* BST<T>::getMax()
{
  TreeNode<T>* current = root;
  if(root == NULL)
  {
    return NULL;
  }

  while(current->right != NULL)
  {
    current = current->right;
  }

  return current; //returning the (pointer to the) node, not the actual value, then you can do what you want with the node
}

template <class T>
void BST<T>::print()
{
  inOrder(root);
}

template <class T>
void BST<T>::inOrder(TreeNode<T>* n)
{
  if(n != NULL)
  {
    inOrder(n->left);
    n->person.print();
    inOrder(n->right);
  }
  return;
}

template <class T>
bool BST<T>::isEmpty()
{
  if(root == NULL)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

#endif



