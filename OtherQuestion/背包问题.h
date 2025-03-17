#pragma once
#include "../Solution.h"

/// <summary>
/// 有N个货物，每个货物有它的重量和价值，有两个数组
/// 一组表示所有货物的重量，另一组表示所有货物的重量
/// 有一个背包，可以装bag个单位重量的货物，
/// 问怎样可以装下价值最多的货物。
/// </summary>
class SolutionBB : public Solution {
public:
	int maxValue(vector<int> w, vector<int> v, int bag)
	{
		if (w.empty() || v.empty() || w.size() != v.size() || w.size() == 0)
		{
			return 0;
		}
		cout << process1(w, v, 0, bag) << endl;
	}

	//当前考虑到了index号货物，index可以自由选择
	//重量不能超过bag
	int process1(vector<int> w, vector<int> v, int index,int bag)
	{
		if (bag < 0)
			return -1;
		if (index == w.size())
			return 0;
		//index没到最后，说明还有货物，且bag还有空间
		int p1 = process1(w, v, index + 1, bag);		//不要当前的货物
		int p2 = 0;
		int next = process1(w, v, index + 1, bag - w[index]);
		if (next != -1)		//判断这次选取是否有效
		{
			p2 = v[index] + next;	//要当前的货物
		}
		
		return max(p1, p2);
	}

	//动态规划
	int dp(vector<int> w, vector<int> v, int bag)
	{
		if (w.empty() || v.empty() || w.size() != v.size() || w.size() == 0)
		{
			return 0;
		}
		int N = (int)w.size();
		vector<int> temp(bag + 1, 0);
		vector<vector<int>> dp(N + 1, temp);
		for (int index = N-1; index >= 0; index--)
		{
			for (int rest = 0; rest <= bag; rest++)
			{
				int p1 = dp[index + 1][rest];
				int p2 = 0;
				int next = rest - w[index] < 0 ? -1 : dp[index + 1][rest - w[index]];
				if (next != -1)		//判断这次选取是否有效
				{
					p2 = v[index] + next;	//要当前的货物
				}
				dp[index][rest] = max(p1, p2);
			}

		}
		return dp[0][bag];	//代表bag正好装满时
	}


	void testDemo() override{
		cout << "有一堆货物，每个货物有它的重量和价值，有两个数组" << endl;
		cout << "一组表示所有货物的重量，另一组表示所有货物的重量" << endl;
		cout << "有一个背包，可以装bag个单位重量的货物，" << endl;
		cout << "问怎样可以装下价值最多的货物。" << endl;

		int bag = randomNum(50);
		vector<int> w;
		vector<int> v;
		//cout << bag << endl;
		//int N = DataGenerator().RadomNum(20);
		//for (int i = 0; i < N; i++)
		//{
		//	Sleep(100);
		//	int weigh = DataGenerator().RadomNum(11);
		//	w.push_back(weigh);
		//	int value = DataGenerator().RadomNum(12);
		//	v.push_back(value);
		//	cout << weigh << "  " << value << endl;
		//}

		bag = 15;
		w.push_back(3);
		w.push_back(2);
		w.push_back(4);
		w.push_back(7);
		w.push_back(3);
		w.push_back(1);
		w.push_back(7);

		v.push_back(5);
		v.push_back(6);
		v.push_back(3);
		v.push_back(19);
		v.push_back(12);
		v.push_back(4);
		v.push_back(2);
	
		maxValue(w, v, bag);
		cout << dp(w, v, bag) << endl;

	}
};



