#pragma once
#include "../Solution.h"

/// <summary>
/// 2. �������
/// ���������ǿյ�������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
/// ���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
/// ����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
/// �� ���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
/// �����[8, 9, 9, 9, 0, 0, 0, 1]
/// </summary>
class _2_AddTwoNumbers : public Solution
{
	//�˷�������̫����������
	ListNode* MyaddTwoNumbers(ListNode* l1, ListNode* l2);

	ListNode* MyaddTwoNumbers2(ListNode* l1, ListNode* l2);

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	void testDemo() override;
};

