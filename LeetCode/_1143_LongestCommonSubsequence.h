/***��Ŀ����***
�����������
���������ַ���text1��text2�������������ַ���������������� �ĳ��ȡ���������ڹ���������,����0��
һ���ַ�������������ָ����һ���µ��ַ�����
������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����
���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�
�����ַ����Ĺ������������������ַ�������ͬӵ�е������С�
*/
#pragma once
#include "../Solution.h"

class _1143_LongestCommonSubsequence : public Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		if (text1.empty() || text2.empty())
			return 0;

		return process1(text1, text2, text1.size() - 1, text2.size() - 1);
	}

	int process1(string s1, string s2, int i, int j)
	{
		if (i == 0 && j == 0)
			return s1[i] == s2[j] ? 1 : 0;
		else if (i == 0)	//s1ֻ��һ���ַ�ʱ
		{
			if (s1[i] == s2[j])
				return 1;
			else
				return process1(s1, s2, i, j - 1);
		}
		else if (j == 0)	//s2ֻ��һ���ַ�ʱ
		{
			if (s1[i] == s2[j])
				return 1;
			else
				return process1(s1, s2, i - 1, j);
		}
		else
		{
			int p1 = process1(s1, s2, i - 1, j);
			int p2 = process1(s1, s2, i, j - 1);
			int p3 = s1[i] == s2[j] ? (1 + process1(s1, s2, i - 1, j - 1)) : INT_MIN;
			return max(p1, max(p2, p3));
		}
	}

	int longestCommonSubsequence2(string text1, string text2) {
		if (text1.empty() || text2.empty())
			return 0;
		int N = text1.size();
		int M = text2.size();
		vector<vector<int>> dp(N,vector<int>(M,0));
		dp[0][0] = text1[0] == text2[0] ? 1 : 0;
		for (int j = 1; j < M; j++)
		{
			dp[0][j] = text1[0] == text2[j] ? 1 : dp[0][j - 1];
		}
		for (int i = 1; i < N; i++)
		{
			dp[i][0] = text1[i] == text2[0] ? 1 : dp[i - 1][0];
		}
		for (int i = 1; i < N; i++)
			for (int j = 1; j < M; j++)
			{
				int p1 = dp[i - 1][j];
				int p2 = dp[i][j - 1];
				int p3 = text1[i] == text2[j] ? (1 + dp[i - 1][j - 1]) : 0;
				dp[i][j] = max(p1, max(p2, p3));
			}
		return dp[N - 1][M - 1];
	}

	void testDemo() override {
		cout << "���������ַ���text1��text2�������������ַ���������������� �ĳ��ȡ���������ڹ���������,����0��" << endl;

		string s = "abc";
		string s2(s.rbegin(), s.rend());
		cout << s.size() << endl;
		cout << s[s.size()] << endl;


	}
};



