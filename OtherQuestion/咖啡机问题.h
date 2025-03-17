#pragma once
#include "../Solution.h"

/// <summary>
/// 给定一个数组arr，arr[i]代表第i号咖啡机泡一杯咖啡的时间
/// 给定一个正数N，表示N个人等着咖啡机泡咖啡，每台咖啡机只能轮流泡咖啡
/// 只有一台洗咖啡杯的机器，一次只能洗一个杯子，时间耗费a，洗完才能洗下一杯
/// 每个咖啡杯也可以自己挥发干净，时间耗费b，咖啡杯可以并行挥发
/// 假设所有人拿到咖啡之后立刻喝干净，
/// 返回从开始等到所有咖啡机变干净的最短时间
/// 三个参数 : int[arr、int N, int a、int b
/// </summary>
class SolutionKFJ : public Solution {
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

		vector<int> drinks(n, 0);		//每个排队的人拿到咖啡的时间点
		for (int i = 0; i < n; i++)
		{
			Machine cur(heap.top().timePoint + heap.top().workTime, heap.top().workTime);
			heap.pop();
			drinks[i] = cur.timePoint;
			heap.push(cur);
		}
		//printArray(drinks);

		return bestTime(drinks, a, b, 0, 0);
	}

	/// <summary>
	/// 所有杯子变干净所需的事件
	/// </summary>
	/// <param name="drinks" 每个杯子开始洗的时间点，固定变量 ></param>
	/// <param name="wash" 洗杯子的机器洗一个被子所需的事件，固定变量 ></param>
	/// <param name="air" 杯子自己挥发干净所需的时间，固定变量 ></param>
	/// <param name="index" 洗到第几个杯子 ></param>
	/// <param name="free" 洗的机器何时可用 ></param>
	/// <returns></returns>
	int bestTime(vector<int>& drinks, int& wash, int& air, int index, int free)
	{
		if (index == drinks.size())
			return 0;
		//决定洗杯子的情况
		//要让所有杯子都洗完,因为可以存着被子不洗等挥发，
		//所以这个杯子何时洗完 取决于 当前杯子洗完的时间 和 下个杯子洗完的时间 取最大
		int selfClean1 = max(drinks[index], free) + wash;	
		int restClean1 = bestTime(drinks, wash, air, index + 1, selfClean1);
		int p1 = max(selfClean1, restClean1);
		//决定挥发的情况
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

		vector<int> drinks(n, 0);		//每个排队的人拿到咖啡的时间点
		for (int i = 0; i < n; i++)
		{
			Machine cur(heap.top().timePoint + heap.top().workTime, heap.top().workTime);
			heap.pop();
			drinks[i] = cur.timePoint;
			heap.push(cur);
		}
		//printArray(drinks);

		return bestTimeDp(drinks, a, b);
	}

	int bestTimeDp(vector<int>& drinks, int& wash, int& air)
	{
		int N = (int)drinks.size();
		int maxFree = 0;
		for (int i = 0; i < drinks.size(); i++)
		{
			maxFree = max(maxFree, drinks[i]) + wash;	//所有杯子都去洗是最差情况
		}

		//行代表第几杯，列的最大值代表最差情况下所有杯子洗完的时间点，以便能囊括每个时间点都有可能洗完的情况
		vector<vector<int>> dp(N + 1, vector<int>(maxFree + 1, 0));

		//从最后一杯开始倒推
		for (int index = N-1; index >= 0 ; --index)
		{
			for (int free = 0; free <= maxFree; ++free)
			{
				//当前这个杯子洗完的时间取决于上一个杯子喝完的时间+洗的时间
				int selfClean1 = max(drinks[index], free) + wash;	
				if (selfClean1 > maxFree)	//不可能超过最差情况
					continue;
				int restClean1 = dp[index + 1][selfClean1];
				//如果洗杯子，当前杯子洗干净的时间 和 上个杯子洗完的时间 取 最大
				int p1 = max(selfClean1, restClean1);

				int selfClean2 = drinks[index] + air;
				int restClean2 = dp[index + 1][free];
				int p2 = max(selfClean2, restClean2);
				dp[index][free] = min(p1, p2);
			}
		}
		//printMatrix(dp);
		return dp[0][0];
	}

	void testDemo() override {
		cout << "给定一个数组arr，arr[i]代表第i号咖啡机泡一杯咖啡的时间" << endl;
		cout << "给定一个正数N，表示N个人等着咖啡机泡咖啡，每台咖啡机只能轮流泡咖啡" << endl;
		cout << "只有一台咖啡机，一次只能洗一个杯子，时间耗费a，洗完才能洗下一杯" << endl;
		cout << "每个咖啡杯也可以自己挥发干净，时间耗费b，咖啡杯可以并行挥发" << endl;
		cout << "假设所有人拿到咖啡之后立刻喝干净，" << endl;
		cout << "返回从开始等到所有咖啡机变干净的最短时间" << endl;
		cout << "三个参数:int[arr、int N, int a、int b" << endl;

		vector<int> arr = randomArray1(5, 9);
		int n = randomNum(5);
		int a = randomNum(5);
		int b = randomNum(10);

		printArray(arr);
		cout << n << "个人  " << a << "分钟洗杯子  " << b << "分钟挥发干净  " << endl;
		cout << MinTime(arr, n, a, b) << endl;
		cout << MinTime2(arr, n, a, b) << endl;
	}
};



