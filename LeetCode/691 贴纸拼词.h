#pragma once
#include "../Solution.h"

/***��Ŀ����***
����һ���ַ���str������һ���ַ������͵�����arc�����ֵ��ַ�����СдӢ��
arrÿһ���ַ���������һ����ֽ������԰ѵ����ַ�����ʹ�ã�
Ŀ����ƴ��str��������Ҫ���ٶ�������ֽ��������������
���ӡ�str= "babac", arr = {"ba" , "c","abcd"]
������Ҫ������ֽ"ha"��"abcd"����Ϊʹ����������ֽ��
��ÿһ���ַ���������������2��a��2��b��1��c���ǿ���ƴ��str�ġ����Է���3��
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
	/// ��һ����ֽ����ȥƴд������һ����������ֽƴ�õ��ַ���
	/// ��һ����������Ŀ���ַ���
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

	//��һ�������ʾһ���ַ�����ÿһ��ͳ��һ�����ʵ���ĸ����Ƶ��
	int process2(vector<vector<int>> stickers, string target)
	{
		if (target.empty())
			return 0;
		//��target����ĸ����Ƶ�ʵ�ͳ��
		int tCounts[26] = {};
		for (char c : target)
		{
			tCounts[c - 'a']++;
		}

		int N = stickers.size();
		int minMeth = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			//���Ե�һ����ֽ
			vector<int> sticker = stickers[i];
			//��֦����ؼ����Ż����ð�����һ���ַ�����ֽ��ȥ����
			if (sticker[target[0] - 'a'] > 0)
			{
				string temp = "";
				for (int j = 0; j < 26; ++j)
				{
					if (tCounts[j] > 0)
					{
						int nums = tCounts[j] - sticker[j];		//����ƴ�õ��ַ�
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
		dp[""] = 0;		//���û���ַ�����ô�ͷ���0
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
		//��target����ĸ����Ƶ�ʵ�ͳ��
		vector<int> tCounts(26,0);
		for (char c : target)
		{
			tCounts[c - 'a']++;
		}

		int N = stickers.size();
		int minMeth = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			//���Ե�һ����ֽ
			//��֦����ؼ����Ż����ð�����һ���ַ�����ֽ��ȥ����
			if (stickers[i][target[0] - 'a'] > 0)
			{
				string temp = "";
				for (int j = 0; j < 26; ++j)
				{
					if (tCounts[j] > 0)
					{
						int nums = tCounts[j] - stickers[i][j];		//����ƴ�õ��ַ�
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
		unordered_map<string, int> strStickerCnt;//strStickerCnt[str]��ʾ���ַ���str��Ҫ��������ֽ����
		vector<vector<int>> myStickers(stickersSize, vector<int>(26, 0));//������ֽ�и�����ĸ���ֵĴ���
		//ͳ��ÿһ��sticker�и����ַ����ֵĴ���
		for (int i = 0; i < stickersSize; ++i) {
			for (char ch : stickers[i]) {
				myStickers[i][ch - 'a'] += 1;
			}
		}
		strStickerCnt[""] = 0;//��ʼ�������ַ�������Ҫ��ֽ
		return dfs(strStickerCnt, myStickers, target);
	}

	//����ƴ��target��Ҫ��������ֽ����
	int dfs(unordered_map<string, int>& strStickerCnt, vector<vector<int>>& myStickers, string target) {
		if (strStickerCnt.count(target)) {
			//���target�Ѿ���������ֱ�ӷ���
			return strStickerCnt[target];
		}
		int minRes = INT_MAX, stickersSize = myStickers.size();
		//ͳ��target�и����ַ����ֵĴ���
		vector<int> tar(26, 0);
		for (char ch : target) {
			tar[ch - 'a'] += 1;
		}
		//����ʹ��ÿһ��sticker
		for (int i = 0; i < stickersSize; ++i) {
			//�����ǰsticker��û��target[0]����ַ����֦
			if (myStickers[i][target[0] - 'a'] == 0) {
				continue;
			}
			//ʹ�õ�ǰsticker��nowTargetΪ������ֽ��ʣ�����ĸ
			string nowTarget = "";
			for (int j = 0; j < 26; j++) {
				if (tar[j] - myStickers[i][j] > 0) {
					nowTarget += string(tar[j] - myStickers[i][j], 'a' + j);
				}
			}
			//����nowTarget�ַ�����Ҫ������ֽ��
			int tempRes = dfs(strStickerCnt, myStickers, nowTarget);
			//����target�ַ�����Ҫ��������ֽ��
			if (tempRes != -1) {
				minRes = min(minRes, 1 + tempRes);
			}
		}
		strStickerCnt[target] = (minRes == INT_MAX ? -1 : minRes);//���target�Ѿ�������
		return strStickerCnt[target];
	}

	void testDemo() override {
		cout << "����һ���ַ���str������һ���ַ������͵�����arc�����ֵ��ַ�����СдӢ��" << endl;
		cout << "arrÿһ���ַ���������һ����ֽ������԰ѵ����ַ�����ʹ�ã�" << endl;
		cout << "Ŀ����ƴ��str��������Ҫ���ٶ�������ֽ��������������" << endl;
		cout << "���ӡ�str= \"babac\", arr = {\"ba\" , \"c\",\"abcd\"]" << endl;
		cout << "������Ҫ������ֽ\"ha\"��\"abcd\"����Ϊʹ����������ֽ��" << endl;
		cout << "��ÿһ���ַ���������������2��a��2��b��1��c���ǿ���ƴ��str�ġ����Է���2��" << endl;


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



