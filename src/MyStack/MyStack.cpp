#include "MyStack.hpp"

template <typename T>

MyStack <T>::MyStack(){
    stackSize = 0;
    myStack = new T[stackSize];
    //top = -1;
};

template <typename T>

MyStack <T>::~MyStack(){
     delete[] myStack;
};

template <typename T>

void MyStack<T>::Push(const T& instance){
    T* newStack;
    for(int i=0; i< stackSize; i++){
        newStack[i] = myStack[i];
    };
    newStack[stackSize++] = instance;
    delete[] myStack;
    myStack = newStack;

    //myStack[++top] = instance;
};

template <typename T>

void MyStack<T>::Pop(){
    if(IsEmpty())
        throw "Cannot pop nonexistent element from the stack";

    delete myStack[--stackSize];

};

template <typename T>

 void MyStack<T>::Read(){
     for(int i = stackSize-1; i > -1; i--)
         std::cout << i+1 << ") " << myStack[i] << std::endl;
     ~MyStack();
};

template <typename T>
bool MyStack<T> :: IsEmpty(){
    return stackSize == 0 ? true : false;
};
