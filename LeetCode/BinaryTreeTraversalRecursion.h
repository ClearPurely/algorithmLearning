#pragma once
#include "../Solution.h"
//二叉树的三种遍历算法

//二叉树遍历
class BinaryTreeTraversalRecursion : public Solution
{
private:
    vector<int> ans = vector<int>();
public:
    BinaryTreeTraversalRecursion();

    void ClearAns();

    //二叉树的前序遍历(递归)
    vector<int> preorderTraversal1(TreeNode* root);

    //二叉树的前序遍历(一个栈实现)LeetCode 144题
    vector<int> preorderTraversal(TreeNode* root);

    //二叉树的中序遍历(递归)
    vector<int> inorderTraversal1(TreeNode* root);

    //二叉树的中序遍历(一个栈实现)LeetCode 94题
    vector<int> inorderTraversal(TreeNode* root);

    //二叉树的后序遍历(递归)
    vector<int> postorderTraversal1(TreeNode* root);

    //二叉树的后序遍历(一个栈实现)LeetCode 145题
    vector<int> postorderTraversal(TreeNode* root);

    //二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode* root);
};

