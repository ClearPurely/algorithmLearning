#pragma once
#include "../Solution.h"
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）


//用栈实现队列
class _232_MyQueue : public Solution
{

private:
    stack<int>* in;
    stack<int>* out;

public:
    _232_MyQueue();
    ~_232_MyQueue();

    //关键思路：
    // 倒数据
    // 从in栈，把数据倒入out栈
    // 1) out空了，才能倒数据(把in的数据取到out)
    // 2) 如果倒数据，in必须倒完
    void inToOut();

    //将元素 x 推到队列的末尾
    void push(int x);
    //从队列的开头移除并返回元素
    int pop();

    //返回队列开头的元素
    int peek();

    //如果队列为空，返回 true ；否则，返回 false
    bool empty();
};

