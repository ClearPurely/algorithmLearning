//用向量实现小根堆
#pragma once
#include<vector>		//向量
#include <random>
using namespace std;

class MyHeap
{
private:
	vector<int> heap;
public:
	MyHeap();

	MyHeap(vector<int> arr);

	void add(int x);

	void pop();

	int top();

	int size();
};