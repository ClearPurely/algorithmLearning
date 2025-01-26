#pragma once
#include "../Solution.h"
//���ѭ��˫�˶���

class _641_MyCircularDeque : public Solution
{
private:
    vector<int> dequeArr;
    int l, r, size, limit;
public:
    //���캯��,˫�˶������Ϊk��
    _641_MyCircularDeque(int k)
    {
        dequeArr = vector<int>(k);
        l = r = size = 0;
        limit = k;
    }

    //��һ��Ԫ����ӵ�˫�˶���ͷ���� ��������ɹ����� true �����򷵻� false ��
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

    //��һ��Ԫ����ӵ�˫�˶���β������������ɹ����� true �����򷵻� false ��
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

    //��˫�˶���ͷ��ɾ��һ��Ԫ�ء� ��������ɹ����� true �����򷵻� false ��
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

    //��˫�˶���β��ɾ��һ��Ԫ�ء���������ɹ����� true �����򷵻� false ��
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

    //��˫�˶���ͷ�����һ��Ԫ�ء����˫�˶���Ϊ�գ����� -1 ��
    int getFront()
    {
        return isEmpty() ? -1 : dequeArr[l];
    }

    //���˫�˶��е����һ��Ԫ�ء� ���˫�˶���Ϊ�գ����� -1 ��
    int getRear()
    {
        return isEmpty() ? -1 : dequeArr[r];
    }

    //��˫�˶���Ϊ�գ��򷵻� true �����򷵻� false  ��
    bool isEmpty()
    {
        return size == 0;
    }

    //��˫�˶������ˣ��򷵻� true �����򷵻� false ��
    bool isFull()
    {
        return size == limit;
    }
};

