#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include <string>
#include"../DataGenerator.h"

using namespace std;

/***��Ŀ����***
�涨1��A��Ӧ��2��B��Ӧ��3��C��Ӧ...26��Z��Ӧ
��ôһ�������ַ�������"111���Ϳ���ת��Ϊ:"AAA"����KA"��"AK"
����һ��ֻ�������ַ���ɵ��ַ���str�������ж�����ת�����
*/


class Solution {
public:
	int number(string str)
	{
		if (str.empty() || str.length() == 0)
		{
			return -1;
		}
		return process1(str,0);
	}

	int process1(string str, int i)
	{
		if (i == str.length())		//����������һ���ַ���˵��ת������
			return 1;
		if (str[i] == '0')	//�������ת��0��˵��ǰ���ѡ��������
			return 0;
		int ways = process1(str, i + 1);	//��һ��ѡ��һλ��ת��
		//�����λ��ת��
		if (i + 1 < str.length() && (str[i] - '0') * 10 + str[i] - '0' < 27)
		{
			ways += process1(str, i + 2);
		}
		return ways;
	}

	int dp(string str)
	{
		if (str.empty() || str.length() == 0)
		{
			return -1;
		}
		int N = str.length();
		vector<int> dp(N+1);
		dp[N] = 1;
		for (int i = N-1; i >= 0; i--)
		{
			if (str[i] != '0')
			{
				int ways = dp[i + 1];
				if (i + 1 < str.length() && (str[i] - '0') * 10 + str[i] - '0' < 27)
				{
					ways += dp[i + 2];;
				}
				dp[i] = ways;
			}
		}
		return dp[0];
	}


	void testDemo() {
		cout << "�涨1��A��Ӧ��2��B��Ӧ��3��C��Ӧ...26��Z��Ӧ" << endl;
		cout << "��ôһ�������ַ������硰111���Ϳ���ת��Ϊ:��AAA������KA���͡�AK��" << endl;
		cout << "����һ��ֻ�������ַ���ɵ��ַ���str�������ж�����ת�����" << endl;


		cout << number("7230231231232031203123") << endl;
		cout << number("7210231231232031203123") << endl;
		cout << dp("7230231231232031203123") << endl;
		cout << dp("7210231231232031203123") << endl;

	}
};



