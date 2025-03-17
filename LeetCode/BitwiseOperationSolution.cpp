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
	// cnts[0] : 0λ���ж��ٸ�1
	// cnts[i] : iλ���ж��ٸ�1
	// cnts[31] : 31λ���ж��ٸ�1
	vector<int> cnts(32, 0);
	for (int num : nums) {
		for (int i = 0; i < 32; i++) {
			cnts[i] += (num >> i) & 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		//�����ǰ���λ����ͳ�Ƶ�1���ֵĴ��� ��mȡ��!=0 �Ǿ�˵����λ����1
		if (cnts[i] % m != 0) {
			ans |= 1 << i;
		}
	}
	return ans;
}

vector<int> BitwiseOperationSolution::singleNumber3(vector<int>& nums) {
	int eor1 = 0;
	for (int num : nums) {
		// nums����2����a��b�����������Σ�����������������ż����
		eor1 ^= num;
	}
	// eor1 = a ^ b
	// Brian Kernighan�㷨
	// ��ȡ�������������Ҳ��1
	int rightOne;
	if (eor1 == INT_MIN) {
		// �� eor1 ���� INT_MIN ʱ��ֱ�Ӹ�ֵ
		rightOne = INT_MIN;
	}
	else {
		// ����������������Ҳ�� 1
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
		//right = right & (right - 1);	//����дҲ��
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
	// ����n�Ķ��������м���1
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);		// ͳ��2������32λ�ָ��ÿ�鳤��Ϊ2��ͳ��1������(01)
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);		// ͳ��2������32λ�ָ��ÿ�鳤��Ϊ4��ͳ��1������(0011)
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);		// ͳ��2������32λ�ָ��ÿ�鳤��Ϊ8��ͳ��1������(00001111)
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);		// ͳ��2������32λ�ָ��ÿ�鳤��Ϊ16��ͳ��1������(0000000011111111)
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);	// ͳ��2������32λ�ָ��ÿ�鳤��Ϊ32��ͳ��1������(00000000000000001111111111111111)
	return n;
}