#pragma once
#include "../Solution.h"

/// <summary>
/// 2 两数相加
/// 给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
/// 请你将两个数相加，并以相同形式返回一个表示和的链表。
/// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
/// 例 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
/// 输出：[8, 9, 9, 9, 0, 0, 0, 1]
/// </summary>
class _2_AddTwoNumbers : public Solution
{
	//此方法对于太长的数不行
	ListNode* MyaddTwoNumbers(ListNode* l1, ListNode* l2);

	ListNode* MyaddTwoNumbers2(ListNode* l1, ListNode* l2);

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	void testDemo() override;
};

