#pragma once
#include "LinkListSolution.h"

ListNode* LinkListSolution::getIntersectionNode(ListNode* h1, ListNode* h2) {
	if (h1 == NULL || h2 == NULL) {
		return NULL;
	}
	ListNode* a = h1, * b = h2;
	int diff = 0;
	while (a->next != NULL) {
		a = a->next;
		diff++;
	}
	while (b->next != NULL) {
		b = b->next;
		diff--;
	}
	if (a != b) {
		return NULL;
	}
	if (diff >= 0) {
		a = h1;
		b = h2;
	}
	else {
		a = h2;
		b = h1;
	}
	diff = abs(diff);
	while (diff-- != 0) {
		a = a->next;
	}
	while (a != b) {
		a = a->next;
		b = b->next;
	}
	return a;
}

Node* LinkListSolution::copyRandomList(Node* head) {
	if (head == NULL) {
		return NULL;
	}
	Node* cur = head;
	Node* next = NULL;
	// 1 -> 2 -> 3 -> ...
	// 变成 : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> ...
	while (cur != NULL) {
		next = cur->next;
		cur->next = new Node(cur->val);
		cur->next->next = next;
		cur = next;
	}
	cur = head;
	Node* copy = NULL;
	// 利用上面新老节点的结构关系，设置每一个新节点的random指针
	while (cur != NULL) {
		next = cur->next->next;
		copy = cur->next;
		copy->random = cur->random != NULL ? cur->random->next : NULL;
		cur = next;
	}
	Node* ans = head->next;
	cur = head;
	// 新老链表分离 : 老链表重新连在一起，新链表重新连在一起
	while (cur != NULL) {
		next = cur->next->next;
		copy = cur->next;
		cur->next = next;
		copy->next = next != NULL ? next->next : NULL;
		cur = next;
	}
	// 返回新链表的头节点
	return ans;
}

bool LinkListSolution::isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	ListNode* slow = head, * fast = head;
	// 找中点
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// 现在中点就是slow，从中点开始往后的节点逆序
	ListNode* pre = slow;
	ListNode* cur = pre->next;
	ListNode* next = NULL;
	pre->next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	// 上面的过程已经把链表调整成从左右两侧往中间指
	// head -> ... -> slow <- ... <- pre
	bool ans = true;
	ListNode* left = head;
	ListNode* right = pre;
	// left往右、right往左，每一步比对值是否一样，如果某一步不一样答案就是false
	while (left != NULL && right != NULL) {
		if (left->val != right->val) {
			ans = false;
			break;
		}
		left = left->next;
		right = right->next;
	}
	// 本着不坑的原则，把链表调整回原来的样子再返回判断结果
	cur = pre->next;
	pre->next = NULL;
	next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return ans;
}

ListNode* LinkListSolution::detectCycle(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return NULL;
	}
	ListNode* slow = head->next;
	ListNode* fast = head->next->next;
	while (slow != fast) {
		if (fast->next == NULL || fast->next->next == NULL) {
			return NULL;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}