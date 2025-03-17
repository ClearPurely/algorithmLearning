#pragma once
#include "../Solution.h"

/// <summary>
/// 295 快速获得数据流的中位数的结构
/// 测试链接 : https://leetcode.cn/problems/find-median-from-data-stream/
/// </summary>
class MedianFinder : public Solution {
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
public:
	MedianFinder() {
	}

	void addNum(int num) {
		if (maxHeap.empty()|| maxHeap.top() >= num) {
			maxHeap.push(num);
		}
		else {
			minHeap.push(num);
		}
		balance();
	}

	double findMedian() {
		if (maxHeap.size() == minHeap.size()) {
			return (double)(maxHeap.top() + minHeap.top()) / 2;
		}
		else {
			return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
		}
	}

	void balance() {
		if (std::abs((int)maxHeap.size() - (int)minHeap.size()) == 2) {
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
			else {
				maxHeap.push(minHeap.top());
				minHeap.pop();
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