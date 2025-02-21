
// С������
// �������� : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
#pragma once
#include "../Solution.h"
#include"../readProcessFun.h"

#include<vector>		//����
using namespace std;


static int MAXN = 100001;

class SmallSum : public Solution {
private:
	vector<int> arr;
	vector<int> help;
	int n;

public:
	SmallSum(): arr(MAXN), help(MAXN), n(0){

	}

	// ���ؿ����Ҳ�����С���ۼӺͣ���������Ҳ�����������������������
	// arr[l...m] arr[m+1...r]
	long merge(int l, int m, int r) {
		// ͳ�Ʋ���
		long ans = 0;
		for (int j = m + 1, i = l, sum = 0; j <= r; j++) {
			while (i <= m && arr[i] <= arr[j]) {
				sum += arr[i++];
			}
			ans += sum;
		}
		// ����merge
		int i = l;
		int a = l;
		int b = m + 1;
		while (a <= m && b <= r) {
			help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
		}
		while (a <= m) {
			help[i++] = arr[a++];
		}
		while (b <= r) {
			help[i++] = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = help[i];
		}
		return ans;
	}

	// ����Ƚϴ���int������ģ����Է���long����
	// �ر�ע���������㣬���Գ�����
	// ����arr[l...r]��Χ�ϣ�С�͵��ۼӺͣ�ͬʱ���arr[l..r]������
	// ʱ�临�Ӷ�O(n * logn)
	long smallSum(int l, int r) {
		if (l == r) {
			return 0;
		}
		int m = (l + r) / 2;
		return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
	}

	void testDemo() override {
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int ans = smallSum(0, n - 1);
		cout << ans;
	}
};