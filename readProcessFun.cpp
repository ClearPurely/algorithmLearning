#include"readProcessFun.h"
#include <string>
#include <sstream>

void processInputMatrix(const MyMatrixProcessFun& func)
{
	std::istream& in = std::cin;
	// 读取直到文件结束
	while (!in.eof()) {
		// 读取n，二维数组的行数
		int n;
		in >> n;
		// 读取m，二维数组的列数
		int m;
		in >> m;
		// 创建一个n行m列的二维数组
		std::vector<std::vector<int>> mat(n, std::vector<int>(m));
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
	std::string line;
	std::string delimiter = " "; // 自定义分隔符，这里使用空格
	while (std::getline(std::cin, line)) {
		std::istringstream iss(line);
		std::string token;
		int sum = 0;
		while (std::getline(iss, token, delimiter[0])) {
			if (func)
				func(std::stoi(token));
		}
	}
}

void processInputArray(const MyArrayProcessFun& func)
{
	std::istream& in = std::cin;
	// 读取直到文件结束
	while (!in.eof()) {
		int n;
		in >> n;
		std::vector<int> arr(n,0);
		for (int i = 0; i < n; ++i) {
			in >> arr[i];
		}
		if (func)
			func(arr);
	}
}