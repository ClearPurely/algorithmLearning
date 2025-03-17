/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 297
/// 二叉树先序序列化和反序列化
/// 二叉树按层序列化和反序列化
/// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
/// </summary>
class _297_SerializeBinaryTree : public Solution {
private:
    //按前序遍历序列化(递归辅助函数)
    void f(TreeNode* root, ostringstream& oss) {
        if (root == nullptr) {
            oss << "#,";
        }
        else {
            oss << root->val << ",";
            f(root->left, oss);
            f(root->right, oss);
        }
    }

    //按前序遍历反序列化(递归辅助函数)
    TreeNode* g(const vector<string>& vals, int& cnt) {
        string cur = vals[cnt++];
        if (cur == "#") {
            return nullptr;
        }
        else {
            TreeNode* node = new TreeNode(stoi(cur));
            node->left = g(vals, cnt);
            node->right = g(vals, cnt);
            return node;
        }
    }

    //分割字符串
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    //序列化二叉树
    string serialize(TreeNode* root) {
        ostringstream oss;
        f(root, oss);
        return oss.str();
    }

    //反序列化二叉树
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int cnt = 0;
        return g(vals, cnt);
    }



    TreeNode* queue[10001];
    int l, r;

    TreeNode* generate(const string& val) {
        return val == "#" ? nullptr : new TreeNode(stoi(val));
    }

    string serialize1(TreeNode* root) {
        ostringstream oss;
        if (root != nullptr) {
            oss << root->val << ",";
            l = 0;
            r = 0;
            queue[r++] = root;
            while (l < r) {
                root = queue[l++];
                if (root->left != nullptr) {
                    oss << root->left->val << ",";
                    queue[r++] = root->left;
                }
                else {
                    oss << "#,";
                }
                if (root->right != nullptr) {
                    oss << root->right->val << ",";
                    queue[r++] = root->right;
                }
                else {
                    oss << "#,";
                }
            }
        }
        return oss.str();
    }

    TreeNode* deserialize1(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<string> nodes = split(data, ',');
        int index = 0;
        TreeNode* root = generate(nodes[index++]);
        l = 0;
        r = 0;
        queue[r++] = root;
        while (l < r) {
            TreeNode* cur = queue[l++];
            cur->left = generate(nodes[index++]);
            cur->right = generate(nodes[index++]);
            if (cur->left != nullptr) {
                queue[r++] = cur->left;
            }
            if (cur->right != nullptr) {
                queue[r++] = cur->right;
            }
        }
        return root;
    }

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};