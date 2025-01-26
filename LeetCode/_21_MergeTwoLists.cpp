#include "_21_MergeTwoLists.h"

ListNode* _21_MergeTwoLists::mergeTwoLists1(ListNode* list1, ListNode* list2)
{
	if (list1 == nullptr || list2 == nullptr) {
		return list1 == nullptr ? list2 : list1;
	}
	ListNode* head = list1->val > list2->val ? list2 : list1;
	ListNode* cur1 = head->next;
	ListNode* cur2 = cur1 == list1 ? list2 : list1;
	ListNode* pre = head;
	while (cur1 != nullptr && cur2 != nullptr)
	{
		if (cur1->val < cur2->val)
		{
			pre->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			pre->next = cur2;
			cur2 = cur2->next;
		}
		pre = pre->next;
	}
	pre->next = cur1 == nullptr ? cur2 : cur1;
	return head;
}

ListNode* _21_MergeTwoLists::mergeTwoLists(ListNode* list1, ListNode* list2)
{
	if (list1 == nullptr || list2 == nullptr) {
		return list1 == nullptr ? list2 : list1;
	}

	if (list1->val < list2->val)
	{
		list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
	else
	{
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
}
