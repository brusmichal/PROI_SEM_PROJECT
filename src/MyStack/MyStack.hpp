#ifndef MYSTACK_H
#define MYSTACK_H

template <typename T>
class MyStack{
    T *my_stack;
    int top;
public:
    MyStack();
    ~MyStack();
    
    void push(T instance);
    void pop();
    void read();
};
#endif