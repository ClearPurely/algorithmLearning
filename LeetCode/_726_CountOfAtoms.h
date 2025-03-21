/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary> 
/// 726 含有嵌套的分子式求原子数量
/// 测试链接 : https://leetcode.cn/problems/number-of-atoms/
/// </summary>
class _726_CountOfAtoms : public Solution {
private:
	int where;
public:
	string countOfAtoms(string str) {
		where = 0;
		map<string, int> cnt_map = f(str, 0);
		stringstream ans;
		for (const auto& pair : cnt_map) {
			ans << pair.first;
			if (pair.second > 1) {
				ans << pair.second;
			}
		}
		return ans.str();
	}

	// s[i....]开始计算，遇到字符串终止 或者 遇到 ) 停止
	// 返回 : 自己负责的这一段字符串的结果，有序表！
	// 返回之间，更新全局变量where，为了上游函数知道从哪继续！
	map<string, int> f(string& s, int i) {
		// ans是总表
		map<string, int> ans;
		// 之前收集到的名字，历史一部分
		string name;
		// 之前收集到的有序表，历史一部分
		map<string, int> pre;
		// 历史翻几倍
		int cnt = 0;
		while (i < s.size() && s[i] != ')') {
			if ((s[i] >= 'A' && s[i] <= 'Z') || s[i] == '(') {
				fill(ans, name, pre, cnt);
				name.clear();
				pre.clear();
				cnt = 0;
				if (s[i] == '(') {
					pre = f(s, i + 1);
					i = where + 1;
				}
				else {
					name += s[i++];
				}
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				name += s[i++];
			}
			else {
				cnt = cnt * 10 + (s[i++] - '0');
			}
		}
		fill(ans, name, pre, cnt);
		where = i;
		return ans;
	}

	void fill(map<string, int>& ans, const string& name, const map<string, int>& pre, int cnt) {
		if (name.empty() && pre.empty()) return;
		cnt = cnt ? cnt : 1;
		if (!name.empty()) {
			ans[name] += cnt;
		}
		else {
			for (const auto& pair : pre) {
				ans[pair.first] += pair.second * cnt;
			}
		}
	}

	void testDemo() override {
		string test = "K4(ON(SO3)2)2";
		cout << "输入：" << "K4(ON(SO3)2)2" << endl;
		cout << "输出：" << endl;
		cout << countOfAtoms(test) << endl;
	}
};