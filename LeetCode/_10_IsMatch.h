#include "../Solution.h"

/// <summary>
/// 10 正则表达式匹配
/// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
/// '.' 匹配任意单个字符
/// '*' 匹配零个或多个前面的那一个元素
/// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
/// 例子1：
/// 输入：s = "aa" p = "a*"
/// 输出：true
/// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
/// 例子2：
/// 输入：s = "aab" p = "c*a*b"
/// 输出：true
/// 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
/// </summary>
class _10_IsMatch : public Solution {
public:
    //动态规划
    bool isMatch(string s, string p) {
        int m = (int)s.size();
        int n = (int)p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }

    //递归法
    bool isMatch1(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        if ('*' == p[1])
        {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        }
        else
        {
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && (isMatch(s.substr(1), p.substr(1)));
        }
    }

    //测试代码
    void testDemo() override {
        cout << isMatch("abc*bj.j", "abcabcabcbjaj") << endl;
        cout << isMatch("abbbbbb", "ab*") << endl;


    }
};



