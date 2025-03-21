/***题目介绍***
// 一个正整数如果能被 a 或 b 整除，那么它是神奇的。
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。
// 因为答案可能很大，所以返回答案 对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/nth-magical-number/
*/
#pragma once
#include "../Solution.h"

//878. 第 N 个神奇数字
class _878_NthMagicalNumber : public Solution {
private:

public:
	int nthMagicalNumber(int n, int a, int b) {
		long long lcmNum = lcm(a, b);
		long long ans = 0;
		// l = 0
		// r = (long long) n * Math.min(a, b)
		// l......r
		for (long long l = 0, r = (long long)n * min(a, b), m = 0; l <= r;) {
			m = (l + r) / 2;
			// 1....m
			if (m / a + m / b - m / lcmNum >= n) {
				ans = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		return (int)(ans % 1000000007);
	}

	long long gcd(long long a, long long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	long long lcm(long long a, long long b) {
		return (long long)a / gcd(a, b) * b;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};