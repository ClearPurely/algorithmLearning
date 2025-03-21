/*************
作者：ClearPurely
说明：这个文件的方法是为了应对ACM风格的题目做出的代码编写
创建日期：2025.1.13
最后更新日期：2025.1.13
****************/
#pragma once
#include <functional>
#include<iostream>		//	输入输出打印
#include<vector>		//向量

using namespace std;

//定义一个 可传入一个整数，返回值void的函数 类型
typedef function<void(int)> MyIntProcessFun;

//定义一个 可传入一个数组，返回值void的函数 类型
typedef function<void(vector<int>&)> MyArrayProcessFun;

//定义一个 可传入一个二维数组参数，返回值void的函数 类型
typedef function<void(vector<vector<int>>&)> MyMatrixProcessFun;

//读取一个矩阵文件数据，并用传入的函数对其进行处理
//该文件格式应符合如下示例：一个2行2列的矩阵，元素分别是9，10，13，14
//2 2
//9 10
//13 14
void processInputMatrix(const MyMatrixProcessFun& func);

//处理一行一行的输入，对单个整数进行处理
//输入距离，该文件有两行：
//10 11 12
//13 50 60
void processInputLineNum(const MyIntProcessFun& func);

//处理输入数组，输入举例：一个长度5的数组，分别是4 2 4 5 1
//5
//4 2 4 5 1
void processInputArray(const MyArrayProcessFun& func);