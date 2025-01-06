#pragma once
#include "../Solution.h"

/***题目介绍***
请同学们自行搜索或者想象一个象棋的棋盘，
然后把整个棋盘放入第一象限，棋盘的最左下角是(0,0)位置
那么整个棋盘就是横坐标上9条线、纵坐标上10条线的区域
给你三个参数x, y, k
返回“马”从(O.0)位置出发，必须走k步
最后落在(x.y)上的方法数有多少种?
*/


class SolutionGJXQ : public Solution {
public:
	int jump(int a, int b, int k, int x = 0, int y = 0)
	{
		return process(x, y, k, a, b);
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="x" 当前所处位置的x坐标></param>
	/// <param name="y" 当前所处位置的y坐标></param>
	/// <param name="rest" 还剩几步></param>
	/// <param name="a" 目标点的x坐标></param>
	/// <param name="b" 目标点的y坐标></param>
	/// <returns></returns>
	int process(int x, int y, int rest, int a, int b)
	{
		//目标点或当前位置越界
		if (x < 0 || x> 9 || y < 0 || y > 8 || a < 0 || a> 9 || b < 0 || b > 8)
			return 0;
		if (rest == 0)
			return (x == a && y == b) ? 1 : 0;
		int ways = process(x + 2, y + 1, rest - 1, a, b);
		ways += process(x + 1, y + 2, rest - 1, a, b);
		ways += process(x - 1, y + 2, rest - 1, a, b);
		ways += process(x - 2, y + 1, rest - 1, a, b);
		ways += process(x - 2, y - 1, rest - 1, a, b);
		ways += process(x - 1, y - 2, rest - 1, a, b);
		ways += process(x + 1, y - 2, rest - 1, a, b);
		ways += process(x + 2, y - 1, rest - 1, a, b);
		return ways;
	}


	int jump2(int a, int b, int k, int i = 0, int j = 0)
	{
		//k+1表示要包含一个初始位置状态
		vector<vector<vector<int>>> dp(10, vector<vector<int>>(9, vector<int>(k + 1, 0)));
		dp[a][b][0] = 1;	//初始化目标点位置，倒着走到起点
		for (int rest = 1; rest <= k; rest++)	
		{
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 9; y++)
				{

					int ways = pick(dp, x + 2, y + 1, rest - 1);
					ways += pick(dp, x + 1, y + 2, rest - 1);
					ways += pick(dp, x - 1, y + 2, rest - 1);
					ways += pick(dp, x - 2, y + 1, rest - 1);
					ways += pick(dp, x - 2, y - 1, rest - 1);
					ways += pick(dp, x - 1, y - 2, rest - 1);
					ways += pick(dp, x + 1, y - 2, rest - 1);
					ways += pick(dp, x + 2, y - 1, rest - 1);
					dp[x][y][rest] = ways;
				}
			}
		}
		return dp[i][j][k];
	}

	int pick(vector<vector<vector<int>>>& dp, int x, int y, int rest)
	{
		if (x < 0 || x> 9 || y < 0 || y > 8)
			return 0;
		return dp[x][y][rest];
	}


	void testDemo() override {
		cout << "请同学们自行搜索或者想象一个象棋的棋盘，" << endl;
		cout << "然后把整个棋盘放入第一象限，棋盘的最左下角是(0,0)位置" << endl;
		cout << "那么整个棋盘就是横坐标上9条线、纵坐标上10条线的区域" << endl;
		cout << "给你三个参数x, y, k" << endl;
		cout << "返回“马”从(O.0)位置出发，必须走k步" << endl;
		cout << "最后落在(x.y)上的方法数有多少种?" << endl;
		int x = 7;
		int y = 7;
		int step = 10;
		cout << jump(x, y, step) << endl;
		cout << jump2(x, y, step) << endl;

	}
};



