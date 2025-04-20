/***题目介绍***
前缀和相关题目
*/
#pragma once
#include "../Solution.h"

class PrefixSum : public Solution {
private:

public:

	// 返回无序数组中累加和为给定值的最长子数组长度
	// 给定一个无序数组arr, 其中元素可正、可负、可0
	// 给定一个整数aim
	// 求arr所有子数组中累加和为aim的最长子数组长度
	// 测试链接 : https://www.nowcoder.com/practice/
	// 拓展：返回无序数组中正数和负数个数相等的最长子数组长度
	// 拓展测试链接 : https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb
	int compute(vector<int>& arr, int aim) {
		unordered_map<int,int> sumMap;	//<前缀和，该前缀和第一次出现的索引>
		// 重要 : 0这个前缀和，一个数字也没有的时候，就存在了
		sumMap[0] = -1;
		int ans = 0;
		for (int i = 0, sum = 0; i < (int)arr.size(); i++) {
			sum += arr[i];
			if (sumMap.count(sum - aim) > 0) {
				ans = std::max(ans, i - sumMap[sum - aim]);
			}
			//为啥遇到相同的前缀和只记录第一次出现的位置？
			//因为要计算最大子数组
			if (sumMap.count(sum) == 0) {
				sumMap[sum] = i;
			}
		}
		return ans;
	}

	// 560 返回无序数组中累加和为给定值的子数组个数
	// 测试链接 : https://leetcode.cn/problems/subarray-sum-equals-k/
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> sumMap;	//<前缀和，该前缀和出现的次数>
		sumMap[0] = 1;
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < (int)nums.size(); i++) {
			sum += nums[i];
			auto iter = sumMap.find(sum - k);
			if (iter != sumMap.end())
				ans += iter->second;
			sumMap[sum]++;
		}
		return ans;
	}

	// 1124 表现良好的最长时间段
	// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
	// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
	// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
	// 请你返回 表现良好时间段 的最大长度
	// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/
	int longestWPI(vector<int>& hours) {
		unordered_map<int, int> sumMap;	//<前缀和，该前缀和第一次出现的索引>
		int ans = 0;
		sumMap[0] = ans;
		for (int i = 0,sum = 0; i < (int)hours.size(); i++)
		{
			sum += hours[i] > 8 ? 1 : -1;
			if (sum > 0)
				ans = i + 1;
			else
				if (sumMap.count(sum - 1) > 0)
					ans = max(ans, i - sumMap[sum - 1]);
			if (sumMap.count(sum) == 0)
				sumMap[sum] = i;
		}
		return ans;
	}

	// 1590 使数组和能被P整除
	// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空）
	// 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
	// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
	// 子数组 定义为原数组中连续的一组元素。
	// 测试链接 : https://leetcode.cn/problems/make-sum-divisible-by-p/
	int minSubarray(vector<int>& nums, int p) {
		int mod = 0;	//所有元素的余数
		for (int num : nums)		//避免一口气加完会有溢出的可能
			mod = (mod + num) % p;
		if (mod == 0)
			return 0;
		int ans = INT_MAX;
		unordered_map<int, int> sumMap;//<前缀和%p的余数，该前缀和最后一次出现的索引>
		sumMap[0] = -1;
		for (int i = 0,cur = 0,find = 0; i < (int)nums.size(); i++)
		{
			cur = (cur + nums[i]) % p;		//当前0到i位置的子数组的前缀和的余数
			find = (cur + p - mod) % p;		//[0,i]数组的余数 - [0,j]数组的余数 满足 能够被mod整除（j<i），最终的到[j,i]子数组的前缀和余数 = mod
			if (sumMap.count(find) > 0)
				ans = min(ans, i - sumMap[find]);
			sumMap[cur] = i;
		}
		return ans == (int)nums.size() ? -1 : ans;
	}

	// 1371 每个元音包含偶数次的最长子字符串
	// 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度
	// 每个元音字母，即 'a'，'e'，'i'，'o'，'u'
	// 在子字符串中都恰好出现了偶数次。
	// 测试链接 : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
	int findTheLongestSubstring(string s) {
		int n = (int)s.size();
		//五个字符最多32个状态，所以用一个数组就可以表示五个字符出现次数异或的所有状态
		int sumMap[32];
		fill(sumMap, sumMap + 32, -2);
		sumMap[0] = -1;
		int ans = 0;
		for (int i = 0,cur = 0; i < n; i++)
		{
			int m = charMap(s[i]);
			if (m != -1)
				cur ^= (1 << m);
			if (sumMap[cur] != -2)
				ans = max(ans, i - sumMap[cur]);
			else
				sumMap[cur] = i;
		}
		return ans;
	}

	int charMap(char c)
	{
		switch (c)
		{
		case 'a':
			return 0;
		case 'e':
			return 1;
		case 'i':
			return 2;
		case 'o':
			return 3;
		case 'u':
			return 4;
		default:
			return -1;
		}
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};