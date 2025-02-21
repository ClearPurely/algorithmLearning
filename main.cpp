/*************
作者：ClearPurely
项目名：LeetCode算法题大全
创建日期：2021.9.20
最后更新日期：2025.1.6
****************/
#include"title.h"

//#include"readProcessFun.h"
// 示例操作函数，将元素加1
void addOne(std::vector<std::vector<int>>& mat) {
	for (auto& row : mat) {
		for (auto& element : row) {
			element += 1;
		}
	}
}

int main()
{
	//MyMatrixProcessFun func = addOne;
	//processInputMatrix(func);


	int num = 1;
	Solution* solution = nullptr;
	while (1) {

		cout << "请输入你要查看的题的序号:" << endl;
		std::cin >> num;

		switch (num) {
		case 0:
			solution = new SolutionSort();
			solution->testDemo();
			break;
		case 1:
			solution = new Solution1();
			solution->testDemo();
			break;
		case 2:
			solution = new _2_AddTwoNumbers();
			solution->testDemo();
			break;
		case 162:
			solution = new Solution162();
			solution->testDemo();
			break;

		default:
			std::cout << "无效的输入" << std::endl;
			break;
		}

		system("pause");
		system("cls");
		if (solution != nullptr) {
			delete solution;
			solution = nullptr;
		}
	}

	return 0;
}