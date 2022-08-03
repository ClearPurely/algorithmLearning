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
��ͬѧ������������������һ����������̣�
Ȼ����������̷����һ���ޣ����̵������½���(0,0)λ��
��ô�������̾��Ǻ�������9���ߡ���������10���ߵ�����
������������x, y, k
���ء�����(O.0)λ�ó�����������k��
�������(x.y)�ϵķ������ж�����?
*/


class Solution {
public:
	int jump(int a, int b, int k, int x = 0, int y = 0)
	{
		return process(x, y, k, a, b);
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="x" ��ǰ����λ�õ�x����></param>
	/// <param name="y" ��ǰ����λ�õ�y����></param>
	/// <param name="rest" ��ʣ����></param>
	/// <param name="a" Ŀ����x����></param>
	/// <param name="b" Ŀ����y����></param>
	/// <returns></returns>
	int process(int x, int y, int rest, int a, int b)
	{
		//Ŀ����ǰλ��Խ��
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
		//k+1��ʾҪ����һ����ʼλ��״̬
		vector<vector<vector<int>>> dp(10, vector<vector<int>>(9, vector<int>(k + 1, 0)));
		dp[a][b][0] = 1;	//��ʼ��Ŀ���λ�ã������ߵ����
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


	void testDemo() {
		cout << "��ͬѧ������������������һ����������̣�" << endl;
		cout << "Ȼ����������̷����һ���ޣ����̵������½���(0,0)λ��" << endl;
		cout << "��ô�������̾��Ǻ�������9���ߡ���������10���ߵ�����" << endl;
		cout << "������������x, y, k" << endl;
		cout << "���ء�����(O.0)λ�ó�����������k��" << endl;
		cout << "�������(x.y)�ϵķ������ж�����?" << endl;
		int x = 7;
		int y = 7;
		int step = 10;
		cout << jump(x, y, step) << endl;
		cout << jump2(x, y, step) << endl;

	}
};



