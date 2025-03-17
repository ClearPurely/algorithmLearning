/***题目介绍***
收录一些与位运算有关的leetcode题目
*/
#pragma once
#include "../Solution.h"

class BitwiseOperationSolution : public Solution {
public:
	// 268 找到缺失的数字
	// 测试链接 : https://leetcode.cn/problems/missing-number/
	int missingNumber(vector<int>& nums);

	// 136 数组中1种数出现了奇数次，其他的数都出现了偶数次
	// 返回出现了奇数次的数
	// 测试链接 : https://leetcode.cn/problems/single-number/
	int singleNumber(vector<int>& nums);

	// 137 数组中只有1种数出现次数少于m次，其他数都出现了m次
	// 返回出现次数小于m次的那种数
	// 测试链接 : https://leetcode.cn/problems/single-number-ii/
	// 注意 : 测试题目只是通用方法的一个特例，这里实现的是更通用的情况
	// 已知数组中只有1种数出现次数少于m次，其他数都出现了m次
	// 返回出现次数小于m次的那种数
	int singleNumber2(vector<int>& nums, int m);

	// 260 数组中有2种数出现了奇数次，其他的数都出现了偶数次
	// 返回这2种出现了奇数次的数
	// 测试链接 : https://leetcode.cn/problems/single-number-iii/
	vector<int> singleNumber3(vector<int>& nums);

	// 231 判断一个整数是不是2的幂
	// Brian Kernighan算法
	// 提取出二进制里最右侧的1
	// 测试链接 : https://leetcode.cn/problems/power-of-two/
	bool isPowerOfTwo(int n);

	// 326 判断一个整数是不是3的幂
	// 测试链接 : https://leetcode.cn/problems/power-of-three/
	// 如果一个数字是3的某次幂，那么这个数一定只含有3这个质数因子
	// 1162261467是int型范围内，最大的3的幂，它是3的19次方
	// 这个1162261467只含有3这个质数因子，如果n也是只含有3这个质数因子，那么
	// 1162261467 % n == 0
	// 反之如果1162261467 % n != 0 说明n一定含有其他因子
	bool isPowerOfThree(int n);

	// 201 给你两个整数 left 和 right ，表示区间 [left, right]
	// 返回此区间内所有数字 & 的结果
	// 包含 left 、right 端点
	// 测试链接 : https://leetcode.cn/problems/bitwise-and-of-numbers-range/
	// 我自己的理解，无论这个区间有多少个数，因为他是与操作，其实与的结果本质上就是这些数在二进制上时有多少个1能留下来
	int rangeBitwiseAnd(int left, int right);

	// 190 逆序二进制的状态
	// 测试链接 : https://leetcode.cn/problems/reverse-bits/
	uint32_t reverseBits(uint32_t n);

	// 461 返回n的二进制中有几个1
	// 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
	// 给你两个整数 x 和 y，计算并返回它们之间的汉明距离
	// 测试链接 : https://leetcode.cn/problems/hamming-distance/
	int hammingDistance(int x, int y);

	void testDemo() override {
		cout << "" << endl;
	}
};