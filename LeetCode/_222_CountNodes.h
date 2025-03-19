/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 222 求完全二叉树的节点个数
/// 测试链接 : https://leetcode.cn/problems/count-complete-tree-nodes/
/// </summary>
class _222_CountNodes : public Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return countNodesF(root, 1, mostLeft(root, 1));
	}

	// cur : 当前来到的节点
	// level :  当前来到的节点在第几层
	// h : 整棵树的高度，不是cur这棵子树的高度
	// 求 : cur这棵子树上有多少节点（辅助函数）
	int countNodesF(TreeNode* cur, int level, int h) {
		if (level == h) {
			return 1;
		}
		if (mostLeft(cur->right, level + 1) == h) {
			// cur右树上的最左节点，扎到了最深层
			return (1 << (h - level)) + countNodesF(cur->right, level + 1, h);
		}
		else {
			// cur右树上的最左节点，没扎到最深层
			return (1 << (h - level - 1)) + countNodesF(cur->left, level + 1, h);
		}
	}

	// 当前节点是cur，并且它在level层
	// 返回从cur开始不停往左，能扎到几层（辅助函数）
	int mostLeft(TreeNode* cur, int level) {
		while (cur != nullptr) {
			level++;
			cur = cur->left;
		}
		return level - 1;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};