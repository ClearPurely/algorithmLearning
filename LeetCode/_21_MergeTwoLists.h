#pragma once
#include "../Solution.h"

/// <summary>
/// 21. 合并两个有序链表
/// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
/// </summary>
class _21_MergeTwoLists : public Solution
{
	//左神的课听来的方法
	ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2);

	//解析最优解
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

