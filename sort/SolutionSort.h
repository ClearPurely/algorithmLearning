/*************
作者：ClearPurely
项目名：排序方法
描述：实现一些常用的排序方法
创建日期：2025.1.20
最后更新日期：2025.2.7
****************/
#pragma once
#include "../Solution.h"
#include"../readProcessFun.h"

using namespace std;

/***题目介绍***
对数组进行排序
测试链接：
https://leetcode.cn/problems/sort-an-array/
https://www.luogu.com.cn/problem/P1177
*/


class SolutionSort : public Solution {
private:
	vector<int>* helpArr;
	//归并排序
	void mergeSort(vector<int>& arr, int l, int r);
	//归并排序的辅助函数
	void merge(vector<int>& arr, int l, int m, int r);
	//归并排序非递归版，用步长模拟实现
	void mergeSort1(vector<int>& arr);

	int first, last;
	vector<int> sourceArr;
	//快速排序
	void useQuickSort(vector<int>& arr);
	//快速排序辅助函数
	void quickSort(int l, int r);
	// 荷兰国旗问题，划分范围
	// 已知arr[l....r]范围上一定有x这个值
	// 划分数组 <x放左边，==x放中间，>x放右边
	// 把全局变量first, last，更新成==x区域的左右边界
	void partition(int l, int r, int x);
	
public:
	SolutionSort()
	{

	}

	~SolutionSort()
	{
		delete helpArr;
		helpArr = NULL;
	}

	//传入一个数组，测试归并排序
	void useMergeSort(vector<int>& arr);

	//供外部调用的测试函数
	void testDemo() override;
};



