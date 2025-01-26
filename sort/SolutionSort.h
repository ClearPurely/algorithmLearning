#pragma once
#include "../Solution.h"
#include"../readProcessFun.h"

using namespace std;

/***题目介绍***
对数组进行排序
https://leetcode.cn/problems/sort-an-array/
*/


class SolutionSort : public Solution {
private:
	vector<int>* helpArr;
	
public:

	~SolutionSort()
	{
		delete helpArr;
		helpArr = NULL;
	}

	void mergeSort(vector<int>& arr, int l, int r) {
		if (l == r) {
			return;
		}
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
	void merge(vector<int>& arr, int l, int m, int r) {
		int i = l;
		int a = l;
		int b = m + 1;
		while (a <= m && b <= r) {
			helpArr->at(i++) = arr[a] <= arr[b] ? arr[a++] : arr[b++];
		}
		while (a <= m) {		//如果最后合并剩一个左边的数
			helpArr->at(i++) = arr[a++];
		}
		while (b <= r) {		//剩右边的数
			helpArr->at(i++) = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = helpArr->at(i);
		}
	}

	//归并排序非递归版，用步长模拟实现
	void mergeSort1(vector<int>& arr) {
		int n = arr.size();
		for (int l, r, m, step = 1; step < n; step <<= 1)
		{
			l = 0;
			while (l <= n)
			{
				m = l + step - 1;
				if (m + 1 > n)
					break;
				r = min(m + step, n - 1);
				merge(arr, l, m, r);
				l = r + 1;
			}
		}
	}

	void useMerge(vector<int>& arr)
	{
		helpArr = new vector<int>(arr.size(), 1);
		mergeSort(arr, 0, arr.size() - 1);
		vector<int> arr2 = copyArray(arr);
		printArray(*helpArr);
	}

	void testDemo() override {
		//MyArrayProcessFun func = useMerge(testArr);;
		//processInputArray(func);

		vector<int> testArr = randomArray(10, 100);
		vector<int> arr2 = copyArray(testArr);
		printArray(testArr);

		helpArr = new vector<int>(testArr.size(), 1);
		cout << "归并排序的结果：" << endl;
		
		mergeSort(testArr, 0, testArr.size() - 1);
		mergeSort1(arr2);
		printArray(testArr);
		printArray(arr2);
	}
};



