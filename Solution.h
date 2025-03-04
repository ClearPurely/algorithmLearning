/*************
作者：ClearPurely
项目名：解决leetcode题目的基类
描述：包含一些基本常用的方法和结构体
创建日期：2025.1.20
最后更新日期：2025.2.7
****************/
#pragma once
#include<iostream>		//	输入输出打印
#include<vector>		//向量
#include<map>			//	图
#include <unordered_map>	//字典
#include <queue>		//队列
#include<math.h>	//	数学库
#include<stack>
#include <cstdlib>   // 包含 rand() 函数所需的头文件
#include <ctime>     // 用于种植随机种子的库
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>
#include <numeric> // for std::accumulate

using namespace std;

#include "Validator.h"
//using namespace Validator;

//链表节点
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//二叉树节点
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Solution {
public:
	virtual void testDemo() {
		cout << "测试开始" << endl;
	}
};