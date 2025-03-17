/***题目介绍***
链表相关的高频题
*/
#pragma once
#include "../Solution.h"

class LinkListSolution : public Solution {
public:
	// 160 返回两个无环链表相交的第一个节点
	// 测试链接 : https://leetcode.cn/problems/intersection-of-two-linked-lists/
	ListNode* getIntersectionNode(ListNode* h1, ListNode* h2);

	// 138 复制带随机指针的链表
	// 测试链接 : https://leetcode.cn/problems/copy-list-with-random-pointer/
	// 总结：用map更快，但是使用的内存空间更多
	Node* copyRandomList(Node* head);

	// 234 判断链表是否是回文结构
	// 测试链接 : https://leetcode.cn/problems/palindrome-linked-list/
	bool isPalindrome(ListNode* head);

	// 142 返回链表的第一个入环节点
	// 测试链接 : https://leetcode.cn/problems/linked-list-cycle-ii/
	ListNode* detectCycle(ListNode* head);


	void testDemo() override {
		cout << "" << endl;
	}
};