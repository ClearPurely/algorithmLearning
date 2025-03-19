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

    // 958 验证完全二叉树
    // 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/
    bool isCompleteTree(TreeNode* root);

    // 236 普通二叉树上寻找两个节点的最近公共祖先
    // 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

    // 235 搜索二叉树上寻找两个节点的最近公共祖先
    // 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q);

    // 110 验证平衡二叉树
    // 测试链接 : https://leetcode.cn/problems/balanced-binary-tree/
    bool balance;
    bool isBalanced(TreeNode* root) {
        // balance是全局变量，所有调用过程共享
        // 所以每次判断开始时，设置为true
        balance = true;
        height(root);
        return balance;
    }
    // 一旦发现不平衡，返回什么高度已经不重要了
    int height(TreeNode* cur) {
        if (!balance || cur == nullptr) {
            return 0;
        }
        int lh = height(cur->left);
        int rh = height(cur->right);
        if (std::abs(lh - rh) > 1) {
            balance = false;
        }
        return std::max(lh, rh) + 1;
    }

    // 98 验证搜索二叉树
    // 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/
    // 思路：可以用中序遍历做，但是用递归+全局变量的形式更快
    long long min;
    long long max;
    bool isValidBST(TreeNode* head) {
        if (head == nullptr) {
            // 使用 long long 类型的边界值
            min = LLONG_MAX;
            max = LLONG_MIN;
            return true;
        }
        bool lok = isValidBST(head->left);
        long long lmin = min;
        long long lmax = max;
        bool rok = isValidBST(head->right);
        long long rmin = min;
        long long rmax = max;
        min = std::min({ lmin, rmin, static_cast<long long>(head->val) });
        max = std::max({ lmax, rmax, static_cast<long long>(head->val) });
        return lok && rok && (lmax < head->val) && (rmin > head->val);
    }

    // 669 修剪搜索二叉树
    // 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/
    TreeNode* trimBST(TreeNode* cur, int low, int high) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (cur->val < low) {
            return trimBST(cur->right, low, high);
        }
        if (cur->val > high) {
            return trimBST(cur->left, low, high);
        }
        // cur在范围中
        cur->left = trimBST(cur->left, low, high);
        cur->right = trimBST(cur->right, low, high);
        return cur;
    }

};