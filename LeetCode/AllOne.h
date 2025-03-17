/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 432 全O(1)的数据结构
/// 测试链接 : https://leetcode.cn/problems/all-oone-data-structure/
/// 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
/// 实现 AllOne 类：
/// AllOne() 初始化数据结构的对象。
/// inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
/// dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
/// getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
/// getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
/// 注意：每个函数都应当满足 O(1) 平均时间复杂度。
/// </summary>
class AllOne : public Solution {
private:
    struct Bucket {
        unordered_set<string> set;
        int cnt;
        Bucket* last;
        Bucket* next;

        Bucket(const string& s, int c) : cnt(c), last(nullptr), next(nullptr) {
            set.insert(s);
        }

        Bucket(int c) : cnt(c), last(nullptr), next(nullptr) {}  // 用于头尾节点构造
    };


    // 将pos插入到cur节点之后
    void insert(Bucket* cur, Bucket* pos) {
        pos->last = cur;
        pos->next = cur->next;
        cur->next->last = pos;
        cur->next = pos;
    }

    // 从链表中移除并销毁节点
    void remove(Bucket* cur) {
        cur->last->next = cur->next;
        cur->next->last = cur->last;
        delete cur;
    }

    Bucket* head;
    Bucket* tail;
    unordered_map<string, Bucket*> map;
public:
    AllOne() {
        head = new Bucket(0);        // 虚拟头节点
        tail = new Bucket(INT_MAX);  // 虚拟尾节点
        head->next = tail;
        tail->last = head;
    }

    ~AllOne() {
        Bucket* p = head;
        while (p) {                 // 析构时清理所有节点
            Bucket* tmp = p->next;
            delete p;
            p = tmp;
        }
    }

    void inc(string key) {
        if (!map.count(key)) {      // key不存在的情况
            if (head->next->cnt == 1) { // 有现成的计数1桶
                head->next->set.insert(key);
                map[key] = head->next;
            }
            else {                    // 需要新建计数1桶
                Bucket* newBucket = new Bucket(key, 1);
                map[key] = newBucket;
                insert(head, newBucket);
            }
        }
        else {                    // key已存在的情况
            Bucket* bucket = map[key];
            if (bucket->next->cnt == bucket->cnt + 1) { // 有下一级桶
                bucket->next->set.insert(key);
                map[key] = bucket->next;
            }
            else {                    // 需要新建中间桶
                Bucket* newBucket = new Bucket(key, bucket->cnt + 1);
                map[key] = newBucket;
                insert(bucket, newBucket);
            }
            bucket->set.erase(key);      // 清理旧桶
            if (bucket->set.empty()) {
                remove(bucket);
            }
        }
    }

    void dec(string key) {
        Bucket* bucket = map[key];
        if (bucket->cnt == 1) {      // 计数降为0的情况
            map.erase(key);
        }
        else {
            if (bucket->last->cnt == bucket->cnt - 1) { // 有前一级桶
                bucket->last->set.insert(key);
                map[key] = bucket->last;
            }
            else {                    // 需要新建中间桶
                Bucket* newBucket = new Bucket(key, bucket->cnt - 1);
                map[key] = newBucket;
                insert(bucket->last, newBucket);
            }
        }
        bucket->set.erase(key);      // 清理旧桶
        if (bucket->set.empty()) {
            remove(bucket);
        }
    }

    string getMaxKey() {
        return (tail->last != head) ? *tail->last->set.begin() : "";
    }

    string getMinKey() {
        return (head->next != tail) ? *head->next->set.begin() : "";
    }

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};