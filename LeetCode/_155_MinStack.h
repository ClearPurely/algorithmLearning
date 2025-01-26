#pragma once
#include "../Solution.h"
//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

//最小栈
class _155_MinStack : public Solution
{
private:
    stack<int>* data;
    stack<int>* minStack;

public:
    _155_MinStack();
    ~_155_MinStack();

    //将元素val推入堆栈。
    void push(int val);

    //删除堆栈顶部的元素。
    void pop();

    // 获取堆栈顶部的元素。
    int top();

    //获取堆栈中的最小元素。
    int getMin();

};

