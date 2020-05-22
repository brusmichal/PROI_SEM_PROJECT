#include "MyStack.hpp"

template <typename T>

MyStack <T>::MyStack(){
     my_stack = new T[];
     top = -1;
};

template <typename T>

MyStack <T>::~MyStack(){
     delete[] my_stack;
};

template <typename T>

void MyStack<T>::push(T instance){
    my_stack[++top] = instance;
};

template <typename T>

void MyStack<T>::pop(){
    if(IsEmpty())
        throw "Cannot pop nonexistent element from the stack";

    delete my_stack[top--];

};

template <typename T>

 void MyStack<T>::read(){
     for(int i = top; i > -1; i--)
         std::cout << i+1 << ") " << T << std::endl;
     ~MyStack();
};
