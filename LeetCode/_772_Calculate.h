/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 772 含有嵌套的表达式求值
/// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
/// </summary>
class _772_Calculate : public Solution {
	int where;
public:
	int calculate(string str) {
		where = 0;
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		return f(str, 0);
	}

	// s[i....]开始计算，遇到字符串终止 或者 遇到)停止
	// 返回 : 自己负责的这一段，计算的结果
	// 返回之间，更新全局变量where，为了上游函数知道从哪继续！
	int f(string& s, int i) {
		int cur = 0;
		vector<int> numbers;
		vector<char> ops;
		while (i < s.size() && s[i] != ')') {
			if (s[i] >= '0' && s[i] <= '9') {
				cur = cur * 10 + (s[i++] - '0');	//这里不加括号遇到最大整数输入时会报错
			}
			else if (s[i] != '(') {
				// 遇到了运算符 + - * /
				push(numbers, ops, cur, s[i++]);
				cur = 0;
			}
			else {
				// i (.....)
				// 遇到了左括号！
				cur = f(s, i + 1);
				i = where + 1;
			}
		}
		push(numbers, ops, cur, '+');
		where = i;
		return compute(numbers, ops);
	}

	void push(vector<int>& numbers, vector<char>& ops, int cur, char op) {
		int n = (int)numbers.size();
		if (n == 0 || ops[n - 1] == '+' || ops[n - 1] == '-') {
			numbers.push_back(cur);
			ops.push_back(op);
		}
		else {
			int topNumber = numbers[n - 1];
			char topOp = ops[n - 1];
			if (topOp == '*') {
				numbers[n - 1] = topNumber * cur;
			}
			else {
				numbers[n - 1] = topNumber / cur;
			}
			ops[n - 1] = op;
		}
	}

	int compute(vector<int>& numbers, vector<char>& ops) {
		int n = (int)numbers.size();
		int ans = numbers[0];
		for (int i = 1; i < n; i++) {
			ans += ops[i - 1] == '+' ? numbers[i] : -numbers[i];
		}
		return ans;
	}
	
	void testDemo() override {
		string expression = "2147483647";
		int result = calculate(expression);
		cout << "expression: " << "2147483647" << endl;
		cout << "Result: " << result << endl;
	}
};