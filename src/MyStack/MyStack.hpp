#ifndef MYSTACK_H
#define MYSTACK_H

template <typename T>
class MyStack{
    T *my_stack;
    int top;
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