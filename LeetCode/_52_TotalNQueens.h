/***题目介绍***
n 皇后问题研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数n，返回n皇后问题不同的解决方案的数量。
*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 52 N皇后问题
/// 测试链接 : https://leetcode.cn/problems/n-queens-ii/
/// </summary>
class _52_TotalNQueens : public Solution {
private:

public:
	// 用数组表示路径实现的N皇后问题，不推荐
	int totalNQueens1(int n) {
		if (n < 1) {
			return 0;
		}
		return f1(0, vector<int>(n), n);
	}

	// i : 当前来到的行
	// path : 0...i-1行的皇后，都摆在了哪些列 例如path[1][1]表示该皇后摆在第二行第二列
	// n : 是几皇后问题
	// 返回 : 0...i-1行已经摆完了，i....n-1行可以去尝试的情况下还能找到几种有效的方法
	int f1(int i, vector<int> path, int n) {
		if (i == n) {
			return 1;
		}
		int ans = 0;
		// 0 1 2 3 .. n-1
		// i j
		for (int j = 0; j < n; j++) {
			if (check(path, i, j)) {
				path[i] = j;
				ans += f1(i + 1, path, n);
			}
		}
		return ans;
	}

	// 当前在i行、j列的位置，摆了一个皇后
	// 0...i-1行的皇后状况，path[0...i-1]
	// 返回会不会冲突，不会冲突，有效！true
	// 会冲突，无效，返回false
	bool check(vector<int> path, int i, int j) {
		// 当前 i
		// 当列 j
		for (int k = 0; k < i; k++) {
			// 0...i-1
			// 之前行 : k
			// 之前列 : path[k]
			//检查是否同列，不用检查是否同行，因为递归规避了同行的可能性
			if (j == path[k] || abs(i - k) == abs(j - path[k])) {	
				return false;
			}
		}
		return true;
	}

	int totalNQueens(int n) {
		if (n < 1 || n > 32)
			return 0;
		int limit = n == 32 ? -1 : (1 << n) - 1;		//有n个皇后就让这个限制的二进制的右n-1位全为1
		return make2(limit, 0, 0, 0);
	}

	int make2(const int& limit, int colLim, int L_Lim, int R_Lim)
	{
		if (colLim == limit)		//表示所有行都放了皇后
			return 1;
		int mostRightOne = 0;

		//取反是为了把限制为limit的左侧多余的数给截断
		//剩下所有可选放皇后的位置都在pos上
		// pos : 1可放皇后，0不能放
		int pos = limit & (~(colLim | L_Lim | R_Lim));

		int res = 0;
		while (pos != 0)
		{
			mostRightOne = pos & -pos;	//取出最右侧的1，也可以写成pos & (~pos+1),一个数的负数就该数取反+1
			pos ^= mostRightOne;		//尝试把皇后摆在最右侧1的这个位置上，也可以写成pos -= mostRightOne;
			res += make2(limit, colLim | mostRightOne, (L_Lim | mostRightOne) << 1, (R_Lim | mostRightOne) >> 1);
		}
		return res;
	}

	void testDemo() override {
		cout << "N皇后问题" << endl;
		cout << "请输入皇后的数量：" << endl;
		int n;
		cin >> n;
		if (n <= 9)
			cout << "最终得出有" << totalNQueens1(n) << "种解决方案" << endl;
		else
			cout << "最终得出有" << totalNQueens(n) << "种解决方案" << endl;

	}
};