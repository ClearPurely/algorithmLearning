/***题目介绍***
割绳子
给定一个有序数组arr，代表坐落在X轴上的点
给定一个正数K，代表绳子的长度
返回绳子最多压中几个点?
即使绳子边缘处盖住点也算盖住
*/
#pragma once
#include "../Solution.h"

class _1891_MaxPoint : public Solution {
public:
	int maxPoint1(vector<int> arr, int L) {
		int res = 1;
		for (int i = 0; i < arr.size(); i++) {
			int nearest = nearestIndex(arr, i, arr[i] - L);
			res = max(res, i - nearest + 1);
		}
		return res;
	}


	int nearestIndex(vector<int> arr, int R, int value) {
		int L = 0;
		int index = R;
		while (L <= R) {
			int mid = L + ((R - L) >> 1);
			if (arr[mid] >= value) {
				index = mid;
				R = mid - 1;
			}
			else {
				L = mid + 1;
			}
		}
		return index;
	}

	int maxPoint2(vector<int> arr, int L) {
		int left = 0;
		int right = 0;
		int N = (int)arr.size();
		int max = 0;
		while (left < N) {
			while (right < N && arr[right] - arr[left] <= L) {
				right++;
			}
			max = std::max(max, right - (left++));
		}
		return max;
	}

	// for test
	//暴力穷举法
	int test(vector<int> arr, int L) {
		int max = 0;
		for (int i = 0; i < arr.size(); i++) {
			int pre = i - 1;
			while (pre >= 0 && arr[i] - arr[pre] <= L) {
				pre--;
			}
			max = std::max(max, i - pre);
		}
		return max;
	}



	void testDemo() override {
		int len = 100;
		int max = 1000;
		int testTime = 100;
		cout << "给定一个有序数组arr，代表坐落在X轴上的点" << endl;
		cout << "给定一个正数K，代表绳子的长度" << endl;
		cout << "返回绳子最多压中几个点 ?" << endl;
		cout << "即使绳子边缘处盖住点也算盖住" << endl;
		for (int i = 0; i < testTime; i++) {
			int L = (int)((rand() % len) + 1);

			vector<int> arr = randomArray1(len, max, true);
			int ans1 = maxPoint1(arr, L);
			int ans2 = maxPoint2(arr, L);
			int ans3 = test(arr, L);	//暴力循环解法
			if (ans1 != ans2 || ans2 != ans3) {
				cout << "错误" << endl;
				break;
			}
			else
			{
				cout << ans1 << " " << ans2 << " " << ans3 << endl;
			}
		}
	}
};



