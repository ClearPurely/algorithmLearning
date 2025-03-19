/***题目介绍***
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
给定二叉树的 root 。返回 在不触动警报的情况下，小偷能够盗取的最高金额。
*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 337 二叉树打家劫舍问题
/// 测试链接 : https://leetcode.cn/problems/house-robber-iii/
/// </summary>
class _337_Rob : public Solution {
public:
	int rob(TreeNode* root) {
		f(root);
		return std::max(yes, no);
	}

	// 全局变量，完成了X子树的遍历，返回之后
	// yes变成，X子树在偷头节点的情况下，最大的收益
	int yes;
	// 全局变量，完成了X子树的遍历，返回之后
	// no变成，X子树在不偷头节点的情况下，最大的收益
	int no;

	void f(TreeNode* root) {
		if (root == nullptr) {
			yes = 0;
			no = 0;
		}
		else {
			int y = root->val;
			int n = 0;	//记录选择打劫当前两个子树的最大收益
			f(root->left);
			y += no;
			n += std::max(yes, no);
			f(root->right);
			y += no;
			n += std::max(yes, no);
			yes = y;
			no = n;
		}
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};