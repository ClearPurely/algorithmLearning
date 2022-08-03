#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include"../DataGenerator.h"

using namespace std;

/***题目介绍***
假设有排成一行的N个位置，记为1~N，N一定大于或等于2
开始时机器人在其中的M位置上(M一定是1~N中的一个)
如果机器人来到1位置，那么下一步只能往右来到2位置;
如果机器人来到N位置，那么下一步只能往左来到N-1位置;
如果机器人来到中间位置，那么下一步可以往左走或者往右走;
规定机器人必须走K步，最终能来到P位置(P也是1~N中的一个)的方法有多少种
给定四个参数N、M、K、P，返回方法数。
*/


class Solution {
public:
	int ways1(int N, int start, int aim, int rest)
	{
		if (N < 2 || start < 1 || aim<1 || aim>N || rest<1 || start>N)
		{
			cout << "无效参数" << endl;
			return -1;
		}
		return process1(start,rest,aim,N);
	}

	//机器人当前来到的位置是cur,
	//机器人还有rest步需要去走，最终的目标是aim,
	//有哪些位置可以到达? 1...N（0位置不可到达）
	//rest就是代表有多少步可以走
	//返回︰机器人从cur出发，走过rest步之后，最终停在aim的方法数，是多少?
	int process1(int cur, int rest, int aim, int N)
	{
		if (rest == 0)		//如果步数消耗完
			return cur == aim ? 1 : 0;
		if (cur == 1)
			return process1(2, rest - 1, aim, N);
		if (cur == N)
			return process1(N - 1, rest - 1, aim, N);
		return process1(cur - 1, rest - 1, aim, N) + process1(cur + 1, rest - 1, aim, N);
	}

	//优化1：用动态规划，缓存之前算过的过程，直接返回,也叫记忆化搜索
	int ways2(int N, int start, int aim, int rest)
	{
		if (N < 2 || start < 1 || aim<1 || aim>N || rest<1 || start>N)
		{
			cout << "无效参数" << endl;
			return -1;
		}
		vector<int> temp(rest + 1, -1);
		vector<vector<int>> dp(N + 1, temp);
		//dp就是缓存表
		//dp[cur][rest] == -1	->	process1(cur, rest)之前没算过!
		//dp[cur][rest] != -1	->	process1(cur, rest)之前算过!返回值，dp[cur][rest]
		//N + 1 * K + 1

		return process2(start, rest, aim, N, dp);
	}

	int process2(int cur, int rest, int aim, int N, vector<vector<int>> dp)
	{
		if (dp[cur][rest] != -1)
			return dp[cur][rest];
		//如果这一步之前没算过
		int ans = 0;

		if (rest == 0)		//如果步数消耗完
			ans = cur == aim ? 1 : 0;
		else if (cur == 1)
			ans = process2(2, rest - 1, aim, N,dp);
		else if (cur == N)
			ans = process2(N - 1, rest - 1, aim, N,dp);
		else
			ans = process2(cur - 1, rest - 1, aim, N,dp) + process2(cur + 1, rest - 1, aim, N,dp);
		
		dp[cur][rest] = ans;
		return ans;
	}

	//利用状态转移，观察规律，可以得到
	//这个矩阵保存的值的依赖关系为：
	//第一行的每一个值都依赖于其左下角的值
	//最后一行的每一个值都依赖于其左上角的值
	//常规行的每一个值都依赖于其左上和左下的值的和
	//这个矩阵的第一列的每一个值都可以直接得到，所以可以根据第一列推算得到后面的每一列
	//第一列只有dp[aim][0]，第aim行第0列（代表终点位置）为1（代表当前位置cur为aim，剩余步数rest为0，很明显剩余步数为0时cur位置刚好在aim时才有1个唯一方法到达aim）
	int ways3(int N, int start, int aim, int rest)
	{
		if (N < 2 || start < 1 || aim<1 || aim>N || rest<1 || start>N)
		{
			cout << "无效参数" << endl;
			return -1;
		}

		vector<int> temp(rest + 1, 0);	//存储列元素
		vector<vector<int>> dp(N + 1, temp);	//存储行元素,第0行和第N+1行没有使用
		dp[aim][0] = 1;

		for (int i = 1; i < rest+1; i++)
		{
			dp[1][i] = dp[2][i - 1];	//第一行的每一个值都依赖于左下角的值,手动赋值
			for (int cur = 2; cur < N; cur++)
			{
				dp[cur][i] = dp[cur - 1][i - 1] + dp[cur + 1][i - 1];
			}
			dp[N][i] = dp[N - 1][i - 1];	//最后一行的每一个值都依赖于其左上角的值,手动赋值
		}


		return dp[start][rest];
	}








	void testDemo() {
		cout << "假设有排成一行的N个位置，记为1~N，N一定大于或等于2" << endl;
		cout << "开始时机器人在其中的M位置上(M一定是1~N中的一个)" << endl;
		cout << "如果机器人来到1位置，那么下一步只能往右来到2位置;" << endl;
		cout << "如果机器人来到N位置，那么下一步只能往左来到N-1位置;" << endl;
		cout << "如果机器人来到中间位置，那么下一步可以往左走或者往右走;" << endl;
		cout << "规定机器人必须走K步，最终能来到P位置(P也是1~N中的一个)的方法有多少种" << endl;
		cout << "给定四个参数N、M、K、P，返回方法数。" << endl;

		
		cout << ways1(4,2,4,4) << endl;
		cout << ways2(4, 2, 4, 4) << endl;
		cout << ways3(4, 2, 4, 4) << endl;



	}
};



