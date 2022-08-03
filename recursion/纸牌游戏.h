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
����һ����������arr��������ֵ��ͬ��ֽ���ų�һ����
���A�����B��������ÿ��ֽ��
�涨���A���ã����B����
����ÿ�����ÿ��ֻ��������������ҵ�ֽ��
���A�����B����������
�뷵������ʤ�ߵķ�����
*/


class Solution {
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
			cout << "���ֻ�ʤ,����Ϊ��" << first << endl;
			return first;
		}
		else if (first < second)
		{
			cout << "���ֻ�ʤ,����Ϊ��" << second << endl;
			return second;
		}
		else
		{
			cout << "ƽ��,����Ϊ��" << first << endl;
			return first;
		}
	}

	//�����������ѡ��
	int f1(vector<int> arr, int L, int R)
	{
		if (L == R)
			return arr[L];
		int p1 = arr[L] + g1(arr, L + 1, R);
		int p2 = arr[R] + g1(arr, L, R - 1);
		return max(p1, p2);
	}

	//�����������ѡ��
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
			cout << "���ֻ�ʤ,����Ϊ��" << first << endl;
		}
		else if (first < second)
		{
			cout << "���ֻ�ʤ,����Ϊ��" << second << endl;
		}
		else
		{
			cout << "ƽ��,����Ϊ��" << first << endl;
		}
	}

	//�����������ѡ��
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

	//�����������ѡ��
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
			cout << "���ֻ�ʤ,����Ϊ��" << fmap[0][N - 1] << endl;
		}
		else if (fmap[0][N - 1] < gmap[0][N - 1])
		{
			cout << "���ֻ�ʤ,����Ϊ��" << gmap[0][N - 1] << endl;
		}
		else
		{
			cout << "ƽ��,����Ϊ��" << fmap[0][N - 1] << endl;
		}
		return max(fmap[0][N - 1], gmap[0][N - 1]);
	}


	void testDemo() {
		cout << "����һ����������arr��������ֵ��ͬ��ֽ���ų�һ����" << endl;
		cout << "���A�����B��������ÿ��ֽ��" << endl;
		cout << "�涨���A���ã����B����" << endl;
		cout << "����ÿ�����ÿ��ֻ��������������ҵ�ֽ��" << endl;
		cout << "���A�����B����������" << endl;
		cout << "�뷵������ʤ�ߵķ�����" << endl;

		vector<int> sample = DataGenerator().generateArray(20, 10, false);
		for (int num : sample)
		{
			cout << num << endl;
		}
		win1(sample);
		win2(sample);
		win3(sample);
	}
};



