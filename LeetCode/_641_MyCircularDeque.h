#pragma once
#include "../Solution.h"
//设计循环双端队列

class _641_MyCircularDeque : public Solution
{
private:
    vector<int> dequeArr;
    int l, r, size, limit;
public:
    //构造函数,双端队列最大为k。
    _641_MyCircularDeque(int k)
    {
        dequeArr = vector<int>(k);
        l = r = size = 0;
        limit = k;
    }

    //将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        else 
        {
            if (isEmpty())
            {
                l = r = 0;
                dequeArr[0] = value;
            }
            else
            {
                l = l == 0 ? (limit - 1) : (l - 1);
                dequeArr[l] = value;
            }
            size++;
            return true;
        }

    }

    //将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        else
        {
            if (isEmpty())
            {
                l = r = 0;
                dequeArr[0] = value;
            }
            else
            {
                r = r == limit - 1 ? 0 : (r + 1);
                dequeArr[r] = value;
            }
            size++;
            return true;
        }
    }

    //从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
    bool deleteFront() 
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            l = l == limit - 1 ? 0 : (l + 1);
            size--;
            return true;
        }
    }

    //从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            r = r == 0 ? (limit - 1) : r - 1;
            size--;
            return true;
        }
    }

    //从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
    int getFront()
    {
        return isEmpty() ? -1 : dequeArr[l];
    }

    //获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
    int getRear()
    {
        return isEmpty() ? -1 : dequeArr[r];
    }

    //若双端队列为空，则返回 true ，否则返回 false  。
    bool isEmpty()
    {
        return size == 0;
    }

    //若双端队列满了，则返回 true ，否则返回 false 。
    bool isFull()
    {
        return size == limit;
    }
};

