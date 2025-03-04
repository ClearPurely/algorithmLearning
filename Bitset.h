// 2166 位图的实现
// 位图是可以存储一窜连续的数的数据结构
// Bitset是一种能以紧凑形式存储位的数据结构
// 测试链接 : https://leetcode-cn.com/problems/design-bitset/
#pragma once
#include<vector>		//向量
#include <string>
using namespace std;

class Bitset
{
private:
	vector<int> saveSet;
	int size;
	int zeros;
	int ones;
	bool reverse;

public:
	// 用 size 个位初始化 Bitset ，所有位都是 0
	Bitset(int n);

	// 将下标为idx的位上的值更新为1。如果值已经是1，则不会发生任何改变。
	void fix(int i);

	// 将下标为idx的位上的值更新为0。如果值已经是0，则不会发生任何改变。
	void unfix(int i);

	//翻转 Bitset 中每一位上的值。换句话说，所有值为 0 的位将会变成 1 ，反之亦然。
	void flip();

	//检查 Bitset 中 每一位 的值是否都是 1 。如果满足此条件，返回 true ；否则，返回 false 。
	bool all();

	//检查 Bitset 中 是否 至少一位 的值是 1 。如果满足此条件，返回 true ；否则，返回 false 。
	bool one();

	//返回 Bitset 中值为 1 的位的 总数 。
	int count();

	//返回 Bitset 的当前组成情况。注意，在结果字符串中，第 i 个下标处的字符应该与 Bitset 中的第 i 位一致。
	string toString();

	//反转一个数在位图中的状态
	void reverseNum(int i);

	//判断位图中是否包含这个数
	bool contains(int i);
};

