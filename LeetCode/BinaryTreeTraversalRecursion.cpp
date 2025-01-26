#include "BinaryTreeTraversalRecursion.h"

BinaryTreeTraversalRecursion::BinaryTreeTraversalRecursion()
{
}

void BinaryTreeTraversalRecursion::ClearAns()
{
	ans.clear();
}

vector<int> BinaryTreeTraversalRecursion::preorderTraversal1(TreeNode* root)
{
	if (!root) {
		return ans;
	}
	ans.push_back(root->val);
	preorderTraversal1(root->left);
	preorderTraversal1(root->right);
	return ans;
}

vector<int> BinaryTreeTraversalRecursion::preorderTraversal(TreeNode* root)
{
	vector<int> ret = vector<int>();
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		st.pop();
		ret.push_back(cur->val);
		if (cur->right != NULL)
		{
			st.push(cur->right);
		}
		if (cur->left != NULL)
		{
			st.push(cur->left);
		}
	}
	return ret;
}

vector<int> BinaryTreeTraversalRecursion::inorderTraversal1(TreeNode* root)
{
	if (!root) {
		return ans;
	}
	inorderTraversal1(root->left);
	ans.push_back(root->val);
	inorderTraversal1(root->right);
	return ans;
}

vector<int> BinaryTreeTraversalRecursion::inorderTraversal(TreeNode* root)
{
	vector<int> ret = vector<int>();
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	while (!st.empty() || root != NULL)
	{
		if (root != NULL)
		{
			st.push(root);
			root = root->left;
		}
		else
		{
			root = st.top();
			st.pop();
			ret.push_back(root->val);
			root = root->right;
		}
	}
	return ret;
}

vector<int> BinaryTreeTraversalRecursion::postorderTraversal1(TreeNode* root)
{
	if (!root) {
		return ans;
	}
	postorderTraversal1(root->left);
	postorderTraversal1(root->right);
	ans.push_back(root->val);
	return ans;
}

vector<int> BinaryTreeTraversalRecursion::postorderTraversal(TreeNode* root)
{
	vector<int> ret = vector<int>();
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		if (cur->left != NULL && root != cur->left && root!= cur->right)
		{
			st.push(cur->left);
		}
		else if (cur->right != NULL && root != cur->right)
		{
			st.push(cur->right);
		}
		else
		{
			ret.push_back(cur->val);
			root = st.top();
			st.pop();
		}
	}
	return ret;
}