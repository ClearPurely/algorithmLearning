#pragma once
#include "../Solution.h"
///设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首
//之后以形成一个循环。它也被称为“环形缓冲器”。循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一
//个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

//循环队列
class _622_MyCircularQueue : public Solution
{
private:
    //vector<int>* queue;
    vector<int> queue;
    int l, r, size, limit;

public:
    //构造器，设置队列长度为k 
    _622_MyCircularQueue(int k);

    ~_622_MyCircularQueue();

    //向循环队列插入一个元素。如果成功插入则返回真。
    bool enQueue(int value);

    //从循环队列中删除一个元素。如果成功删除则返回真。
    bool deQueue();

    //从队首获取元素。如果队列为空，返回 -1 。
    int Front();

    //获取队尾元素。如果队列为空，返回 -1 。
    int Rear();

    //检查循环队列是否为空。
    bool isEmpty();

    //检查循环队列是否已满。
    bool isFull();
};