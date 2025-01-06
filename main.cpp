/*************
作者：张为
项目名：LeetCode算法题大全
创建日期：2021.9.20
最后更新日期：2025.1.6
****************/
#include <conio.h> // 包含getch()和kbhit()函数
#include <thread>

#include"标题.h"


bool shouldExit = false; // 用于标记是否应该退出程序的标志


void listenEvent() {
	while (!shouldExit) {
		if (_kbhit()) { // 检查是否有键盘输入
			char ch = _getch(); // 获取键盘输入
			if (ch == 27) { // 检查是否按下Esc键（ASCII码为27）
				shouldExit = true; // 设置退出标志
				break; // 退出循环
			}
		}
		this_thread::sleep_for(chrono::milliseconds(100)); // 避免过度占用CPU资源
	}
}

int main() 
{
	/*
	cout << "===测试开始===" << endl;
	cout << endl;

	//Solution162 s162;
	//Solution* solution = &s162;
	Solution* solution = new Solution162();
	solution->testDemo();
	cout << "===测试结束===" << endl;

	delete solution;
	solution = nullptr;
	*/

	int num = 1;
	Solution* solution = nullptr;

	while (1) {

		cout << "请输入你要查看的题的序号:" << endl;
		std::cin >> num;

		switch (num) {
		case 162:
			solution = new Solution162();
			solution->testDemo();
			break;
		case 1:
			solution = new Solution1();
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