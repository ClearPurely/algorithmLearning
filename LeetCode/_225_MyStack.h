#pragma once
#include "../Solution.h"
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����

//�ö���ʵ��ջ
class _225_MyStack : public Solution
{
private:
    queue<int>* queue1;

public:
    _225_MyStack();

    ~_225_MyStack();

    //��Ԫ�� x ѹ��ջ����
    void push(int x);

    //�Ƴ�������ջ��Ԫ�ء�
    int pop();

    //����ջ��Ԫ�ء�
    int top();

    //���ջ�ǿյģ����� true �����򣬷��� false ��
    bool empty();

};

