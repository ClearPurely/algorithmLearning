#pragma once
#include "../Solution.h"

/// <summary>
/// 895 最大频率栈
/// 测试链接 : https://leetcode.cn/problems/maximum-frequency-stack/
/// </summary>
class FreqStack : public Solution {
private:
	// 出现的最大次数
	int topTimes;
	// 每层节点<出现次数 : 出现这多么多次的数>
	unordered_map<int, vector<int>> cntValues;
	// 每一个数出现了几次<int : 该数的出现次数>
	unordered_map<int, int> valueTimes;
public:
    FreqStack() : topTimes(0) {}

	void push(int val) {
		int curTopTimes = ++valueTimes[val];
		if (cntValues.find(curTopTimes) == cntValues.end()) {
			cntValues[curTopTimes] = vector<int>();
		}
		cntValues[curTopTimes].push_back(val);
		if (curTopTimes > topTimes)
			topTimes = curTopTimes;
	}

	int pop() {
		vector<int>& topTimeValues = cntValues[topTimes];
		int ans = topTimeValues.back();
		topTimeValues.pop_back();
		if (topTimeValues.empty()) {
			cntValues.erase(topTimes--);
		}
		if (--valueTimes[ans] == 0) {
			valueTimes.erase(ans);
		}
		return ans;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};