#include"readProcessFun.h"
#include <string>
#include <sstream>

void processInputMatrix(const MyMatrixProcessFun& func)
{
	std::istream& in = std::cin;
	// ��ȡֱ���ļ�����
	while (!in.eof()) {
		// ��ȡn����ά���������
		int n;
		in >> n;
		// ��ȡm����ά���������
		int m;
		in >> m;
		// ����һ��n��m�еĶ�ά����
		std::vector<std::vector<int>> mat(n, std::vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				in >> mat[i][j];
			}
		}
		// ʹ�ô���ĺ�����������ά������в���
		if (func)
			func(mat);
	}
}

void processInputLineNum(const MyIntProcessFun& func)
{
	std::string line;
	std::string delimiter = " "; // �Զ���ָ���������ʹ�ÿո�
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
	// ��ȡֱ���ļ�����
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