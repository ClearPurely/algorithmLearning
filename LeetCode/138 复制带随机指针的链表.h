#pragma once
#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>

using namespace std;


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


class Solution {
public:
	//����һ��һ�Ա���ʵ��
	
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
		// �������� 1' 2' 3' randomָ��
		while (cur != nullptr) {
			next = cur->next->next;
			copy = cur->next;
			copy->random = cur->random != nullptr ? cur->random->next : nullptr;
			cur = next;
		}
		Node* res = head->next;
		cur = head;
		// �� �� ����һ��next�����ϣ�random��ȷ
		// next�����ϣ��������������
		while (cur != nullptr) {
			next = cur->next->next;
			copy = cur->next;
			cur->next = next;
			copy->next = next != nullptr ? next->next : nullptr;
			cur = next;
		}
		return res;
    }

	//����mapʵ��
	Node* copyRandomList1(Node* head) {
		// key �Ͻڵ�
		// value �½ڵ�
		unordered_map<Node*, Node*> map;
		Node* cur = head;
		while (cur != nullptr) {
			map.insert(unordered_map<Node*, Node*>::value_type(cur, new Node(cur->val)));
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr) {
			// cur ��
			// map.get(cur) ��
			// ��.next ->  cur.next��¡�ڵ��ҵ�
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


	void testDemo()
	{
		cout << "��Ŀ����" << endl;
		cout << "����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����" << endl;
		cout << "ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣" << endl;

	}
};



