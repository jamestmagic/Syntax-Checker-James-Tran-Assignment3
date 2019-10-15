#include <iostream>
using namespace std;

template <class T>
class GenStack{
public:
  GenStack();//constructor
  GenStack(int maxSize); //destructor
  ~GenStack();
  void push(T);
  T pop();
  T peek();

  bool isFull();
  bool isEmpty();
  void increaseSize();
  void setSize(int newSize);

  int size;
  int top;

  T *myArray;
};

template <class T>
GenStack<T>::GenStack(){ //constructor
  myArray = new T[0];
  size = 0;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){ //destructor
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
  try{
    myArray[++top] = d;
  }
  catch(...){
    cout << "Stack is empty. Can not push." << endl;
  }
}

template <class T>
T GenStack<T>::pop(){
  try{
    return myArray[top--];
  }
  catch(...){
    cout << "Stack is empty. Can not pop." << endl;
  }
}

template <class T>
T GenStack<T>::peek(){
  try{
    return myArray[top];
  }
  catch(...){
    cout << "Stack is empty. Can not pop." << endl;
  }

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

template <class T>
void GenStack<T>::setSize(int newSize){
  size = newSize;
}
