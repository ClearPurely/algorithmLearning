/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 数字的全排列
/// </summary>
class _46_47_Permute : public Solution {
public:
	/// 46 没有重复项数字的全排列
	/// 测试链接 : https://leetcode.cn/problems/permutations/
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		f(nums, 0, ans);
		return ans;
	}

	void f(vector<int>& nums, int i, vector<vector<int>>& ans) {
		if (i == (int)nums.size()) {
			ans.emplace_back(nums.begin(), nums.end());
		}
		else {
			for (int j = i; j < (int)nums.size(); j++) {
				swap(nums[i], nums[j]);
				f(nums, i + 1, ans);
				swap(nums[i], nums[j]); // 特别重要，课上进行了详细的图解
			}
		}
	}

	/// 47 有重复项数组的去重全排列
	/// 测试链接 : https://leetcode.cn/problems/permutations-ii/
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		f2(nums, 0, ans);
		return ans;
	}

	void f2(vector<int>& nums, int i, vector<vector<int>>& ans) {
		if (i == (int)nums.size()) {
			ans.emplace_back(nums.begin(), nums.end());
		}
		else {
			unordered_set<int> numsSet;
			for (int j = i; j < (int)nums.size(); j++) {
				if (numsSet.count(nums[j]) == 0) {
					numsSet.insert(nums[j]);
					swap(nums[i], nums[j]);
					f(nums, i + 1, ans);
					swap(nums[i], nums[j]);
				}
			}
		}
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};