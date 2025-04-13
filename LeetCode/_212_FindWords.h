/***题目介绍***
// 在二维字符数组中搜索可能的单词
// 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words
// 返回所有二维网格上的单词。单词必须按照字母顺序，通过 相邻的单元格 内的字母构成
// 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
// 同一个单元格内的字母在一个单词中不允许被重复使用
// 1 <= m, n <= 12
// 1 <= words.length <= 3 * 10^4
// 1 <= words[i].length <= 10
*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 212 单词搜索 II
/// </summary>
class _212_FindWords : public Solution {
private:
	//生成数组前缀树的代码
	static const int MAX_CAPACITY = 10001;
	int tree[MAX_CAPACITY][26];
	int passTree[MAX_CAPACITY];
	string endTree[MAX_CAPACITY];		//存储以这个节点收尾的字符串
	int cnt;

	void buildTrie(vector<string>& words)
	{
		clear();
		cnt = 1;
		for (string word : words)
		{
			int cur = 1;
			passTree[cur]++;
			for (char c : word)
			{
				int path = c - 'a';
				if (tree[cur][path] == 0)
					tree[cur][path] = ++cnt;
				cur = tree[cur][path];
				passTree[cur]++;
			}
			endTree[cur] = word;
		}
	}

	void clear() {
		memset(tree, 0, sizeof(tree));
		memset(passTree, 0, sizeof(passTree));
		for (int i = 0; i < MAX_CAPACITY; ++i) {
			endTree[i].clear();
		}
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		buildTrie(words);
		vector<string> ans;
		for (int i = 0; i < (int)board.size(); i++)
		{
			for (int j = 0; j < (int)board[0].size(); j++)
				dfs(board, i, j, 1, ans);
		}
		return ans;
	}

	int dfs(vector<vector<char>>& board, int i, int j, int t, vector<string>& ans) {
		if (i < 0 || i == (int)board.size() || j < 0 || j == (int)board[0].size() || board[i][j] == 0)
			return 0;
		char tmp = board[i][j];
		int path = tmp - 'a';
		t = tree[t][path];		//找到对应下一节点
		if (passTree[t] == 0)		//如果没有字符串有字符经过该点说明这个字符串不在给定的字符串里面
			return 0;

		int fix = 0;
		if (!endTree[t].empty())
		{
			fix++;
			ans.push_back(endTree[t]);
			endTree[t].clear();		//这个字符串出现过，直接清除
		}

		board[i][j] = 0;
		fix += dfs(board, i - 1, j, t, ans);
		fix += dfs(board, i + 1, j, t, ans);
		fix += dfs(board, i, j - 1, t, ans);
		fix += dfs(board, i, j + 1, t, ans);
		passTree[t] -= fix;		//更新 Trie 树中节点的经过次数，避免重复搜索
		board[i][j] = tmp;

		return fix;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};