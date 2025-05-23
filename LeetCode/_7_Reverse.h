﻿#pragma once
#include "../Solution.h"

/// <summary>
/// 7 整数反转
/// 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
/// 如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。
/// 假设环境不允许存储 64 位整数（有符号或无符号）。
/// 输入：x = -123
/// 输出： - 321
/// </summary>
class _7_Reverse : public Solution {
public:
	int reverse(int x) {
		{
			int rev = 0;
			while (x != 0) {
				if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
					return 0;
				}
				int digit = x % 10;
				x /= 10;
				rev = rev * 10 + digit;
			}
			return rev;
		}
	}

	//测试代码
	void testDemo() override {
	}

};
