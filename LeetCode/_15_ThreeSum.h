﻿#pragma once
#include "../Solution.h"

/// <summary>
/// 15 三数之和
/// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
/// 注意：答案中不可以包含重复的三元组。
/// 提示：
/// 0 <= nums.length <= 3000
/// - 105 <= nums[i] <= 105
/// </summary>
class _15_ThreeSum : public Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = (int)nums.size();
        if (size < 3)   return {};          // 特判
        vector<vector<int> >res;            // 保存结果（所有不重复的三元组）
        sort(nums.begin(), nums.end());// 排序（默认递增）
        for (int i = 0; i < size; i++)      // 固定第一个数，转化为求两数之和
        {
            if (nums[i] > 0)    return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了
            // 去重：如果此数已经选取过，跳过
            if (i > 0 && nums[i] == nums[i - 1])  continue;
            // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i])
                    right--;    // 两数之和太大，右指针左移
                else if (nums[left] + nums[right] < -nums[i])
                    left++;     // 两数之和太小，左指针右移
                else
                {
                    // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // 去重：第二个数和第三个数也不重复选取
                    // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while (left < right && nums[left] == nums[left - 1])  left++;
                    while (left < right && nums[right] == nums[right + 1])    right--;
                }
            }
        }
        return res;
    }

    //测试代码
    void testDemo() override {
        vector<int> v = { 1,21,-36,32,16,20,3,8,7,2,1,13,-11 };
        vector<vector<int>> ret = threeSum(v);
        for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end();++it) {
            for (vector<int>::iterator ite = (*it).begin(); ite != (*it).end(); ++ite) {
                cout << (*ite) << " ";
            }
            cout << endl;
        }
    }
};





