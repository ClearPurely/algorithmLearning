#pragma once
#include "../Solution.h"
//���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

//��Сջ
class _155_MinStack : public Solution
{
private:
    stack<int>* data;
    stack<int>* minStack;

public:
    _155_MinStack();
    ~_155_MinStack();

    //��Ԫ��val�����ջ��
    void push(int val);

    //ɾ����ջ������Ԫ�ء�
    void pop();

    // ��ȡ��ջ������Ԫ�ء�
    int top();

    //��ȡ��ջ�е���СԪ�ء�
    int getMin();

};

