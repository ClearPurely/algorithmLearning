#pragma once
#include "../Solution.h"

using namespace std;

/***题目介绍***
规定1和A对应、2和B对应、3和C对应...26和Z对应
那么一个数字字符串比如"111”就可以转化为:"AAA"、“KA"和"AK"
给定一个只有数字字符组成的字符串str，返回有多少种转化结果
*/


class SolutionSZZFC : public Solution {
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
		if (i == str.length())		//如果到了最后一个字符，说明转化完了
			return 1;
		if (str[i] == '0')	//如果单独转化0，说明前面的选择有问题
			return 0;
		int ways = process1(str, i + 1);	//第一种选择，一位数转换
		//如果两位数转换
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


	void testDemo() override {
		cout << "规定1和A对应、2和B对应、3和C对应...26和Z对应" << endl;
		cout << "那么一个数字字符串比如“111”就可以转化为:“AAA”、“KA”和“AK”" << endl;
		cout << "给定一个只有数字字符组成的字符串str，返回有多少种转化结果" << endl;


		cout << number("7230231231232031203123") << endl;
		cout << number("7210231231232031203123") << endl;
		cout << dp("7230231231232031203123") << endl;
		cout << dp("7210231231232031203123") << endl;

	}
};



