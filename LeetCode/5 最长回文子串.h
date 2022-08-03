/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���


���룺s = "babad"
�����"bab"
���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�
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
            int len1 = expandAroundCenter(s, i, i);//һ��Ԫ��Ϊ����
            int len2 = expandAroundCenter(s, i, i + 1);//����Ԫ��Ϊ����
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
        {// ������left��rightΪ���ĵĻ��Ĵ�����
            L--;
            R++;
        }
        return R - L - 1;
    }


    //���Դ���
    void testDemo() {
        //string s = "babad";
        string s = "a";
        string ret = longestPalindrome(s);

        cout << ret << endl;

    }
};