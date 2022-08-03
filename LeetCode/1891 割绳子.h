#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include"../DataGenerator.h"

using namespace std;

/***��Ŀ����***
����һ����������arr������������X���ϵĵ�
����һ������K���������ӵĳ���
�����������ѹ�м�����?
��ʹ���ӱ�Ե����ס��Ҳ���ס
*/


class Solution {
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
		int N = arr.size();
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
	//������ٷ�
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



	void testDemo() {
		int len = 100;
		int max = 1000;
		int testTime = 100;
		cout << "����һ����������arr������������X���ϵĵ�" << endl;
		cout << "����һ������K���������ӵĳ���" << endl;
		cout << "�����������ѹ�м����� ?" << endl;
		cout << "��ʹ���ӱ�Ե����ס��Ҳ���ס" << endl;
		for (int i = 0; i < testTime; i++) {
			int L = (int)((rand() % len) + 1);
			vector<int> arr = DataGenerator().generateArray(len, max, true);
			int ans1 = maxPoint1(arr, L);
			int ans2 = maxPoint2(arr, L);
			int ans3 = test(arr, L);	//����ѭ���ⷨ
			if (ans1 != ans2 || ans2 != ans3) {
				cout << "����" << endl;
				break;
			}
			else
			{
				cout << ans1 << " " << ans2 << " " << ans3 << endl;
			}
		}
	}
};



