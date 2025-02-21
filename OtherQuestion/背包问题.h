#pragma once
#include "../Solution.h"

/***��Ŀ����***
��N�����ÿ�����������������ͼ�ֵ������������
һ���ʾ���л������������һ���ʾ���л��������
��һ������������װbag����λ�����Ļ��
����������װ�¼�ֵ���Ļ��
*/


class SolutionBB : public Solution {
public:
	int maxValue(vector<int> w, vector<int> v, int bag)
	{
		if (w.empty() || v.empty() || w.size() != v.size() || w.size() == 0)
		{
			return 0;
		}
		cout << process1(w, v, 0, bag) << endl;
	}

	//��ǰ���ǵ���index�Ż��index��������ѡ��
	//�������ܳ���bag
	int process1(vector<int> w, vector<int> v, int index,int bag)
	{
		if (bag < 0)
			return -1;
		if (index == w.size())
			return 0;
		//indexû�����˵�����л����bag���пռ�
		int p1 = process1(w, v, index + 1, bag);		//��Ҫ��ǰ�Ļ���
		int p2 = 0;
		int next = process1(w, v, index + 1, bag - w[index]);
		if (next != -1)		//�ж����ѡȡ�Ƿ���Ч
		{
			p2 = v[index] + next;	//Ҫ��ǰ�Ļ���
		}
		
		return max(p1, p2);
	}

	//��̬�滮
	int dp(vector<int> w, vector<int> v, int bag)
	{
		if (w.empty() || v.empty() || w.size() != v.size() || w.size() == 0)
		{
			return 0;
		}
		int N = w.size();
		vector<int> temp(bag + 1, 0);
		vector<vector<int>> dp(N + 1, temp);
		for (int index = N-1; index >= 0; index--)
		{
			for (int rest = 0; rest <= bag; rest++)
			{
				int p1 = dp[index + 1][rest];
				int p2 = 0;
				int next = rest - w[index] < 0 ? -1 : dp[index + 1][rest - w[index]];
				if (next != -1)		//�ж����ѡȡ�Ƿ���Ч
				{
					p2 = v[index] + next;	//Ҫ��ǰ�Ļ���
				}
				dp[index][rest] = max(p1, p2);
			}

		}
		return dp[0][bag];	//����bag����װ��ʱ
	}


	void testDemo() override{
		cout << "��һ�ѻ��ÿ�����������������ͼ�ֵ������������" << endl;
		cout << "һ���ʾ���л������������һ���ʾ���л��������" << endl;
		cout << "��һ������������װbag����λ�����Ļ��" << endl;
		cout << "����������װ�¼�ֵ���Ļ��" << endl;

		int bag = randomNum(50);
		vector<int> w;
		vector<int> v;
		//cout << bag << endl;
		//int N = DataGenerator().RadomNum(20);
		//for (int i = 0; i < N; i++)
		//{
		//	Sleep(100);
		//	int weigh = DataGenerator().RadomNum(11);
		//	w.push_back(weigh);
		//	int value = DataGenerator().RadomNum(12);
		//	v.push_back(value);
		//	cout << weigh << "  " << value << endl;
		//}

		bag = 15;
		w.push_back(3);
		w.push_back(2);
		w.push_back(4);
		w.push_back(7);
		w.push_back(3);
		w.push_back(1);
		w.push_back(7);

		v.push_back(5);
		v.push_back(6);
		v.push_back(3);
		v.push_back(19);
		v.push_back(12);
		v.push_back(4);
		v.push_back(2);
	
		maxValue(w, v, bag);
		cout << dp(w, v, bag) << endl;

	}
};



