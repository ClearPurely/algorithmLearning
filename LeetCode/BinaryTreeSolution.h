/***题目介绍***
* 二叉树相关的题目
//94 144 145二叉树的三种遍历算法
//
*/
#pragma once
#include "../Solution.h"


//二叉树遍历
class BinaryTreeSolution : public Solution
{
private:
    vector<int> ans = vector<int>();
public:
    BinaryTreeSolution();

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

    //102 二叉树的层序遍历
    //测试链接 : https://leetcode.cn/problems/binary-tree-level-order-traversal/
    vector<vector<int>> levelOrder(TreeNode* root);

    // 103 二叉树的锯齿形层序遍历
    // 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);

    // 二叉树的锯齿形层序遍历(使用数组的版本)
    vector<vector<int>> zigzagLevelOrder1(TreeNode* root);

    // 662 二叉树的最大特殊宽度
    // 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/
    int widthOfBinaryTree(TreeNode* root);

    // 104 二叉树的最大深度
    // 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
    int maxDepth(TreeNode* root);

    // 111 二叉树的最小深度
    // 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
    int minDepth(TreeNode* root);



};