#pragma once
#include "../Solution.h"

/// <summary>
/// 146 实现LRU结构
/// 测试链接 : https://leetcode.cn/problems/lru-cache/
/// </summary>
class LRUCache : public Solution {
private:
    struct DoubleNode {
        int key;
        int val;
        DoubleNode* last;
        DoubleNode* next;
        DoubleNode(int k, int v) : key(k), val(v), last(nullptr), next(nullptr) {}
    };

    class DoubleList {
    private:
        DoubleNode* head;
        DoubleNode* tail;

    public:
        DoubleList() : head(nullptr), tail(nullptr) {}

        void addNode(DoubleNode* newNode) {
            if (!newNode) return;
            if (!head) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->last = tail;
                tail = newNode;
            }
        }

        void moveNodeToTail(DoubleNode* node) {
            if (node == tail) return;
            if (node == head) {
                head = head->next;
                head->last = nullptr;
            }
            else {
                node->last->next = node->next;
                node->next->last = node->last;
            }
            tail->next = node;
            node->last = tail;
            node->next = nullptr;
            tail = node;
        }

        DoubleNode* removeHead() {
            if (!head) return nullptr;
            DoubleNode* removed = head;
            if (head == tail) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
                head->last = nullptr;
                removed->next = nullptr;
            }
            return removed;
        }
    };

    int capacity;
    unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleList nodeList;
public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            DoubleNode* target = keyNodeMap[key];
            nodeList.moveNodeToTail(target);
            return target->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            DoubleNode* target = keyNodeMap[key];
            target->val = value;
            nodeList.moveNodeToTail(target);
        }
        else {
            if (keyNodeMap.size() == capacity) {
                DoubleNode* removedNode = nodeList.removeHead();
                keyNodeMap.erase(removedNode->key);
                delete removedNode;
            }
            DoubleNode* newNode = new DoubleNode(key, value);
            keyNodeMap[key] = newNode;
            nodeList.addNode(newNode);
        }
    }
};