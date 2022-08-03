#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include <unordered_map>
#include<vector>
#include <random>
#include"../DataGenerator.h"

using namespace std;

/***题目介绍***
现有司机N*2人，调度中心会将所有司机平分给A、B两个区域
第i个司机去A可得收入为income[i][0],
第i个司机去B可得收入为income[i][1],
返回所有调度方案中能使所有司机总收入最高的方案，是多少钱

假设有排成一行的N个位置，记为1~N，N一定大于或等于2
开始时机器人在其中的M位置上(M一定是1~N中的一个)
如果机器人来到1位置，那么下一步只能往右来到2位置;
如果机器人来到N位置，那么下一步只能往左来到N-1位置;
如果机器人来到中间位置，那么下一步可以往左走或者往右走;
规定机器人必须走K步，最终能来到P位置(P也是1~N中的一个)的方法有多少种
给定四个参数N、M、K、P，返回方法数。
*/


class Solution {
public:
	Solution()
	{
	}





	void testDemo() {
		cout << "现有司机N*2人，调度中心会将所有司机平分给A、B两个区域" << endl;
		cout << "第i个司机去A可得收入为income[i][0]," << endl;
		cout << "第i个司机去B可得收入为income[i][1]," << endl;
		cout << "返回所有调度方案中能使所有司机总收入最高的方案，是多少钱？" << endl;



	}
};



