#pragma once
#include "../Solution.h"

/// <summary>
/// 380 插入、删除和获取随机元素O(1)时间的结构
/// 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1/
/// </summary>
class RandomizedSet : public Solution {
private:
	unordered_map<int, int> map;
	vector<int> arr;
public:
    RandomizedSet() {
		srand(static_cast<unsigned int>(time(nullptr)));  // 新增初始化
    }

    bool insert(int val) {
		if (map.find(val) != map.end()) {
			return false;
		}
		map[val] = (int)arr.size();
		arr.push_back(val);
		return true;
    }

    bool remove(int val) {
		if (map.find(val) == map.end()) {
			return false;
		}
        int valIndex = map[val];
        int endValue = arr.back();

        // 保持原操作顺序
        map[endValue] = valIndex;
        arr[valIndex] = endValue;

        // 保持删除顺序
        arr.pop_back();
        map.erase(val);

        return true;
    }

    int getRandom() {
		return arr[rand() % arr.size()];
    }
};