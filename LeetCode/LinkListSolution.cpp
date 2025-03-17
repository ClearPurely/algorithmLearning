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
	// ��� : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> ...
	while (cur != NULL) {
		next = cur->next;
		cur->next = new Node(cur->val);
		cur->next->next = next;
		cur = next;
	}
	cur = head;
	Node* copy = NULL;
	// �����������Ͻڵ�Ľṹ��ϵ������ÿһ���½ڵ��randomָ��
	while (cur != NULL) {
		next = cur->next->next;
		copy = cur->next;
		copy->random = cur->random != NULL ? cur->random->next : NULL;
		cur = next;
	}
	Node* ans = head->next;
	cur = head;
	// ����������� : ��������������һ����������������һ��
	while (cur != NULL) {
		next = cur->next->next;
		copy = cur->next;
		cur->next = next;
		copy->next = next != NULL ? next->next : NULL;
		cur = next;
	}
	// �����������ͷ�ڵ�
	return ans;
}

bool LinkListSolution::isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	ListNode* slow = head, * fast = head;
	// ���е�
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// �����е����slow�����е㿪ʼ����Ľڵ�����
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
	// ����Ĺ����Ѿ�����������ɴ������������м�ָ
	// head -> ... -> slow <- ... <- pre
	bool ans = true;
	ListNode* left = head;
	ListNode* right = pre;
	// left���ҡ�right����ÿһ���ȶ�ֵ�Ƿ�һ�������ĳһ����һ���𰸾���false
	while (left != NULL && right != NULL) {
		if (left->val != right->val) {
			ans = false;
			break;
		}
		left = left->next;
		right = right->next;
	}
	// ���Ų��ӵ�ԭ�򣬰����������ԭ���������ٷ����жϽ��
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