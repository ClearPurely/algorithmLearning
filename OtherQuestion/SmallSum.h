
// 小和问题
// 测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
#pragma once
#include "../Solution.h"
#include"../readProcessFun.h"

#include<vector>		//向量
using namespace std;


static int MAXN = 100001;

class SmallSum : public Solution {
private:
	vector<int> arr;
	vector<int> help;
	int n;

public:
	SmallSum(): arr(MAXN), help(MAXN), n(0){

	}

	// 返回跨左右产生的小和累加和，左侧有序、右侧有序，让左右两侧整体有序
	// arr[l...m] arr[m+1...r]
	long merge(int l, int m, int r) {
		// 统计部分
		long ans = 0;
		for (int j = m + 1, i = l, sum = 0; j <= r; j++) {
			while (i <= m && arr[i] <= arr[j]) {
				sum += arr[i++];
			}
			ans += sum;
		}
		// 正常merge
		int i = l;
		int a = l;
		int b = m + 1;
		while (a <= m && b <= r) {
			help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
		}
		while (a <= m) {
			help[i++] = arr[a++];
		}
		while (b <= r) {
			help[i++] = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = help[i];
		}
		return ans;
	}

	// 结果比较大，用int会溢出的，所以返回long类型
	// 特别注意溢出这个点，笔试常见坑
	// 返回arr[l...r]范围上，小和的累加和，同时请把arr[l..r]变有序
	// 时间复杂度O(n * logn)
	long smallSum(int l, int r) {
		if (l == r) {
			return 0;
		}
		int m = (l + r) / 2;
		return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
	}

	void testDemo() override {
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int ans = smallSum(0, n - 1);
		cout << ans;
	}
};