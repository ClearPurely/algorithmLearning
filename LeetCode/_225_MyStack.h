#pragma once
#include "../Solution.h"
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

//用队列实现栈
class _225_MyStack : public Solution
{
private:
    queue<int>* queue1;

public:
    _225_MyStack();

    ~_225_MyStack();

    //将元素 x 压入栈顶。
    void push(int x);

    //移除并返回栈顶元素。
    int pop();

    //返回栈顶元素。
    int top();

    //如果栈是空的，返回 true ；否则，返回 false 。
    bool empty();

};

