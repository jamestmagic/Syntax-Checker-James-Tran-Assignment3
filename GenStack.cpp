// #include <iostream>
// using namespace std;
//
// template <class T>
// class GenStack{
// public:
//   GenStack();//constructor
//   GenStack(int maxSize);
//   ~GenStack();
//   void push(T);
//   T pop();
//   T peek();
//
//   bool isFull();
//   bool isEmpty();
//   void increaseSize();
//   void setSize(int newSize);
//
//   int size;
//   int top;
//
//   T *myArray;
// };
//
// template <class T>
// GenStack<T>::GenStack(){ //default constructor
//   myArray = new T[0];
//   size = 0;
//   top = -1;
// }
//
// template <class T>
// GenStack<T>::GenStack(int maxSize){ //overloaded constructor
//   myArray = new T[maxSize];
//   size = maxSize;
//   top = -1;
// }
//
// template <class T>
// GenStack<T>::~GenStack(){ //destructor
//   delete[] myArray;
// }
//
// template <class T>
// void GenStack<T>::push(T d){
//     // if (isFull()) //doubles the size of the array if full
//     // {
//     //    increaseSize();
//     // }
//     myArray[++top] = d;
// }
//
// template <class T>
// T GenStack<T>::pop(){ //returns and removes top element
//   try{
//     if(isEmpty()){
//       throw 'd';
//     }
//     return myArray[top--];
//   }
//   catch(...){
//     cout << "Stack is empty. Can not pop." << endl;
//   }
// }
//
// template <class T>
// T GenStack<T>::peek(){ //returns the top element
//   if(isEmpty()){
//     return myArray[top];
//   }
//   else{
//     cout << "Stack is Empty, can not peek" << endl;
//     return NULL;
//   }
// }
//
// template <class T>
// bool GenStack<T>::isFull(){ //check if the stack is full
//   return(top == size-1);
// }
//
// template <class T>
// bool GenStack<T>::isEmpty(){ //checks if the stack is empty
//   return(top == -1);
// }
//
// template <class T>
// void GenStack<T>::increaseSize(){ //doubles the size once the stack is full
//   int doubleSize = size*2;
//   T *temp = myArray;
//   T *nextStack = new T[doubleSize];
//   for(int i = 0;i<size;++i){
//     nextStack[i] = temp[i];
//   }
//   myArray = nextStack;
//   delete[] temp;
//   delete[] nextStack;
// }
//
// template <class T>
// void GenStack<T>::setSize(int newSize){ //sets the size
//   size = newSize;
// }
