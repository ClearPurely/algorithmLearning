/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 105 利用先序与中序遍历序列构造二叉树
/// 测试链接 : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/// </summary>
class _105_BuildTree : public Solution {
public:
	TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
		if (pre.empty() || in.empty() || (int)pre.size() != (int)in.size()) {
			return nullptr;
		}
		unordered_map<int, int> map = unordered_map<int, int>();
		for (int i = 0; i < (int)in.size(); i++)
			map[in[i]] = i;
		return buildTreeF(pre, 0, (int)pre.size() - 1, in, 0, (int)in.size() - 1, map);
	}

	TreeNode* buildTreeF(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2, unordered_map<int, int>& map) {
		if (l1 > r1) {
			return nullptr;
		}
		TreeNode* head = new TreeNode(pre[l1]);
		if (l1 == r1) {
			return head;
		}
		int k = map[pre[l1]];
		// pre : l1(........)[.......r1]
		// in  : (l2......)k[........r2]
		// (...)是左树对应，[...]是右树的对应
		head->left = buildTreeF(pre, l1 + 1, l1 + k - l2, in, l2, k - 1, map);
		head->right = buildTreeF(pre, l1 + k - l2 + 1, r1, in, k + 1, r2, map);
		return head;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};