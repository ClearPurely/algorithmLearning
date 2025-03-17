/*************
作者：ClearPurely
项目名：对数器
描述：记录一些生成随机数的方法，用于带入进行计算
创建日期：2025.1.20
最后更新日期：2025.2.7
****************/
#pragma once
#include<iostream>		//	输入输出打印
#include<vector>		//向量
#include<map>			//	图
#include <unordered_map>	//字典
#include <queue>		//队列
#include<math.h>	//	数学库
#include<stack>
#include <cstdlib>   // 包含 rand() 函数所需的头文件
#include <ctime>     // 用于种植随机种子的库
#include <unordered_set>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <random>

using namespace std;

// 生成一个随机数，范围在1到max之间
int randomNum(int max);

// 生成 min 到 max 之间（包含 min 和 max）的随机数(使用random的高级方法)
int randomNum1(int min, int max);

/// <summary>
/// 获取一个函数的运行时间
/// </summary>
/// <param name="start">函数开始时间</param>
/// <param name="isPrint">是否打印运行时间</param>
/// <returns>函数运行时间（秒）</returns>
double getFuncExcTime(std::clock_t start, bool isPrint = true);

/// 打印一个数的二进制表示
void printBinary(int num);

/// 打印一个数组的所有值
void printArray(const std::vector<int>& arr);

/// 打印一个矩阵的所有值
void printMatrix(const std::vector<std::vector<int>>& mat);

/// <summary>
// 生成一个包含n个随机数的数组，每个数在1到v之间
/// </summary>
/// <param name="n">数组的长度</param>
/// <param name="v">随机数的最大值</param>
/// <returns>生成的数组</returns>
std::vector<int> randomArray(int n, int v);

/// <summary>
/// 生成一个随机正数组成的数组
/// </summary>
/// <param name="len">数组的最大长度</param>
/// <param name="max">随机数的最大值</param>
/// <param name="isSorted">是否对数组进行排序</param>
/// <returns>生成的数组</returns>
std::vector<int> randomArray1(int maxLen, int max, bool isSorted = true);

/// <summary>
/// 生成一个随机数组成的数组，可能包含正数和负数
/// </summary>
/// <param name="len">数组的最大长度</param>
/// <param name="max">随机数的最大值</param>
/// <param name="isSorted">是否对数组进行排序</param>
/// <returns>生成的数组</returns>
std::vector<int> randomArray2(int maxLen, int max, bool isSorted);

/// <summary>
/// 生成一个随机字符串，只包含指定字符
/// </summary>
/// <param name="maxLen">字符串的最大长度</param>
/// <param name="exaction">指定的字符集合</param>
/// <returns>生成的字符串</returns>
std::string randomString(int maxLen, const std::string& exaction = "GB");

/// 拷贝一个数组并返回新数组
std::vector<int> copyArray(const std::vector<int>& source);

/// 验证两个数组是否相同
bool sameArray(const std::vector<int>& arr1, const std::vector<int>& arr2);
