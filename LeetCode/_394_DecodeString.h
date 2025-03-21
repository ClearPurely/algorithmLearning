/***题目介绍***

*/
#pragma once
#include "../Solution.h"

/// <summary>
/// 394 含有嵌套的字符串解码
/// 测试链接 : https://leetcode.cn/problems/decode-string/
/// </summary>
class _394_DecodeString : public Solution {
private:
	int where;
public:
	string decodeString(string str) {
		where = 0;
		return f(str, 0);
	}

	// s[i....]开始计算，遇到字符串终止 或者 遇到 ] 停止
	// 返回 : 自己负责的这一段字符串的结果
	// 返回之间，更新全局变量where，为了上游函数知道从哪继续！
	string f(const string& s, int i) {
		stringstream path;
		int cnt = 0;
		while (i < (int)s.size() && s[i] != ']') {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				path << s[i++];
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				cnt = cnt * 10 + s[i++] - '0';
			}
			else {
				// 遇到 [ 
				// cnt = 7 * ? 
				path << get(cnt, f(s, i + 1));
				i = where + 1;
				cnt = 0;
			}
		}
		where = i;
		return path.str();
	}

	string get(int cnt, const string& str) {
		stringstream builder;
		for (int i = 0; i < cnt; i++) {
			builder << str;
		}
		return builder.str();
	}

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
};