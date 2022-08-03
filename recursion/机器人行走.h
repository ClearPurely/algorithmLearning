#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include"../DataGenerator.h"

using namespace std;

/***��Ŀ����***
�������ų�һ�е�N��λ�ã���Ϊ1~N��Nһ�����ڻ����2
��ʼʱ�����������е�Mλ����(Mһ����1~N�е�һ��)
�������������1λ�ã���ô��һ��ֻ����������2λ��;
�������������Nλ�ã���ô��һ��ֻ����������N-1λ��;
��������������м�λ�ã���ô��һ�����������߻���������;
�涨�����˱�����K��������������Pλ��(PҲ��1~N�е�һ��)�ķ����ж�����
�����ĸ�����N��M��K��P�����ط�������
*/


class Solution {
public:
	int ways1(int N, int start, int aim, int rest)
	{
		if (N < 2 || start < 1 || aim<1 || aim>N || rest<1 || start>N)
		{
			cout << "��Ч����" << endl;
			return -1;
		}
		return process1(start,rest,aim,N);
	}

	//�����˵�ǰ������λ����cur,
	//�����˻���rest����Ҫȥ�ߣ����յ�Ŀ����aim,
	//����Щλ�ÿ��Ե���? 1...N��0λ�ò��ɵ��
	//rest���Ǵ����ж��ٲ�������
	//���ةU�����˴�cur�������߹�rest��֮������ͣ��aim�ķ��������Ƕ���?
	int process1(int cur, int rest, int aim, int N)
	{
		if (rest == 0)		//�������������
			return cur == aim ? 1 : 0;
		if (cur == 1)
			return process1(2, rest - 1, aim, N);
		if (cur == N)
			return process1(N - 1, rest - 1, aim, N);
		return process1(cur - 1, rest - 1, aim, N) + process1(cur + 1, rest - 1, aim, N);
	}

	//�Ż�1���ö�̬�滮������֮ǰ����Ĺ��̣�ֱ�ӷ���,Ҳ�м��仯����
	int ways2(int N, int start, int aim, int rest)
	{
		if (N < 2 || start < 1 || aim<1 || aim>N || rest<1 || start>N)
		{
			cout << "��Ч����" << endl;
			return -1;
		}
		vector<int> temp(rest + 1, -1);
		vector<vector<int>> dp(N + 1, temp);
		//dp���ǻ����
		//dp[cur][rest] == -1	->	process1(cur, rest)֮ǰû���!
		//dp[cur][rest] != -1	->	process1(cur, rest)֮ǰ���!����ֵ��dp[cur][rest]
		//N + 1 * K + 1

		return process2(start, rest, aim, N, dp);
	}

	int process2(int cur, int rest, int aim, int N, vector<vector<int>> dp)
	{
		if (dp[cur][rest] != -1)
			return dp[cur][rest];
		//�����һ��֮ǰû���
		int ans = 0;

		if (rest == 0)		//�������������
			ans = cur == aim ? 1 : 0;
		else if (cur == 1)
			ans = process2(2, rest - 1, aim, N,dp);
		else if (cur == N)
			ans = process2(N - 1, rest - 1, aim, N,dp);
		else
			ans = process2(cur - 1, rest - 1, aim, N,dp) + process2(cur + 1, rest - 1, aim, N,dp);
		
		dp[cur][rest] = ans;
		return ans;
	}

	//����״̬ת�ƣ��۲���ɣ����Եõ�
	//������󱣴��ֵ��������ϵΪ��
	//��һ�е�ÿһ��ֵ�������������½ǵ�ֵ
	//���һ�е�ÿһ��ֵ�������������Ͻǵ�ֵ
	//�����е�ÿһ��ֵ�������������Ϻ����µ�ֵ�ĺ�
	//�������ĵ�һ�е�ÿһ��ֵ������ֱ�ӵõ������Կ��Ը��ݵ�һ������õ������ÿһ��
	//��һ��ֻ��dp[aim][0]����aim�е�0�У������յ�λ�ã�Ϊ1������ǰλ��curΪaim��ʣ�ಽ��restΪ0��������ʣ�ಽ��Ϊ0ʱcurλ�øպ���aimʱ����1��Ψһ��������aim��
	int ways3(int N, int start, int aim, int rest)
	{
		if (N < 2 || start < 1 || aim<1 || aim>N || rest<1 || start>N)
		{
			cout << "��Ч����" << endl;
			return -1;
		}

		vector<int> temp(rest + 1, 0);	//�洢��Ԫ��
		vector<vector<int>> dp(N + 1, temp);	//�洢��Ԫ��,��0�к͵�N+1��û��ʹ��
		dp[aim][0] = 1;

		for (int i = 1; i < rest+1; i++)
		{
			dp[1][i] = dp[2][i - 1];	//��һ�е�ÿһ��ֵ�����������½ǵ�ֵ,�ֶ���ֵ
			for (int cur = 2; cur < N; cur++)
			{
				dp[cur][i] = dp[cur - 1][i - 1] + dp[cur + 1][i - 1];
			}
			dp[N][i] = dp[N - 1][i - 1];	//���һ�е�ÿһ��ֵ�������������Ͻǵ�ֵ,�ֶ���ֵ
		}


		return dp[start][rest];
	}








	void testDemo() {
		cout << "�������ų�һ�е�N��λ�ã���Ϊ1~N��Nһ�����ڻ����2" << endl;
		cout << "��ʼʱ�����������е�Mλ����(Mһ����1~N�е�һ��)" << endl;
		cout << "�������������1λ�ã���ô��һ��ֻ����������2λ��;" << endl;
		cout << "�������������Nλ�ã���ô��һ��ֻ����������N-1λ��;" << endl;
		cout << "��������������м�λ�ã���ô��һ�����������߻���������;" << endl;
		cout << "�涨�����˱�����K��������������Pλ��(PҲ��1~N�е�һ��)�ķ����ж�����" << endl;
		cout << "�����ĸ�����N��M��K��P�����ط�������" << endl;

		
		cout << ways1(4,2,4,4) << endl;
		cout << ways2(4, 2, 4, 4) << endl;
		cout << ways3(4, 2, 4, 4) << endl;



	}
};



