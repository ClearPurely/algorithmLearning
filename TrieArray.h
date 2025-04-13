#pragma once
#include<string>
#include<vector>
#include <iostream>

using namespace std;

/// <summary>
/// 前缀树，用数组实现
/// 测试链接 : https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
/// 测试链接 : https://leetcode.cn/problems/implement-trie-ii-prefix-tree/
/// </summary>
class TrieArray
{
private:
	//最多添加多少个字符串 如果将来增加了数据量，就改大这个值
	int MAXN = 150001;

	//行：每一行就是相当于一个节点，统计到这个长度上出现的所有种类字符
	//	  这个数组的行数是MAXN，这个数越大，说明构造这个前缀数的字符串越多，这个的长度的意义就在于 不同前缀串后面跟一个不同字符 的可能性越多，例如：abc+1 abd+1 abc+2
	// 例如 ：abc def mln 对应treeArr[1] = {b,e,l}  b后面跟的节点就是treeArr[1][0]的值
	//列：字符的种类	每行的列越多，说明这些字符串里面出现的字符种类越多
	//存储的值：当前字符连着的下个节点的索引      （对应endArr和passArr数组里面存放着下一个字符对应的信息）
	vector<vector<int>> treeArr;
	vector<int> passArr;
	vector<int> endArr;

	//当前添加到第几个节点了
	int cnt;
public:

	TrieArray();

	void insert(const string& word);

	int search(const string& word);

	int startsWith(const string& pre);

	void erase(const string& word);

	void clear();
};