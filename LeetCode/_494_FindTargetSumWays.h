﻿/***题目介绍***
目标和
给定一个数组arr，你可以在每个数字之前决定+或者-
但是必须所有数字都参与
再给定一个数target，请问最后算出target的方法数是多少?
*/
#pragma once
#include "../Solution.h"




class _494_FindTargetSumWays : public Solution {
public:
	_494_FindTargetSumWays()
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	///
	int findTargetSumWays1(vector<int> arr, int target) {
		return process1(arr, 0, target);
	}

	// 可以自由使用arr[index....]所有的数字！
	// 搞出rest这个数，方法数是多少？返回
	// index == 7 rest = 13
	// map "7_13" 256
	int process1(vector<int> arr, int index, int rest) {
		if (index == arr.size()) { // 没数了！
			return rest == 0 ? 1 : 0;
		}
		// 还有数！arr[index] arr[index+1 ... ]
		return process1(arr, index + 1, rest - arr[index]) + process1(arr, index + 1, rest + arr[index]);
	}

	/// <summary>
	/// 方法二，增加一个hashmap
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="s"></param>
	/// <returns></returns>
	int findTargetSumWays2(vector<int> arr, int s) {
		unordered_map<int, unordered_map<int, int>> temp;
		return process2(arr, 0, s, temp);
	}

	int process2(vector<int> arr, int index, int rest, unordered_map<int, unordered_map<int, int>> dp) {
		
		if (dp.count(index) && dp[index].count(rest)) {
			return dp[index][rest];
		}
		// 否则，没命中！
		int ans = 0;
		if (index == arr.size()) {
			ans = rest == 0 ? 1 : 0;
		}
		else {
			ans = process2(arr, index + 1, rest - arr[index], dp) + process2(arr, index + 1, rest + arr[index], dp);
		}
		if (!dp.count(index)) {
			unordered_map<int, int> temp;
			dp[index] = temp;
		}
		//dp[index].emplace(rest, ans);
		dp[index][rest] = ans;
		return ans;
	}

	// 优化点一 :
	// 你可以认为arr中都是非负数
	// 因为即便是arr中有负数，比如[3,-4,2]
	// 因为你能在每个数前面用+或者-号
	// 所以[3,-4,2]其实和[3,4,2]达成一样的效果
	// 那么我们就全把arr变成非负数，不会影响结果的
	// 优化点二 :
	// 如果arr都是非负数，并且所有数的累加和是sum
	// 那么如果target<sum，很明显没有任何方法可以达到target，可以直接返回0
	// 优化点三 :
	// arr内部的数组，不管怎么+和-，最终的结果都一定不会改变奇偶性
	// 所以，如果所有数的累加和是sum，
	// 并且与target的奇偶性不一样，没有任何方法可以达到target，可以直接返回0
	// 优化点四 :
	// 比如说给定一个数组, arr = [1, 2, 3, 4, 5] 并且 target = 3
	// 其中一个方案是 : +1 -2 +3 -4 +5 = 3
	// 该方案中取了正的集合为P = {1，3，5}
	// 该方案中取了负的集合为N = {2，4}
	// 所以任何一种方案，都一定有 sum(P) - sum(N) = target
	// 现在我们来处理一下这个等式，把左右两边都加上sum(P) + sum(N)，那么就会变成如下：
	// sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N)
	// 2 * sum(P) = target + 数组所有数的累加和
	// sum(P) = (target + 数组所有数的累加和) / 2
	// 也就是说，任何一个集合，只要累加和是(target + 数组所有数的累加和) / 2
	// 那么就一定对应一种target的方式
	// 也就是说，比如非负数组arr，target = 7, 而所有数累加和是11
	// 求有多少方法组成7，其实就是求有多少种达到累加和(7+11)/2=9的方法
	// 优化点五 :
	// 二维动态规划的空间压缩技巧
	int findTargetSumWays(vector<int> arr, int target) {
		int sum = 0;
		for (int n : arr) {
			sum += n;
		}
		return sum < target || ((target & 1) ^ (sum & 1)) != 0 ? 0 : subset2(arr, (target + sum) >> 1);
	}

	// 求非负数组nums有多少个子集，累加和是s
	// 二维动态规划
	// 不用空间压缩
	int subset1(vector<int> nums, int s) {
		if (s < 0) {
			return 0;
		}
		int n = (int)nums.size();
		// dp[i][j] : nums前缀长度为i的所有子集，有多少累加和是j？
		vector<int> temp(s + 1);
		vector<vector<int>> dp(n + 1, temp);
		// nums前缀长度为0的所有子集，有多少累加和是0？一个：空集
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= s; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - nums[i - 1] >= 0) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}
		return dp[n][s];
	}

	// 求非负数组nums有多少个子集，累加和是s
	// 二维动态规划
	// 用空间压缩:
	// 核心就是for循环里面的：for (int i = s; i >= n; i--) {
	// 为啥不枚举所有可能的累加和？只枚举 n...s 这些累加和？
	// 因为如果 i - n < 0，dp[i]怎么更新？和上一步的dp[i]一样！所以不用更新
	// 如果 i - n >= 0，dp[i]怎么更新？上一步的dp[i] + 上一步dp[i - n]的值，这才需要更新
	int subset2(vector<int> nums, int s) {
		if (s < 0) {
			return 0;
		}
		vector<int> dp(s + 1);
		dp[0] = 1;
		for (int n : nums) {
			for (int i = s; i >= n; i--) {
				dp[i] += dp[i - n];
			}
		}
		return dp[s];
	}



	void testDemo() override {
		cout << "给定一个数组arr，你可以在每个数字之前决定 + 或者 -" << endl;
		cout << "但是必须所有数字都参与" << endl;
		cout << "再给定一个数target，请问最后算出target的方法数是多少 ?" << endl;
		
		vector<int> arr = { 0, 1, 2, 3, 4, 5 };
		int target = 3;
		cout << "方法一的验证：" << findTargetSumWays(arr, target) << endl;
		cout << "方法二的验证：" << findTargetSumWays1(arr, target) << endl;
		cout << "方法三的验证：" << findTargetSumWays2(arr, target) << endl;

	}
};



