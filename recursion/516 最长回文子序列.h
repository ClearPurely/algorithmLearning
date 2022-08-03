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
����һ���ַ���str����������ַ���������������г���
����: str = ��a12b3c43def2ghi1kpm��
������������ǡ�1234321�����ߡ�123c321�������س���7
*/


class Solution {
public:
	//���Կ�����һ���ַ������������ַ�������󹫹������У��ⷨ�ɼ�1143��
	int longestPalindromeSubseq(string s) {
		if (s.empty())
			return 0;
		string s2(s.rbegin(), s.rend());
		return longestCommonSubsequence(s, s2);
	}

	int longestCommonSubsequence(string text1, string text2) {
		if (text1.empty() || text2.empty())
			return 0;
		int N = text1.size();
		int M = text2.size();
		vector<vector<int>> dp(N, vector<int>(M, 0));
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

	int longestPalindromeSubseq2(string s) {
		if (s.empty())
			return 0;
		return f(s, 0, s.size() - 1);
	}

	int f(string s, int L, int R)
	{
		if (L == R)
			return 1;
		if (L == R - 1)
			return s[L] == s[R] ? 2 : 1;

		int p1 = f(s, L + 1, R - 1);
		int p2 = f(s, L, R - 1);
		int p3 = f(s, L + 1, R);
		int p4 = s[L] == s[R] ? (f(s, L + 1, R - 1) + 2) : 0;
		return max(p1, max(p2, max(p3, p4)));
	}

	//��̬�滮
	int longestPalindromeSubseq3(string s) {
		if (s.empty())
			return 0;
		int N = s.size();
		vector<vector<int>> dp(N, vector<int>(N, 0));
		dp[N - 1][N - 1] = 1;
		for (int i = 0; i < N-1; i++)
		{
			dp[i][i] = 1;
			dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
		}
		//�ӵ��������п�ʼ��
		for (int L = N-3; L >= 0; --L)
		{
			for (int R = L + 2; R < N; ++R)
			{
				int p1 = dp[L + 1][R - 1];	//����
				int p2 = dp[L][R - 1];
				int p3 = dp[L + 1][R];
				int p4 = s[L] == s[R] ? (dp[L + 1][R - 1] + 2) : 0;
				dp[L][R] = max(p1, max(p2, max(p3, p4)));
			}
		}
		return dp[0][N - 1];
	}

	//�Ż�
	int longestPalindromeSubseq3(string s) {
		if (s.empty())
			return 0;
		int N = s.size();
		vector<vector<int>> dp(N, vector<int>(N, 0));
		dp[N - 1][N - 1] = 1;
		for (int i = 0; i < N - 1; i++)
		{
			dp[i][i] = 1;
			dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
		}
		//�ӵ��������п�ʼ��
		for (int L = N - 3; L >= 0; --L)
		{
			for (int R = L + 2; R < N; ++R)
			{
				dp[L][R] = max(dp[L][R - 1], dp[L + 1][R]);
				if (s[L] == s[R])
					dp[L][R] = max(dp[L][R], dp[L + 1][R - 1] + 2);
			}
		}
		return dp[0][N - 1];
	}

	void testDemo() {
		cout << "����һ���ַ���str����������ַ���������������г���" << endl;
		cout << "����: str = ��a12b3c43def2ghi1kpm��" << endl;
		cout << "������������ǡ�1234321�����ߡ�123c321�������س���7" << endl;





	}
};



