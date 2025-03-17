/***题目介绍***
找峰值


*/
#pragma once
#include "../Solution.h"

class _162_FindPeakElement : public Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int num = (int)nums.size();
		if (nums.size() == 1) {
			return 0;
		}
		if (nums[0] > nums[1])
			return 0;
		if (nums[num - 1] > nums[num - 2])
			return num - 1;
		int left = 1, right = num - 2, m = 0, ans = -1;
		while (left <= right)
		{
			m = (right + left) >> 1;
			if (nums[m - 1] > nums[m])
				right = m - 1;
			else if (nums[m] < nums[m + 1])
				left = m + 1;
			else
			{
				ans = m;
				break;
			}
		}
		return ans;
	}

	void testDemo() override {
		cout << "峰值元素是指其值严格大于左右相邻值的元素。" << endl;
		cout << "给你一个整数数组nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。" << endl;
		cout << "你可以假设 nums[-1] = nums[n] = -∞。" << endl;
		cout << "你必须实现时间复杂度为 O(log n) 的算法来解决此问题。" << endl;
		cout << "下面一个用例【1,2,3,1】的输出示范，你可以修改代码来修改用例" << endl;
		
		vector<int> arr = { 1,2,3,1 };
		int a = findPeakElement(arr);
		cout << a << endl;
	}
};