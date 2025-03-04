#pragma once
#include "../Solution.h"

class _1_TwoSum : public Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0;
        for (i = 0; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i,j };
                }
            }
        }
        return { i,j };
    }

    vector<int> twoSum1(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> b(2,-1);
        for (int i = 0; i < nums.size(); i++)
        {
            a.insert(map<int, int>::value_type(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i]) && a[target - nums[i]] != i) //判断map中找到的元素是否是本身
            {
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        }
        return b;
    }

    //测试代码
    void testDemo() override {
        vector<int> v = { 1,2,3,4,5,6 };
        vector<int> v1 = twoSum1(v, 3);

        cout << "给定一个整数数组 nums 和一个整数目标值 target，请你在该数组" << endl;
        cout << "中找出和为目标值target的那两个整数，并返回它们的数组下标。" << endl;
        cout << "你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。" << endl;
        cout << "你可以按任意顺序返回答案。" << endl;

        cout << "输入数组为1，2，3，4，5" << endl;
        cout << "预期返回索引0，1" << endl;
        cout << v1[0] << "  " << v1[1] << endl;
    }
};