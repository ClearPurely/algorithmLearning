/***题目介绍**
// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
// 注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 测试链接 : https://leetcode.cn/problems/subsets-ii/
*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 90 子集 II
/// </summary>
class _90_SubsetsWithDup : public Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		std::sort(nums.begin(), nums.end());
		vector<int> path(nums.size());
		f(nums, 0, path, 0, ans);
		return ans;
	}

	//理解：这里每次传入path的状态，但每次向下传递时path[i]位置都会被覆盖，形成了这种回溯的概念
	void f(vector<int>& nums, int i, vector<int>& path, int size, vector<vector<int>>& ans) {
		if (i == nums.size()) {
			ans.emplace_back(path.begin(), path.begin() + size); // 直接构造子集
			return;
		}
		else {
			// 下一组的第一个数的位置
			int j = i + 1;
			while (j < (int)nums.size() && nums[i] == nums[j]) {
				j++;
			}
			// 当前数x，要0个
			f(nums, j, path, size, ans);
			// 当前数x，要1个、要2个、要3个...都尝试
			for (; i < j; i++) {
				path[size++] = nums[i];	//依次填到path中去
				f(nums, j, path, size, ans);
			}
		}
	}

	// 下面是对这道题的拓展
	// 字符串的全部子序列
	// 子序列本身是可以有重复的，只是这个题目要求去重
	// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
	// 相当于可以看成没有重复的数字的数组获取所有的子集
	vector<string> generatePermutation(string str) {
		vector<char> s(str.begin(), str.end());
		unordered_set<string> set;
		vector<char> path(s.size());
		f2(s, 0, path, 0, set);
		vector<string> ans(set.begin(), set.end());
		return ans;
	}

	void f2(const vector<char>& s, int i, vector<char>& path, int size, unordered_set<string>& set) {
		if (i == s.size()) {
			string temp(path.begin(), path.begin() + size);
			set.insert(temp);
		}
		else {
			path[size] = s[i];
			f2(s, i + 1, path, size + 1, set);
			f2(s, i + 1, path, size, set);
		}
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};