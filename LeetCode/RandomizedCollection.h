#pragma once
#include "../Solution.h"

/// <summary>
/// 381 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
/// 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
/// </summary>
class RandomizedCollection : public Solution {
private:
    unordered_map<int, unordered_set<int>> map;
    vector<int> arr;

public:
    RandomizedCollection() {
        srand(static_cast<unsigned int>(time(nullptr)));  // 新增初始化
    }

    bool insert(int val) {
        arr.push_back(val);
        int index = (int)arr.size() - 1;
        auto& indices = map[val];
        bool wasEmpty = indices.empty();
        indices.insert(index);
        return wasEmpty;
    }

    bool remove(int val) {
        auto it = map.find(val);
        if (it == map.end()) {
            return false;
        }

        //对应元素的set
        unordered_set<int>& valIndices = it->second;
        //默认删除set里面的第一个元素的（对应该元素在数组里面的第一下标）
        int valAnyIndex = *valIndices.begin();
        int lastElement = arr.back();

        if (val == lastElement) {   //判断最后一个元素是否为要删除的元素，是则可以直接删除
            valIndices.erase((int)arr.size() - 1);
            arr.pop_back();
        }
        else {
            //vec里面最后一个元素对应的set
            unordered_set<int>& lastIndices = map[lastElement];
            arr[valAnyIndex] = lastElement;
            lastIndices.erase((int)arr.size() - 1);
            lastIndices.insert(valAnyIndex);
            valIndices.erase(valAnyIndex);
            arr.pop_back();
        }

        if (valIndices.empty()) {
            map.erase(it);
        }

        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};