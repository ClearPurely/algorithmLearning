/*************
作者：ClearPurely
项目名：排序方法
描述：实现一些常用的排序方法
创建日期：2025.1.20
最后更新日期：2025.2.7

****************/
#pragma once
#include "../Solution.h"

/***题目介绍***
对数组进行排序
测试链接：
https://leetcode.cn/problems/sort-an-array/
https://www.luogu.com.cn/problem/P1177
*/

class SolutionSort : public Solution {
private:

	/// 归并排序的部分
	vector<int>* helpArr;
	//归并排序的辅助函数
	void merge(vector<int>& arr, int l, int m, int r);
	//归并排序
	void mergeSort(vector<int>& arr, int l, int r);
	//归并排序非递归版，用步长模拟实现
	void mergeSort1(vector<int>& arr);

	/// 快速排序的部分
	int first, last;
	vector<int> sourceArr;	//归并排序用来进行操作的数组
	// 荷兰国旗问题，划分范围
	// 已知arr[l....r]范围上一定有x这个值
	// 划分数组 <x放左边，==x放中间，>x放右边
	// 把全局变量first, last，更新成==x区域的左右边界
	void partition(int l, int r, int x);
	//快速排序辅助函数
	void quickSort(int l, int r);
	//快速排序
	void useQuickSort(vector<int>& arr);

	//堆排序（如果是降序排把比较强换成greater就行了）
	void heapSort(vector<int>& arr);

	// 用归并排序的思路解决 力扣 215. 数组中的第i个最大元素
	int randomizedSelect(vector<int>& arr, int i);


	int MAXN = 50001;
	int BASE = 10;	//数的进制,可以任意修改成任何进制
	vector<int> help;
	vector<int> cnts;
	//计算一个数的位数（辅助基数排序）
	int bits(int number);
	//调用基数排序
	vector<int> radixSortArray(vector<int>& arr);
	// 基数排序核心代码
	// arr内要保证没有负数
	// n是arr的长度
	// bits是arr中最大值在BASE进制下有几位
	void radixSort(vector<int>& arr, int n, int bits);

public:
	SolutionSort()
	{
		help = vector<int>(MAXN);
		cnts = vector<int>(BASE);
	}

	~SolutionSort()
	{
		delete helpArr;
		helpArr = NULL;
	}

	//传入一个数组，测试所有不同种类的排序
	void useSort(vector<int>& arr);

	//供外部调用的测试函数
	void testDemo() override;
};



