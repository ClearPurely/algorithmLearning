#pragma once
#include "../Solution.h"

/***题目介绍***
给定一个整型数组arr，代表数值不同的纸牌排成一条线
玩家A和玩家B依次拿走每张纸牌
规定玩家A先拿，玩家B后拿
但是每个玩家每次只能拿走最左或最右的纸牌
玩家A和玩家B都绝顶聪明
请返回最后获胜者的分数。
*/


class SolutionZP : public Solution {
public:
	int win1(vector<int> arr)
	{
		if (arr.empty())
			return -1;

		clock_t start = clock();
		int first = f1(arr, 0, arr.size() - 1);
		int second = g1(arr, 0, arr.size() - 1);
		getFuncExcTime(start);

		if (first > second)
		{
			cout << "先手获胜,分数为：" << first << endl;
			return first;
		}
		else if (first < second)
		{
			cout << "后手获胜,分数为：" << second << endl;
			return second;
		}
		else
		{
			cout << "平局,分数为：" << first << endl;
			return first;
		}
	}

	//先手情况进行选择
	int f1(vector<int> arr, int L, int R)
	{
		if (L == R)
			return arr[L];
		int p1 = arr[L] + g1(arr, L + 1, R);
		int p2 = arr[R] + g1(arr, L, R - 1);
		return max(p1, p2);
	}

	//后手情况进行选择
	int g1(vector<int> arr, int L, int R)
	{
		if (L == R)
			return 0;
		int p1 = f1(arr, L + 1, R);
		int p2 = f1(arr, L, R - 1);
		return min(p1, p2);
	}

	int win2(vector<int> arr)
	{
		if (arr.empty())
			return -1;

		int N = arr.size();
		vector<int> temp(N, -1);
		vector<vector<int>> fmap(N, temp);
		vector<vector<int>> gmap(N, temp);

		clock_t start = clock();
		int first = f2(arr, 0, arr.size() - 1, fmap, gmap);
		int second = g2(arr, 0, arr.size() - 1, fmap, gmap);
		getFuncExcTime(start);

		if (first > second)
		{
			cout << "先手获胜,分数为：" << first << endl;
		}
		else if (first < second)
		{
			cout << "后手获胜,分数为：" << second << endl;
		}
		else
		{
			cout << "平局,分数为：" << first << endl;
		}
	}

	//先手情况进行选择
	int f2(vector<int> arr, int L, int R, vector<vector<int>> fmap, vector<vector<int>> gmap)
	{
		if (fmap[L][R] != -1)
		{
			return fmap[L][R];
		}
		int ans = 0;
		if (L == R)
			ans = arr[L];
		else
		{
			int p1 = arr[L] + g2(arr, L + 1, R, fmap, gmap);
			int p2 = arr[R] + g2(arr, L, R - 1, fmap, gmap);
			ans = max(p1, p2);
		}
		return ans;
	}

	//后手情况进行选择
	int g2(vector<int> arr, int L, int R, vector<vector<int>> fmap, vector<vector<int>> gmap)
	{
		if (gmap[L][R] != -1)
		{
			return gmap[L][R];
		}
		int ans = 0;
		if (L != R)
		{
			int p1 = f2(arr, L + 1, R, fmap, gmap);
			int p2 = f2(arr, L, R - 1, fmap, gmap);
			ans = min(p1, p2);
		}
		return ans;
	}

	int win3(vector<int> arr)
	{
		if (arr.empty())
			return -1;

		int N = arr.size();
		vector<int> temp(N, -1);
		vector<vector<int>> fmap(N, temp);
		vector<vector<int>> gmap(N, temp);

		clock_t start = clock();
		for (int i = 0; i < arr.size(); i++)
		{
			fmap[i][i] = arr[i];
			gmap[i][i] = 0;
		}
		for (int startCol = 1; startCol < N; startCol++)
		{
			int L = 0;	//row
			int R = startCol;	//col
			while (R < N)
			{
				fmap[L][R] = max((arr[L] + gmap[L + 1][R]), (arr[R] + gmap[L][R - 1]));
				gmap[L][R] = min(fmap[L + 1][R], fmap[L][R - 1]);
				L++;
				R++;
			}
		}
		getFuncExcTime(start);
		if (fmap[0][N - 1] > gmap[0][N - 1])
		{
			cout << "先手获胜,分数为：" << fmap[0][N - 1] << endl;
		}
		else if (fmap[0][N - 1] < gmap[0][N - 1])
		{
			cout << "后手获胜,分数为：" << gmap[0][N - 1] << endl;
		}
		else
		{
			cout << "平局,分数为：" << fmap[0][N - 1] << endl;
		}
		return max(fmap[0][N - 1], gmap[0][N - 1]);
	}


	void testDemo() override {
		cout << "给定一个整型数组arr，代表数值不同的纸牌排成一条线" << endl;
		cout << "玩家A和玩家B依次拿走每张纸牌" << endl;
		cout << "规定玩家A先拿，玩家B后拿" << endl;
		cout << "但是每个玩家每次只能拿走最左或最右的纸牌" << endl;
		cout << "玩家A和玩家B都绝顶聪明" << endl;
		cout << "请返回最后获胜者的分数。" << endl;

		vector<int> sample = randomArray1(20, 10, false);
		for (int num : sample)
		{
			cout << num << endl;
		}
		win1(sample);
		win2(sample);
		win3(sample);
	}
};



