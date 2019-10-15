#include <iostream>
using namespace std;

template <class T>
class GenStack{
public:
  GenStack();//constructor
  GenStack(int maxSize);
  ~GenStack();
  void push(T);
  T pop();
  T peek();

  bool isFull();
  bool isEmpty();
  void increaseSize();

  int size;
  int top;

  T *myArray;
};

template <class T>
GenStack<T>::GenStack(){
  myArray = new T[0];
  size = 0;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete[] myArray;
}

template <class T>
void GenStack<T>::push(T d){
  //need to check error/boundary check
  //research this
  myArray[++top] = d;
}

template <class T>
T GenStack<T>::pop(){
  //make sure it's not empty
  return myArray[top--];
}

template <class T>
T GenStack<T>::peek(){
  //check if isEmpty
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return(top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return(top == -1);
}

template <class T>
void GenStack<T>::increaseSize(){
  int doubleSize = size*2;
  T *temp = myArray;
  T *nextStack = new T[doubleSize];
  for(int i = 0;i<size;++i){
    nextStack[i] = temp[i];
  }
  myArray = nextStack;
  delete[] temp;
  delete[] nextStack;
}
