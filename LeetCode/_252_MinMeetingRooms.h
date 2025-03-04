/***题目介绍***
最多线段重合问题(leetcode也叫会议室2)
// 测试链接 : https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/
每一个线段都有start和end两个数据项，表示这条线段在X轴上从start位置开始到end位置结束。
给定一批线段，求所有重合区域中最多重合了几个线段，首尾相接的线段不算重合。
例如：线段[1,2]和线段[2.3]不重合。
线段[1,3]和线段[2,3]重合
*/
#pragma once
#include "../Solution.h"

class _252_MinMeetingRooms : public Solution {
public:
	int lineNum;
	vector<vector<int>> arr;
	priority_queue<int, vector<int>, greater<int>> lessHeap;

	_252_MinMeetingRooms(){
		arr = vector<vector<int>>(10000, vector<int>(2));
	}

	int minMeetingRooms(vector<vector<int>>& line) {

		sort(line.begin(), line.begin() + lineNum, [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

		int ans = 0;
		for (int i = 0; i < lineNum; i++) {
			while (lessHeap.size() > 0 && lessHeap.top() <= line[i][0]) {
				lessHeap.pop();
			}
			lessHeap.push(line[i][1]);
			ans = max(ans, int(lessHeap.size()));
		}
		return ans;
	}

	void testDemo() override {
		cin >> lineNum;

		for (int i = 0; i < lineNum; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> arr[i][j];
			}
		}

		cout << minMeetingRooms(arr) << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;

	}
};