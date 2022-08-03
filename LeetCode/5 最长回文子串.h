/*
给你一个字符串 s，找到 s 中最长的回文子串。


输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
*/

#pragma once
#include<string>
#include<iostream>
#include<set>
using namespace std;



class Solution {
public:
    string longestPalindrome1(string s) {
        int size = s.size();
        int start = 0, end = size - 1;
        string ret = "";
        for (int i = 0; i < size; i++) {
            for (int j = size-1; j >= i; j--)
            {
                if (s[i] == s[j])
                {
                    cout << j - i + 1<< endl;
                    cout << s.substr(i, j - i + 1) << endl;
                    ret = isPal(s.substr(i, j - i + 1));
                    if (ret.size() > 1)
                    {
                        return ret;
                    }
                }
            }
        }

        return ret;
    }
    
    string isPal(string s) {
        int size = s.size();
        int start = 0, end = size - 1;
        string ret = "";
        set<int> index;

        while (start <= end) {
            cout << start << " " << end << endl;

            if (s[start] == s[end]) {

                index.insert(start);
                index.insert(end);
            }
            else {
                return "";
            }

            ++start;
            --end;
        }

        for (set<int>::iterator it = index.begin(); it != index.end(); it++) {
            int a = *it;
            //string b(1,s.at(a));
            //cout << *it << " ";
            //cout << a << " ";
            //cout << b << " ";
            ret = ret + s.at(a);
        }
        return ret;
    }


    string longestPalindrome(string s)
    {
        if (s.length() < 1)
        {
            return "";
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);//一个元素为中心
            int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {// 计算以left和right为中心的回文串长度
            L--;
            R++;
        }
        return R - L - 1;
    }


    //测试代码
    void testDemo() {
        //string s = "babad";
        string s = "a";
        string ret = longestPalindrome(s);

        cout << ret << endl;

    }
};