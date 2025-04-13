#pragma once
#include<string>
#include<vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/// <summary>
/// 前缀树代码
/// 用map实现，支持所有字符
/// 需要自己管理内存释放等问题，稍显复杂
/// 测试链接 : https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
/// 测试链接 : https://leetcode.cn/problems/implement-trie-ii-prefix-tree/
/// </summary>
class TrieTree
{
private:
	class TrieNode {
	public:
		int pass;
		int end;
		unordered_map<int, TrieNode*> nexts;

		//构造函数
		TrieNode() {
			pass = 0;
			end = 0;
		}
	};

	TrieNode *root;

	// 析构函数辅助方法
	void destroy(TrieNode* node);

public:
	TrieTree();

	~TrieTree();

	//插入一个单词
	void insert(const string& word);

	//删除一个单词
	void erase(const string& word);

	//查询该单词出现了多少次
	int countWordsEqualTo(const string& word);

	//查询多少个单词以pre开头
	int countWordsStartingWith(const string& pre);
};