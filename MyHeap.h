//������ʵ��С����
#pragma once
#include<vector>		//����
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