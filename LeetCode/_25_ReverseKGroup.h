/***题目介绍***
// 每k个节点一组翻转链表
// 测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
*/
#pragma once
#include "../Solution.h"

class _25_ReverseKGroup : public Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* start = head;
		ListNode* end = teamEnd(start, k);
		if (end == NULL) {
			return head;
		}
		// 第一组很特殊因为牵扯到换头的问题
		head = end;
		reverse(start, end);
		// 翻转之后start变成了上一组的结尾节点
		ListNode* lastTeamEnd = start;
		while (lastTeamEnd->next != NULL) {
			start = lastTeamEnd->next;
			end = teamEnd(start, k);
			if (end == NULL) {
				return head;
			}
			reverse(start, end);
			lastTeamEnd->next = end;
			lastTeamEnd = start;
		}
		return head;
	}

	// 当前组的开始节点是s，往下数k个找到当前组的结束节点返回
	ListNode* teamEnd(ListNode* s, int k) {
		while (--k != 0 && s != NULL) {
			s = s->next;
		}
		return s;
	}

	// s -> a -> b -> c -> e -> 下一组的开始节点
	// 上面的链表通过如下的reverse方法调整成 : e -> c -> b -> a -> s -> 下一组的开始节点
	void reverse(ListNode* s, ListNode* e) {
		e = e->next;
		ListNode *pre = NULL, *cur = s, *next = NULL;
		while (cur != e) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		s->next = e;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};