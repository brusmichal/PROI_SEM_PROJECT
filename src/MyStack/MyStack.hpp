#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <string>

template <typename T>
class MyStack{
    T *myStack;
   // int top;
    int stackSize;
public:
    MyStack();
    ~MyStack();
    
    void Push(const T& instance);
    void Pop();
    void Read();

    //metody pomocnicze
    bool IsEmpty();
};

#endif
