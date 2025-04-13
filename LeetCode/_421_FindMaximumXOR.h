/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 421 数组中两个数的最大异或值
/// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
/// </summary>
class _421_FindMaximumXOR : public Solution {
private:
	// 准备这么多静态空间就够了，实验出来的
	// 如果测试数据升级了规模，就改大这个值
	static const int MAXN = 1000;
	int tree[MAXN][2];
	// 前缀树目前使用了多少空间
	int cnt;
	// 数字只需要从哪一位开始考虑
	int high;

public:
	// 前缀树的做法
    void insert(int num) {
        int cur = 1;
        for (int i = high; i >= 0; --i) {
            int path = (num >> i) & 1;
            if (tree[cur][path] == 0) {
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
        }
    }

    void build(vector<int>& nums) {
        cnt = 1;
        if (nums.empty()) {
            high = -1;
            return;
        }
        int max_val = *max_element(nums.begin(), nums.end());
        if (max_val == 0) {
            high = -1;
        }
        else {
            high = 0;       //最大值在二进制上最高有效位
            int temp = max_val;
            while (temp >>= 1) {
                ++high;
            }
        }
        for (int num : nums) {
            insert(num);
        }
    }

    int maxXor(int num) {
        int ans = 0;
        int cur = 1;    // 前缀树目前来到的节点编号
        for (int i = high; i >= 0; --i) {
            int status = (num >> i) & 1;
            int want = status ^ 1;
            if (tree[cur][want] == 0) { //有一个数在这一位上为0
                want ^= 1;
            }
            ans |= (status ^ want) << i;
            cur = tree[cur][want];
        }
        return ans;
    }

    void clear() {
        for (int i = 1; i <= cnt; ++i) {
            tree[i][0] = tree[i][1] = 0;
        }
    }

    int findMaximumXOR1(vector<int>& nums) {
        memset(tree, 0, sizeof(tree));
        build(nums);
        int ans = 0;
        for (int num : nums) {
            ans = max(ans, maxXor(num));
        }
        clear();
        return ans;
    }

	int findMaximumXOR(vector<int> nums) {
		int maxNum = *std::max_element(nums.begin(), nums.end());
        int h = 0;
        while (maxNum >>= 1)
            ++h;
        int ans = 0;
        unordered_multiset<int> setNums;
        for (int i = h; i >= 0; i--) {
            int better = ans | (1 << i);    //理论上当前最有状态
            setNums.clear();
            for (int num : nums)
            {
                num = (num >> i) << i;
                setNums.emplace(num);   //只保留左侧状态，然后放入set，这样可以讨论出目前左侧最优数是哪一个
                if (setNums.count(better ^ num))
                {
                    ans = better;
                    break;
                }
            }
        }
        return ans;
	}

	void testDemo() override {
		vector<int> inArr = { 14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70 };
		cout << findMaximumXOR1(inArr) << endl;
		cout << findMaximumXOR(inArr) << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};