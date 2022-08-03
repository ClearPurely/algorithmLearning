#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include <queue>

#include"../DataGenerator.h"

using namespace std;

/***��Ŀ����***
����һ������arr��arr[i]�����i�ſ��Ȼ���һ�����ȵ�ʱ��
����һ������N����ʾN���˵��ſ��Ȼ��ݿ��ȣ�ÿ̨���Ȼ�ֻ�������ݿ���
ֻ��һ̨ϴ���ȱ��Ļ�����һ��ֻ��ϴһ�����ӣ�ʱ��ķ�a��ϴ�����ϴ��һ��
ÿ�����ȱ�Ҳ�����Լ��ӷ��ɾ���ʱ��ķ�b�����ȱ����Բ��лӷ�
�����������õ�����֮�����̺ȸɾ���
���شӿ�ʼ�ȵ����п��Ȼ���ɾ������ʱ��
��������:int[arr��int N, int a��int b
*/


class Solution {
public:
	class Machine
	{
	public:
		int timePoint;
		int workTime;

		Machine(int t, int w)
		{
			timePoint = t;
			workTime = w;
		}

		bool operator>(const Machine& a) const
		{
			return (this->timePoint + this->workTime) > a.timePoint + a.workTime;
		}

		bool operator<(const Machine& a) const
		{
			return (this->timePoint + this->workTime) < a.timePoint + a.workTime;
		}	

	};

	int MinTime(vector<int> arr,int n,int a,int b)
	{
		priority_queue<Machine, vector<Machine>, greater<Machine>> heap;
		for (int i = 0; i < arr.size(); i++)
		{
			heap.push(Machine(0, arr[i]));
		}

		vector<int> drinks(n, 0);		//ÿ���Ŷӵ����õ����ȵ�ʱ���
		for (int i = 0; i < n; i++)
		{
			Machine cur(heap.top().timePoint + heap.top().workTime, heap.top().workTime);
			heap.pop();
			drinks[i] = cur.timePoint;
			heap.push(cur);
		}
		printArray(drinks);

		return bestTime(drinks, a, b, 0, 0);
	}

	/// <summary>
	/// ���б��ӱ�ɾ�������¼�
	/// </summary>
	/// <param name="drinks" ÿ�����ӿ�ʼϴ��ʱ��㣬�̶����� ></param>
	/// <param name="wash" ϴ���ӵĻ���ϴһ������������¼����̶����� ></param>
	/// <param name="air" �����Լ��ӷ��ɾ������ʱ�䣬�̶����� ></param>
	/// <param name="index" ϴ���ڼ������� ></param>
	/// <param name="free" ϴ�Ļ�����ʱ���� ></param>
	/// <returns></returns>
	int bestTime(vector<int>& drinks, int& wash, int& air, int index, int free)
	{
		if (index == drinks.size())
			return 0;
		//����ϴ���ӵ����
		//Ҫ�����б��Ӷ�ϴ��,��Ϊ���Դ��ű��Ӳ�ϴ�Ȼӷ���
		//����������Ӻ�ʱϴ�� ȡ���� ��ǰ����ϴ���ʱ�� �� �¸�����ϴ���ʱ�� ȡ���
		int selfClean1 = max(drinks[index], free) + wash;	
		int restClean1 = bestTime(drinks, wash, air, index + 1, selfClean1);
		int p1 = max(selfClean1, restClean1);
		//�����ӷ������
		int selfClean2 = drinks[index] + air;
		int restClean2 = bestTime(drinks, wash, air, index + 1, free);
		int p2 = max(selfClean2, restClean2);

		return min(p1, p2);
	}

	int MinTime2(vector<int> arr, int n, int a, int b)
	{
		priority_queue<Machine, vector<Machine>, greater<Machine>> heap;
		for (int i = 0; i < arr.size(); i++)
		{
			heap.push(Machine(0, arr[i]));
		}

		vector<int> drinks(n, 0);		//ÿ���Ŷӵ����õ����ȵ�ʱ���
		for (int i = 0; i < n; i++)
		{
			Machine cur(heap.top().timePoint + heap.top().workTime, heap.top().workTime);
			heap.pop();
			drinks[i] = cur.timePoint;
			heap.push(cur);
		}
		printArray(drinks);

		return bestTimeDp(drinks, a, b);
	}

	int bestTimeDp(vector<int>& drinks, int& wash, int& air)
	{
		int N = drinks.size();
		int maxFree = 0;
		for (int i = 0; i < drinks.size(); i++)
		{
			maxFree = max(maxFree, drinks[i]) + wash;	//���б��Ӷ�ȥϴ��������
		}

		//�д���ڼ������е����ֵ���������������б���ϴ���ʱ��㣬�Ա�������ÿ��ʱ��㶼�п���ϴ������
		vector<vector<int>> dp(N + 1, vector<int>(maxFree + 1, 0));

		//�����һ����ʼ����
		for (int index = N-1; index >= 0 ; --index)
		{
			for (int free = 0; free <= maxFree; ++free)
			{
				//��ǰ�������ϴ���ʱ��ȡ������һ�����Ӻ����ʱ��+ϴ��ʱ��
				int selfClean1 = max(drinks[index], free) + wash;	
				if (selfClean1 > maxFree)	//�����ܳ���������
					continue;
				int restClean1 = dp[index + 1][selfClean1];
				//���ϴ���ӣ���ǰ����ϴ�ɾ���ʱ�� �� �ϸ�����ϴ���ʱ�� ȡ ���
				int p1 = max(selfClean1, restClean1);

				int selfClean2 = drinks[index] + air;
				int restClean2 = dp[index + 1][free];
				int p2 = max(selfClean2, restClean2);
				dp[index][free] = min(p1, p2);
			}
		}
		printMatrix(dp);
		return dp[0][0];
	}

	void testDemo() {
		cout << "����һ������arr��arr[i]�����i�ſ��Ȼ���һ�����ȵ�ʱ��" << endl;
		cout << "����һ������N����ʾN���˵��ſ��Ȼ��ݿ��ȣ�ÿ̨���Ȼ�ֻ�������ݿ���" << endl;
		cout << "ֻ��һ̨���Ȼ���һ��ֻ��ϴһ�����ӣ�ʱ��ķ�a��ϴ�����ϴ��һ��" << endl;
		cout << "ÿ�����ȱ�Ҳ�����Լ��ӷ��ɾ���ʱ��ķ�b�����ȱ����Բ��лӷ�" << endl;
		cout << "�����������õ�����֮�����̺ȸɾ���" << endl;
		cout << "���شӿ�ʼ�ȵ����п��Ȼ���ɾ������ʱ��" << endl;
		cout << "��������:int[arr��int N, int a��int b" << endl;


		DataGenerator data;
		vector<int> arr = data.generateArray(5, 9);
		int n = data.RadomNum(5);
		int a = data.RadomNum(5);
		int b = data.RadomNum(10);

		printArray(arr);
		cout << n << "����  " << a << "����ϴ����  " << b << "���ӻӷ��ɾ�  " << endl;
		cout << MinTime(arr, n, a, b) << endl;
		cout << MinTime2(arr, n, a, b) << endl;
	}
};



