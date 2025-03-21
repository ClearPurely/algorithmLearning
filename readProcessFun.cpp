#include"readProcessFun.h"
#include <string>
#include <sstream>

void processInputMatrix(const MyMatrixProcessFun& func)
{
	istream& in = cin;
	// 读取直到文件结束
	while (!in.eof()) {
		// 读取n，二维数组的行数
		int n;
		in >> n;
		// 读取m，二维数组的列数
		int m;
		in >> m;
		// 创建一个n行m列的二维数组
		vector<vector<int>> mat(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				in >> mat[i][j];
			}
		}
		// 使用传入的函数对整个二维数组进行操作
		if (func)
			func(mat);
	}
}

void processInputLineNum(const MyIntProcessFun& func)
{
	string line;
	string delimiter = " "; // 自定义分隔符，这里使用空格
	while (getline(cin, line)) {
		istringstream iss(line);
		string token;
		int sum = 0;
		while (getline(iss, token, delimiter[0])) {
			if (func)
				func(stoi(token));
		}
	}
}

void processInputArray(const MyArrayProcessFun& func)
{
	istream& in = cin;
	// 读取直到文件结束
	while (!in.eof()) {
		int n;
		in >> n;
		vector<int> arr(n,0);
		for (int i = 0; i < n; ++i) {
			in >> arr[i];
		}
		if (func)
			func(arr);
	}
}