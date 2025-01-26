#pragma once
#include "../Solution.h"
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty��


//��ջʵ�ֶ���
class _232_MyQueue : public Solution
{

private:
    stack<int>* in;
    stack<int>* out;

public:
    _232_MyQueue();
    ~_232_MyQueue();

    //�ؼ�˼·��
    // ������
    // ��inջ�������ݵ���outջ
    // 1) out���ˣ����ܵ�����(��in������ȡ��out)
    // 2) ��������ݣ�in���뵹��
    void inToOut();

    //��Ԫ�� x �Ƶ����е�ĩβ
    void push(int x);
    //�Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
    int pop();

    //���ض��п�ͷ��Ԫ��
    int peek();

    //�������Ϊ�գ����� true �����򣬷��� false
    bool empty();
};

