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

void MyStack<T>::Push(const T& instance){
    my_stack[++top] = instance;
};

template <typename T>

void MyStack<T>::Pop(){
    if(IsEmpty())
        throw "Cannot pop nonexistent element from the stack";

    delete my_stack[top--];

};

template <typename T>

 void MyStack<T>::Read(){
     for(int i = top; i > -1; i--)
         std::cout << i+1 << ") " << T << std::endl;
     ~MyStack();
};

template <typename T>
bool MyStack<T> :: IsEmpty(){
    return top == -1 ? true : false;
};
