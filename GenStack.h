#include <iostream>
using namespace std;

template <class T>
class GenStack
{
public:
  int top;
  int max;
  T *myArray;

  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  void push(T data);
  T pop();
  T peek();
  bool isFull();
  bool isEmpty();
  void adjSize();
};

template <class T>
GenStack<T>::GenStack()
{

}

template <class T>
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T[maxSize];
  max = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack()
{
  delete myArray;
  cout << "GenStack object destroyed" << endl;
}

template <class T>
void GenStack<T>::push(T data)
{
  if (isFull())
  {
    adjSize();
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop()
{
  if (isEmpty())
  {
    throw range_error("The stack cannot be popped when it is empty");
  }
  return myArray[top--];
}

template <class T>
T GenStack<T>::peek()
{
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull()
{
  return (top == max - 1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
void GenStack<T>::adjSize()
{
  cout << "size of stack increased" << endl;
  max *= 4;
  T *tempArray;
  tempArray = new T[max];
  for (int i = 0; i <= top; ++i)
  {
    tempArray[i] = myArray[i];
  }
  myArray = tempArray;
}
