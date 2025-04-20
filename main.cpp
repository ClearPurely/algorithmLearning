/*************
作者：ClearPurely
项目名：LeetCode算法题大全
创建日期：2021.9.20
最后更新日期：2025.1.6
****************/
#include"title.h"

//#include"readProcessFun.h"
// 示例操作函数，将元素加1
void addOne(vector<vector<int>>& mat) {
	for (auto& row : mat) {
		for (auto& element : row) {
			element += 1;
		}
	}
}

void testTrieArrayDemo() {
	int n;
	int op;
	string inStr;
	TrieArray trie;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> op;
		cin >> inStr;
		if (op == 1) {
			trie.insert(inStr);
		}
		else if (op == 2) {
			trie.erase(inStr);
		}
		else if (op == 3) {
			cout << (trie.search(inStr) > 0 ? "YES" : "NO") << endl;
		}
		else if (op == 4) {
			cout << trie.startsWith(inStr) << endl;
		}
	}
	trie.clear();
}

//测试前缀树代码
void testTrieTreeDemo() {
	TrieTree trie;

	// 测试1：基础插入和查询
	trie.insert("apple");
	cout << "Test1.1: " << (trie.countWordsEqualTo("apple") == 1 ? "Pass" : "Fail") << endl;     // 应输出Pass
	cout << "Test1.2: " << (trie.countWordsStartingWith("app") == 1 ? "Pass" : "Fail") << endl; // 应输出Pass

	// 测试2：重复插入
	trie.insert("apple");
	cout << "Test2.1: " << (trie.countWordsEqualTo("apple") == 2 ? "Pass" : "Fail") << endl;    // 应输出Pass
	cout << "Test2.2: " << (trie.countWordsStartingWith("a") == 2 ? "Pass" : "Fail") << endl;   // 应输出Pass

	// 测试3：插入不同词
	trie.insert("app");
	trie.insert("application");
	cout << "Test3.1: " << (trie.countWordsStartingWith("app") == 4 ? "Pass" : "Fail") << endl;  // (apple*2 + app + application)
	cout << "Test3.2: " << (trie.countWordsEqualTo("app") == 1 ? "Pass" : "Fail") << endl;      // 应输出Pass

	// 测试4：删除操作
	trie.erase("apple");
	cout << "Test4.1: " << (trie.countWordsEqualTo("apple") == 1 ? "Pass" : "Fail") << endl;    // 应输出Pass
	cout << "Test4.2: " << (trie.countWordsStartingWith("appl") == 1 ? "Pass" : "Fail") << endl;  // 剩下1个apple和application

	// 测试5：完全删除单词
	trie.erase("apple");
	cout << "Test5.1: " << (trie.countWordsEqualTo("apple") == 0 ? "Pass" : "Fail") << endl;     // 应输出Pass
	cout << "Test5.2: " << (trie.countWordsStartingWith("app") == 2 ? "Pass" : "Fail") << endl;  // app + application

	// 测试6：删除不存在的词
	trie.erase("banana");
	cout << "Test6: " << (trie.countWordsStartingWith("b") == 0 ? "Pass" : "Fail") << endl;      // 应输出Pass

	// 测试7：删除后结构保持
	cout << "Test7.1: " << (trie.countWordsEqualTo("app") == 1 ? "Pass" : "Fail") << endl;       // 应输出Pass
	trie.erase("app");
	cout << "Test7.2: " << (trie.countWordsStartingWith("app") == 1 ? "Pass" : "Fail") << endl; // 只剩application
}

int main()
{
	//MyMatrixProcessFun func = addOne;
	//processInputMatrix(func);
	testTrieTreeDemo();
	

	int num = 1;
	Solution* solution = nullptr;
	while (1) {
		cout << "请输入你要查看的题的序号:" << endl;
		cin >> num;

		switch (num) {
		case 0:
			solution = new SolutionSort();
			solution->testDemo();
			break;
		case 1:
			solution = new _1_TwoSum();
			solution->testDemo();
			break;
		case 2:
			solution = new _2_AddTwoNumbers();
			solution->testDemo();
			break;
		case 29:
			solution = new _29_Divide();
			solution->testDemo();
			break;
		case 52:
			solution = new _52_TotalNQueens();
			solution->testDemo();
			break;
		case 162:
			solution = new _162_FindPeakElement();
			solution->testDemo();
			break;
		case 421:
			solution = new _421_FindMaximumXOR();
			solution->testDemo();
			break;
		case 726:
			solution = new _726_CountOfAtoms();
			solution->testDemo();
			break;
		case 772:
			solution = new _772_Calculate();
			solution->testDemo();
			break;
		case 906:
			solution = new _906_SuperpalindromesInRange();
			solution->testDemo();
			break;
		default:
			cout << "无效的输入" << endl;
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