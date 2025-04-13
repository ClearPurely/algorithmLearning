/***题目介绍***
// 超级回文数(java版)
// 如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。
// 现在，给定两个正整数 L 和 R （以字符串形式表示），
// 返回包含在范围 [L, R] 中的超级回文数的数目。
// 1 <= len(L) <= 18
// 1 <= len(R) <= 18
// L 和 R 是表示 [1, 10^18) 范围的整数的字符串
//测试链接 : https://leetcode.cn/problems/super-palindromes/
*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 906 超级回文数
/// </summary>
class _906_SuperpalindromesInRange : public Solution {
private:

public:
	/*
	int superpalindromesInRange(string left, string right) {
		long l = std::stoll(left);
		long r = std::stoll(right);
		r = r > LLONG_MAX ? LLONG_MAX : r;
		// l....r  long
		// x根号，范围limit
		long limit = (long)std::sqrt((double)r);
		// seed : 枚举量很小，10^18 -> 10^9 -> 10^5
		// seed : 奇数长度回文、偶数长度回文
		long seed = 1;
		// num : 根号x，num^2 -> x
		long num = 0;
		int ans = 0;
		do {
			//  seed生成偶数长度回文数字
			// 123 -> 123321
			num = evenEnlarge(seed, false);
			if (check(num * num, l, r)) {
				ans++;
			}
			//  seed生成奇数长度回文数字
			// 123 -> 12321
			num = evenEnlarge(seed, true);
			if (check(num * num, l, r)) {
				ans++;
			}
			// 123 -> 124 -> 125
			seed++;
		} while (num < limit);
		return ans;
	}

	long long evenEnlarge(long long seed, bool isOdd) {
		long long ans = seed;
		if(isOdd)
			seed /= 10;
		while (seed != 0) {
			ans = ans * 10 + seed % 10;
			seed /= 10;
		}
		return ans;
	}

	bool check(long long ans, long long l, long long r) {
		return ans >= l && ans <= r && isPalindrome(ans);
	}
	*/

	int superpalindromesInRange(string left, string right) {
		long long l = stoll(left);
		long long r = stoll(right);
		long long limit = (long long)sqrt((double)r) + 1;
		long long seed = 0;
		long long ans = 0;

		do {
			long long even_num = evenEnlarge(seed, false);
			long long odd_num = evenEnlarge(seed, true);

			if (even_num <= limit && check(even_num, l, r)) {
				ans++;
			}
			if (odd_num <= limit && check(odd_num, l, r)) {
				ans++;
			}

			seed++;
		} while (evenEnlarge(seed, true) <= limit);

		return (int)ans;
	}

	//生成一个数的回文数（奇数长度和偶数长度）
	long long evenEnlarge(long long seed, bool isOdd) {
		long long ans = seed;
		if (isOdd) seed /= 10;
		while (seed != 0) {
			ans = ans * 10 + seed % 10;
			seed /= 10;
		}
		return ans;
	}

	bool check(long long num, long long l, long long r) {
		if (num < 0) return false;
		if (num > 0 && num > (LLONG_MAX / num)) {
			return false; // 乘法溢出
		}
		long long square = num * num;
		return square >= l && square <= r && isPalindrome(square);
	}

	// 9 判断一个数字是不是回文数
	// 测试链接 : https://leetcode.cn/problems/palindrome-number/
	bool isPalindrome(long long num) {
		if (num < 0) return false;
		long long reversed = 0, original = num;
		while (num > 0) {
			reversed = reversed * 10 + num % 10;
			num /= 10;
		}
		return original == reversed;
	}

	bool isPalindrome1(long long num) {
		if (num < 0)
			return false;
		long long offset = 1;
		while (num / offset >= 10)
			offset *= 10;
		while (num != 0)
		{
			if (num / offset != num % 10)
				return false;
			num = (num % offset) / 10;	//123%100/10=2	3%10/10 当消耗位数<=1时
			offset /= 100;
		}
		return true;
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << superpalindromesInRange("1", "5") << endl;
	}
};