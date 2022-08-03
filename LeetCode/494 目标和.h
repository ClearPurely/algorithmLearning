#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include<unordered_map>

using namespace std;

/***��Ŀ����***
����һ������arr���������ÿ������֮ǰ����+����-
���Ǳ����������ֶ�����
�ٸ���һ����target������������target�ķ������Ƕ���?
*/


class Solution {
public:
	Solution()
	{
		srand(time(NULL));
	}

	///
	int findTargetSumWays1(vector<int> arr, int target) {
		return process1(arr, 0, target);
	}

	// ��������ʹ��arr[index....]���е����֣�
	// ���rest��������������Ƕ��٣�����
	// index == 7 rest = 13
	// map "7_13" 256
	int process1(vector<int> arr, int index, int rest) {
		if (index == arr.size()) { // û���ˣ�
			return rest == 0 ? 1 : 0;
		}
		// ��������arr[index] arr[index+1 ... ]
		return process1(arr, index + 1, rest - arr[index]) + process1(arr, index + 1, rest + arr[index]);
	}

	/// <summary>
	/// ������������һ��hashmap
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="s"></param>
	/// <returns></returns>
	int findTargetSumWays2(vector<int> arr, int s) {
		unordered_map<int, unordered_map<int, int>> temp;
		return process2(arr, 0, s, temp);
	}

	int process2(vector<int> arr, int index, int rest, unordered_map<int, unordered_map<int, int>> dp) {
		
		if (dp.count(index) && dp[index].count(rest)) {
			return dp[index][rest];
		}
		// ����û���У�
		int ans = 0;
		if (index == arr.size()) {
			ans = rest == 0 ? 1 : 0;
		}
		else {
			ans = process2(arr, index + 1, rest - arr[index], dp) + process2(arr, index + 1, rest + arr[index], dp);
		}
		if (!dp.count(index)) {
			unordered_map<int, int> temp;
			dp[index] = temp;
		}
		//dp[index].emplace(rest, ans);
		dp[index][rest] = ans;
		return ans;
	}

	// �Ż���һ :
	// �������Ϊarr�ж��ǷǸ���
	// ��Ϊ������arr���и���������[3,-4,2]
	// ��Ϊ������ÿ����ǰ����+����-��
	// ����[3,-4,2]��ʵ��[3,4,2]���һ����Ч��
	// ��ô���Ǿ�ȫ��arr��ɷǸ���������Ӱ������
	// �Ż���� :
	// ���arr���ǷǸ������������������ۼӺ���sum
	// ��ô���target<sum��������û���κη������Դﵽtarget������ֱ�ӷ���0
	// �Ż����� :
	// arr�ڲ������飬������ô+��-�����յĽ����һ������ı���ż��
	// ���ԣ�������������ۼӺ���sum��
	// ������target����ż�Բ�һ����û���κη������Դﵽtarget������ֱ�ӷ���0
	// �Ż����� :
	// ����˵����һ������, arr = [1, 2, 3, 4, 5] ���� target = 3
	// ����һ�������� : +1 -2 +3 -4 +5 = 3
	// �÷�����ȡ�����ļ���ΪP = {1��3��5}
	// �÷�����ȡ�˸��ļ���ΪN = {2��4}
	// �����κ�һ�ַ�������һ���� sum(P) - sum(N) = target
	// ��������������һ�������ʽ�����������߶�����sum(P) + sum(N)����ô�ͻ������£�
	// sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N)
	// 2 * sum(P) = target + �������������ۼӺ�
	// sum(P) = (target + �������������ۼӺ�) / 2
	// Ҳ����˵���κ�һ�����ϣ�ֻҪ�ۼӺ���(target + �������������ۼӺ�) / 2
	// ��ô��һ����Ӧһ��target�ķ�ʽ
	// Ҳ����˵������Ǹ�����arr��target = 7, ���������ۼӺ���11
	// ���ж��ٷ������7����ʵ�������ж����ִﵽ�ۼӺ�(7+11)/2=9�ķ���
	// �Ż����� :
	// ��ά��̬�滮�Ŀռ�ѹ������
	int findTargetSumWays(vector<int> arr, int target) {
		int sum = 0;
		for (int n : arr) {
			sum += n;
		}
		return sum < target || ((target & 1) ^ (sum & 1)) != 0 ? 0 : subset2(arr, (target + sum) >> 1);
	}

	// ��Ǹ�����nums�ж��ٸ��Ӽ����ۼӺ���s
	// ��ά��̬�滮
	// ���ÿռ�ѹ��
	int subset1(vector<int> nums, int s) {
		if (s < 0) {
			return 0;
		}
		int n = nums.size();
		// dp[i][j] : numsǰ׺����Ϊi�������Ӽ����ж����ۼӺ���j��
		vector<int> temp(s + 1);
		vector<vector<int>> dp(n + 1, temp);
		// numsǰ׺����Ϊ0�������Ӽ����ж����ۼӺ���0��һ�����ռ�
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= s; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - nums[i - 1] >= 0) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}
		return dp[n][s];
	}

	// ��Ǹ�����nums�ж��ٸ��Ӽ����ۼӺ���s
	// ��ά��̬�滮
	// �ÿռ�ѹ��:
	// ���ľ���forѭ������ģ�for (int i = s; i >= n; i--) {
	// Ϊɶ��ö�����п��ܵ��ۼӺͣ�ֻö�� n...s ��Щ�ۼӺͣ�
	// ��Ϊ��� i - n < 0��dp[i]��ô���£�����һ����dp[i]һ�������Բ��ø���
	// ��� i - n >= 0��dp[i]��ô���£���һ����dp[i] + ��һ��dp[i - n]��ֵ�������Ҫ����
	int subset2(vector<int> nums, int s) {
		if (s < 0) {
			return 0;
		}
		vector<int> dp(s + 1);
		dp[0] = 1;
		for (int n : nums) {
			for (int i = s; i >= n; i--) {
				dp[i] += dp[i - n];
			}
		}
		return dp[s];
	}



	void testDemo() {
		cout << "����һ������arr���������ÿ������֮ǰ���� + ���� -" << endl;
		cout << "���Ǳ����������ֶ�����" << endl;
		cout << "�ٸ���һ����target������������target�ķ������Ƕ��� ?" << endl;
		
		vector<int> arr = { 0, 1, 2, 3, 4, 5 };
		int target = 3;
		cout << "����һ����֤��" << findTargetSumWays(arr, target) << endl;
		cout << "����������֤��" << findTargetSumWays1(arr, target) << endl;
		cout << "����������֤��" << findTargetSumWays2(arr, target) << endl;

	}
};



