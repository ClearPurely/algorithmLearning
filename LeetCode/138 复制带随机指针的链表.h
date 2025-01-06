#pragma once
#include "../Solution.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution138 : public Solution {
public:
	//利用一对一对遍历实现
	
    Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return nullptr;
		}
		Node* cur = head;
		Node* next = nullptr;
		// 1 -> 2 -> 3 -> null
		// 1 -> 1' -> 2 -> 2' -> 3 -> 3'
		while (cur != nullptr) {
			next = cur->next;
			cur->next = new Node(cur->val);
			cur->next->next = next;
			cur = next;
		}
		cur = head;
		Node* copy = nullptr;
		// 1 1' 2 2' 3 3'
		// 依次设置 1' 2' 3' random指针
		while (cur != nullptr) {
			next = cur->next->next;
			copy = cur->next;
			copy->random = cur->random != nullptr ? cur->random->next : nullptr;
			cur = next;
		}
		Node* res = head->next;
		cur = head;
		// 老 新 混在一起，next方向上，random正确
		// next方向上，把新老链表分离
		while (cur != nullptr) {
			next = cur->next->next;
			copy = cur->next;
			cur->next = next;
			copy->next = next != nullptr ? next->next : nullptr;
			cur = next;
		}
		return res;
    }

	//利用map实现
	Node* copyRandomList1(Node* head) {
		// key 老节点
		// value 新节点
		unordered_map<Node*, Node*> map;
		Node* cur = head;
		while (cur != nullptr) {
			map.insert(unordered_map<Node*, Node*>::value_type(cur, new Node(cur->val)));
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr) {
			// cur 老
			// map.get(cur) 新
			// 新.next ->  cur.next克隆节点找到
			//map.get(cur).next = map.get(cur.next);
			//map.get(cur).random = map.get(cur.random);
			//(*(map.find(cur))).second->next = (*(map.find(cur->next))).second;
			//(*(map.find(cur))).second->random = (*(map.find(cur->random))).second;
			map[cur]->next = map[cur->next];
			map[cur]->random = map[cur->random];
			cur = cur->next;
		}
		return map[head];
	}


	void testDemo() override {
		cout << "题目描述" << endl;
		cout << "给你一个长度为 n 的链表，每个节点包含一个额外增加的随机" << endl;
		cout << "指针 random ，该指针可以指向链表中的任何节点或空节点。" << endl;

	}
};



