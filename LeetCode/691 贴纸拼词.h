#pragma once
#include "../Solution.h"

/***题目介绍***
给定一个字符串str，给定一个字符串类型的数组arc，出现的字符都是小写英文
arr每一个字符串，代表一张贴纸，你可以把单个字符剪开使用，
目的是拼出str来返回需要至少多少张贴纸可以完成这个任务。
例子∶str= "babac", arr = {"ba" , "c","abcd"]
至少需要两张贴纸"ha"和"abcd"，因为使用这两张贴纸，
把每一个字符单独剪开，含有2个a、2个b、1个c。是可以拼出str的。所以返回3。
*/


class Solution691 : public Solution {
public:
	int minStickers(vector<string>& stickers, string target) {
		int ans = process1(stickers, target);
		return ans == INT_MAX ? -1 : ans;
	}

	int process1(vector<string>& stickers, string target)
	{
		if (target.empty())
			return 0;
		int minMeth = INT_MAX;
		for (string first:stickers)
		{
			string rest = minus(target, first);		
			if (rest.size() != target.size())
				minMeth = min(minMeth, process1(stickers, rest));
		}
		return minMeth + (minMeth == INT_MAX ? 0 : 1);
	}

	/// <summary>
	/// 用一张贴纸尝试去拼写，返回一个被这张贴纸拼好的字符串
	/// 不一定是完整的目标字符串
	/// </summary>
	/// <param name="s1"></param>
	/// <param name="s2"></param>
	/// <returns></returns>
	string minus(string& s1, string& s2)
	{
		int count[26] = {};
		for (char c : s1)
			count[c - 'a']++;
		for (char c : s2)
			count[c - 'a']--;
		string temp;
		for (int i = 0; i < 26; i++)
		{
			if(count[i] >0)
				for (int j = 0; j < count[i]; j++)
				{
					temp.push_back((char)(i+'a'));
				}
		}
		return temp;
	}


	int minStickers2(vector<string>& stickers, string target) {
		int N = stickers.size();
		vector<int> temp(26, 0);
		vector<vector<int>> counts(N, temp);
		for (int i = 0; i < N; i++)
		{
			for (char cha : stickers[i])
				counts[i][cha - 'a']++;
		}
		int ans = process2(counts, target);
		return ans == INT_MAX ? -1 : ans;
	}

	//用一个矩阵表示一组字符串，每一行统计一个单词的字母出现频率
	int process2(vector<vector<int>> stickers, string target)
	{
		if (target.empty())
			return 0;
		//对target做字母出现频率的统计
		int tCounts[26] = {};
		for (char c : target)
		{
			tCounts[c - 'a']++;
		}

		int N = stickers.size();
		int minMeth = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			//尝试第一张贴纸
			vector<int> sticker = stickers[i];
			//剪枝，最关键的优化，让包含第一个字符的贴纸先去尝试
			if (sticker[target[0] - 'a'] > 0)
			{
				string temp = "";
				for (int j = 0; j < 26; ++j)
				{
					if (tCounts[j] > 0)
					{
						int nums = tCounts[j] - sticker[j];		//减掉拼好的字符
						for (int k = 0; k < nums; ++k)
						{
							temp.push_back((char)(j + 'a'));
						}
					}
				}
				minMeth = min(minMeth, process2(stickers, temp));
			}
		}
		return minMeth + (minMeth == INT_MAX ? 0 : 1);
	}


	int minStickers3(vector<string>& stickers, string target) {
		int N = stickers.size();
		vector<int> temp(26, 0);
		vector<vector<int>> counts(N, temp);
		unordered_map<string, int> dp;
		dp[""] = 0;		//如果没有字符，那么就返回0
		for (int i = 0; i < N; ++i)
		{
			for (char cha : stickers[i])
				counts[i][cha - 'a']++;
		}
		int ans = process3(counts, target, dp);
		return ans == INT_MAX ? -1 : ans;
	}

	int process3(vector<vector<int>>& stickers, string target, unordered_map<string, int>& dp)
	{
		if (dp.count(target))
		{
			return dp[target];
		}
		//对target做字母出现频率的统计
		vector<int> tCounts(26,0);
		for (char c : target)
		{
			tCounts[c - 'a']++;
		}

		int N = stickers.size();
		int minMeth = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			//尝试第一张贴纸
			//剪枝，最关键的优化，让包含第一个字符的贴纸先去尝试
			if (stickers[i][target[0] - 'a'] > 0)
			{
				string temp = "";
				for (int j = 0; j < 26; ++j)
				{
					if (tCounts[j] > 0)
					{
						int nums = tCounts[j] - stickers[i][j];		//减掉拼好的字符
						for (int k = 0; k < nums; ++k)
							temp += (char)(j + 'a');
					}
				}
				minMeth = min(minMeth, process3(stickers, temp, dp));
			}
		}
		dp[target] = minMeth + (minMeth == INT_MAX ? 0 : 1);
		return dp[target];
	}


	int minStickers4(vector<string>& stickers, string target) {
		int stickersSize = stickers.size();
		unordered_map<string, int> strStickerCnt;//strStickerCnt[str]表示的字符串str需要的最少贴纸数量
		vector<vector<int>> myStickers(stickersSize, vector<int>(26, 0));//各个贴纸中各个字母出现的次数
		//统计每一个sticker中各个字符出现的次数
		for (int i = 0; i < stickersSize; ++i) {
			for (char ch : stickers[i]) {
				myStickers[i][ch - 'a'] += 1;
			}
		}
		strStickerCnt[""] = 0;//初始化，空字符串不需要贴纸
		return dfs(strStickerCnt, myStickers, target);
	}

	//搜索拼凑target需要的最少贴纸数量
	int dfs(unordered_map<string, int>& strStickerCnt, vector<vector<int>>& myStickers, string target) {
		if (strStickerCnt.count(target)) {
			//如果target已经搜索过，直接返回
			return strStickerCnt[target];
		}
		int minRes = INT_MAX, stickersSize = myStickers.size();
		//统计target中各个字符出现的次数
		vector<int> tar(26, 0);
		for (char ch : target) {
			tar[ch - 'a'] += 1;
		}
		//尝试使用每一个sticker
		for (int i = 0; i < stickersSize; ++i) {
			//如果当前sticker中没有target[0]这个字符则剪枝
			if (myStickers[i][target[0] - 'a'] == 0) {
				continue;
			}
			//使用当前sticker，nowTarget为运用贴纸后剩余的字母
			string nowTarget = "";
			for (int j = 0; j < 26; j++) {
				if (tar[j] - myStickers[i][j] > 0) {
					nowTarget += string(tar[j] - myStickers[i][j], 'a' + j);
				}
			}
			//搜索nowTarget字符串需要最少贴纸数
			int tempRes = dfs(strStickerCnt, myStickers, nowTarget);
			//更新target字符串需要的最少贴纸数
			if (tempRes != -1) {
				minRes = min(minRes, 1 + tempRes);
			}
		}
		strStickerCnt[target] = (minRes == INT_MAX ? -1 : minRes);//标记target已经搜索过
		return strStickerCnt[target];
	}

	void testDemo() override {
		cout << "给定一个字符串str，给定一个字符串类型的数组arc，出现的字符都是小写英文" << endl;
		cout << "arr每一个字符串，代表一张贴纸，你可以把单个字符剪开使用，" << endl;
		cout << "目的是拼出str来返回需要至少多少张贴纸可以完成这个任务。" << endl;
		cout << "例子∶str= \"babac\", arr = {\"ba\" , \"c\",\"abcd\"]" << endl;
		cout << "至少需要两张贴纸\"ha\"和\"abcd\"，因为使用这两张贴纸，" << endl;
		cout << "把每一个字符单独剪开，含有2个a、2个b、1个c。是可以拼出str的。所以返回2。" << endl;


		vector<string> str;
		str.push_back("slave");
		str.push_back("doctor");
		str.push_back("insect");
		str.push_back("an");
		str.push_back("window");
		str.push_back("she");
		str.push_back("range");
		str.push_back("post");
		str.push_back("guide");
		string t = "supportclose";

		cout << minStickers(str, t) << endl;
		cout << minStickers2(str, t) << endl;
		cout << minStickers3(str, t) << endl;
		cout << minStickers4(str, t) << endl;
	}
};



