#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include <random>

using namespace std;


/// <summary>
/// 获取一个函数的运行时间
/// </summary>
/// <param name="start"></param>
/// <param name="isPrint"></param>
/// <returns></returns>
double getFuncExcTime(clock_t start,bool isPrint = true)
{
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	if(isPrint)
		cout << "Function is running in " << duration << "s" << endl;
	return duration;
}

/// <summary>
/// 打印一个数组的所有值
/// </summary>
/// <param name="arr"></param>
void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

/// <summary>
/// 打印一个矩阵的所有值
/// </summary>
/// <param name="mat"></param>
void printMatrix(vector<vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
}

class DataGenerator {
public:
	DataGenerator() 
	{
		srand(time(NULL));
	}

	int RadomNum(int max)
	{
		return (rand() % max + 1);
	}

	/// <summary>
	/// 生成随机正数组成的数组
	/// </summary>
	/// <param name="len"></param>
	/// <param name="max"></param>
	/// <param name="isSorted"></param>
	/// <returns></returns>
	vector<int> static generateArray(int maxLen, int max, bool isSorted = true) {
		vector<int> ans((rand() % maxLen) + 1);
		for (int i = 0; i < ans.size(); i++) {
			ans[i] = (int)((rand() % max) + 1);
		}
		if (isSorted)
			sort(ans.begin(), ans.end());
		return ans;
	}

	/// <summary>
	/// 生成随机正数组成的数组
	/// </summary>
	/// <param name="len"></param>
	/// <param name="max"></param>
	/// <param name="isSorted"></param>
	/// <returns></returns>
	vector<int> static generateArray2(int maxLen, int max, bool isSorted) {
		vector<int> ans((rand() % maxLen) + 1);
		for (int i = 0; i < ans.size(); i++) {
			int temp = (int)((rand() % max) + 1);
			ans[i] = (rand() % (999 + 1) / (float)(999 + 1)) < 0.5 ? temp : -temp;
		}
		if (isSorted)
			sort(ans.begin(), ans.end());
		return ans;
	}

	/// <summary>
	/// 生成随机字符串,可以指定只包含一些指定字符
	/// </summary>
	/// <param name="maxLen"></param>
	/// <param name="exaction"></param>
	/// <returns></returns>
	string randomString(int maxLen, string exaction = "GB") {
		string str((rand() % maxLen) + 1, 'G');
		for (int i = 0; i < str.size(); i++) {
			str[i] = exaction.at(rand() % exaction.size());
		}
		return str;
	}
};



