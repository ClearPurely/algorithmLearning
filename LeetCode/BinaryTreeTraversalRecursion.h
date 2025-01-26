#pragma once
#include "../Solution.h"
//�����������ֱ����㷨

//����������
class BinaryTreeTraversalRecursion : public Solution
{
private:
    vector<int> ans = vector<int>();
public:
    BinaryTreeTraversalRecursion();

    void ClearAns();

    //��������ǰ�����(�ݹ�)
    vector<int> preorderTraversal1(TreeNode* root);

    //��������ǰ�����(һ��ջʵ��)LeetCode 144��
    vector<int> preorderTraversal(TreeNode* root);

    //���������������(�ݹ�)
    vector<int> inorderTraversal1(TreeNode* root);

    //���������������(һ��ջʵ��)LeetCode 94��
    vector<int> inorderTraversal(TreeNode* root);

    //�������ĺ������(�ݹ�)
    vector<int> postorderTraversal1(TreeNode* root);

    //�������ĺ������(һ��ջʵ��)LeetCode 145��
    vector<int> postorderTraversal(TreeNode* root);

    //�������Ĳ������
    vector<vector<int>> levelOrder(TreeNode* root);
};

