#pragma once
#include "BitwiseOperationSolution.h"

int BitwiseOperationSolution::missingNumber(vector<int>& nums) {
	int eorAll = 0, eorHas = 0;
	for (int i = 0; i < nums.size(); i++) {
		eorAll ^= i;
		eorHas ^= nums[i];
	}
	eorAll ^= nums.size();
	return eorAll ^ eorHas;
}

int BitwiseOperationSolution::singleNumber(vector<int>& nums) {
	int eor = 0;
	for (int num : nums) {
		eor ^= num;
	}
	return eor;
}

int BitwiseOperationSolution::singleNumber2(vector<int>& nums, int m = 3) {
	// cnts[0] : 0位上有多少个1
	// cnts[i] : i位上有多少个1
	// cnts[31] : 31位上有多少个1
	vector<int> cnts(32, 0);
	for (int num : nums) {
		for (int i = 0; i < 32; i++) {
			cnts[i] += (num >> i) & 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		//如果当前这个位数上统计的1出现的次数 对m取余!=0 那就说明这位上是1
		if (cnts[i] % m != 0) {
			ans |= 1 << i;
		}
	}
	return ans;
}

vector<int> BitwiseOperationSolution::singleNumber3(vector<int>& nums) {
	int eor1 = 0;
	for (int num : nums) {
		// nums中有2种数a、b出现了奇数次，其他的数都出现了偶数次
		eor1 ^= num;
	}
	// eor1 = a ^ b
	// Brian Kernighan算法
	// 提取出二进制里最右侧的1
	int rightOne;
	if (eor1 == INT_MIN) {
		// 当 eor1 等于 INT_MIN 时，直接赋值
		rightOne = INT_MIN;
	}
	else {
		// 正常情况，计算最右侧的 1
		rightOne = eor1 & (-eor1);
	}
	int eor2 = 0;
	for (int num : nums) {
		if ((num & rightOne) == 0) {
			eor2 ^= num;
		}
	}
	return { eor2, eor1 ^ eor2 };
}

//00000100 & 11111100 = 00000100
bool BitwiseOperationSolution::isPowerOfTwo(int n) {
	return n > 0 && n == (n & -n);
}

bool BitwiseOperationSolution::isPowerOfThree(int n) {
	return n > 0 && 1162261467 % n == 0;

	//while (n && n % 3 == 0) {
	//	n /= 3;
	//}
	//return n == 1;
}

int BitwiseOperationSolution::rangeBitwiseAnd(int left, int right) {
	while (left < right)
	{
		right -= (right & -right);
		//right = right & (right - 1);	//这样写也行
	}
	return right;
}

uint32_t BitwiseOperationSolution::reverseBits(uint32_t n) {
	n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
	n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
	n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
	n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
	n = (n >> 16) | (n << 16);
	return n;
}

int BitwiseOperationSolution::hammingDistance(int x, int y) {
	int n = x ^ y;
	// 返回n的二进制中有几个1
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);		// 统计2进制上32位分割成每组长度为2上统计1的数量(01)
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);		// 统计2进制上32位分割成每组长度为4上统计1的数量(0011)
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);		// 统计2进制上32位分割成每组长度为8上统计1的数量(00001111)
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);		// 统计2进制上32位分割成每组长度为16上统计1的数量(0000000011111111)
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);	// 统计2进制上32位分割成每组长度为32上统计1的数量(00000000000000001111111111111111)
	return n;
}