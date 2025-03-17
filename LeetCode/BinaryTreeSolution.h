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

    //102 二叉树的层序遍历（宽度优先遍历）
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

    // 105 利用先序与中序遍历序列构造二叉树
    // 测试链接 : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    TreeNode* buildTree(vector<int>& pre, vector<int>& in);
    //递归构造二叉树（辅助函数）
    TreeNode* buildTreeF(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2, unordered_map<int, int>& map);

    // 958 验证完全二叉树
    // 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/
    bool isCompleteTree(TreeNode* root);

    // 222 求完全二叉树的节点个数
    // 测试链接 : https://leetcode.cn/problems/count-complete-tree-nodes/
    int countNodes(TreeNode* root);
    // cur : 当前来到的节点
    // level :  当前来到的节点在第几层
    // h : 整棵树的高度，不是cur这棵子树的高度
    // 求 : cur这棵子树上有多少节点（辅助函数）
    int countNodesF(TreeNode* cur, int level, int h);
    // 当前节点是cur，并且它在level层
    // 返回从cur开始不停往左，能扎到几层（辅助函数）
    int mostLeft(TreeNode* cur, int level);
};