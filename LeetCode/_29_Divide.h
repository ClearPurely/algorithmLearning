/***题目介绍***
// 29 不用任何算术运算，只用位运算实现加减乘除
// 代码实现中你找不到任何一个算术运算符
// 测试链接 : https://leetcode.cn/problems/divide-two-integers/

*/
#pragma once
#include "../Solution.h"

class _29_Divide : public Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == INT_MIN)
			return 1;
		if (dividend != INT_MIN && divisor != INT_MIN)
			return div(dividend, divisor);
		if (divisor == INT_MIN)
			return 0;
		// a是整数最小，b是-1，返回整数最大，因为题目里明确这么说了
		if (divisor == neg(1))
			return INT_MAX;
		dividend = add(dividend, divisor > 0 ? divisor : neg(divisor));
		int ans = div(dividend, divisor);
		int offset = divisor > 0 ? neg(1) : 1;
		return add(ans, offset);
	}

	// 必须保证a和b都不是整数最小值，返回a除以b的结果
	int div(int a, int b) {
		int x = a < 0 ? neg(a) : a;
		int y = b < 0 ? neg(b) : b;
		int ans = 0;
		for (int i = 30; i >= 0; i = minus(i, 1))
		{
			if ((x >> i) >= y)
			{
				ans |= (1 << i);
				x = minus(x, y << i);
			}
		}
		return (a < 0) ^ (b < 0) ? neg(ans) : ans;
	}

	//两数相加
	int add(int a, int b)
	{
		int ans = a;
		while (b != 0)
		{
			ans = a ^ b;			//无进位相加，每步加上进位信息
			b = (a & b) << 1;		//进位信息
			a = ans;
		}
		return ans;
	}

	//两数相减
	int minus(int a, int b)
	{
		return add(a, neg(b));
	}

	//对一个数变负数
	int neg(int a)
	{
		return add(~a, 1);
	}

	int multiply(int a, int b)
	{
		int ans = 0;
		while (b != 0)
		{
			if ((b & 1) != 0)
			{
				ans = add(ans, a);
			}
			a <<= 1;
			b >>= 1;
		}
		return ans;
	}

	void testDemo() override {
		int a, b;
		cout << "请输入两个数，然后计算前者除以后者的结果" << endl;
		cin >> a;
		cin >> b;
		cout << "正常计算的结果是：" << a / b << endl;
		cout << "位运算计算的结果是：" << divide(a, b) << endl;
	}
};