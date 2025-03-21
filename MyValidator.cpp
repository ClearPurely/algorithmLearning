#include "MyValidator.h"

int MyValidator::randomNum(int max) {
	//srand(static_cast<unsigned int>(time(nullptr)));
	//return rand() % max + 1;
	return randomNum1(0, max);
}

int MyValidator::randomNum1(int min, int max) {
	//srand(static_cast<unsigned int>(time(nullptr)));
	//srand(static_cast<unsigned int>(time(nullptr)));  // 新增初始化
	//min + rand() % (max - min + 1);

	// random_device 是一个非确定性的随机数生成器，
	// 通常基于硬件设备（如系统的熵池）来生成随机数。
	// 它的主要作用是为随机数引擎提供一个高质量的随机种子。
	// 这里创建了一个 random_device 对象 rd，用于获取随机种子。
	random_device rd;

	// mt19937 是一个基于梅森旋转算法的伪随机数生成器。
	// 它是一个随机数引擎，能够根据给定的种子生成一系列随机数。
	// 这里使用 random_device 对象 rd 生成的随机数作为种子，
	// 初始化 mt19937 对象 gen。
	mt19937 gen(rd());

	// uniform_int_distribution 是一个离散均匀分布类模板，
	// 用于将随机数引擎生成的随机数映射到指定的整数范围内。
	// 这里创建了一个 uniform_int_distribution 对象 dis，
	// 并指定了分布的范围为 [min, max]，即生成的随机数会均匀分布在这个区间内。
	uniform_int_distribution<> dis(min, max);

	// 调用 uniform_int_distribution 对象 dis 的函数调用运算符，
	// 传入随机数引擎 gen 作为参数，生成一个在 [min, max] 范围内的随机整数，
	// 并将其作为函数的返回值。
	return dis(gen);
}

double MyValidator::getFuncExcTime(clock_t start, bool isPrint) {
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	if (isPrint)
		cout << "Function is running in " << duration << "s" << endl;
	return duration;
}

void MyValidator::printBinary(int num) {
	bitset<32> binary(num);
	cout << binary << endl;
}

void MyValidator::printArray(const vector<int>& arr) {
	for (const auto& num : arr) {
		cout << num << "  ";
	}
	cout << endl;
}

void MyValidator::printMatrix(const vector<vector<int>>& mat) {
	for (const auto& row : mat) {
		for (const auto& num : row) {
			cout << num << "  ";
		}
		cout << endl;
	}
}

vector<int> MyValidator::randomArray(int n, int v) {
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = randomNum(v);
	}
	return arr;
}

vector<int> MyValidator::randomArray1(int maxLen, int max, bool isSorted) {
	vector<int> ans((rand() % maxLen) + 1);
	for (int i = 0; i < ans.size(); ++i) {
		ans[i] = (rand() % max) + 1;
	}
	if (isSorted)
		sort(ans.begin(), ans.end());
	return ans;
}

vector<int> MyValidator::randomArray2(int maxLen, int max, bool isSorted) {
	vector<int> ans(maxLen);
	for (int i = 0; i < ans.size(); ++i) {
		int temp = (rand() % max) + 1;
		ans[i] = (rand() % 2 == 0) ? temp : -temp;
	}
	if (isSorted)
		sort(ans.begin(), ans.end());
	return ans;
}

string MyValidator::randomString(int maxLen, const string& exaction) {
	string str((rand() % maxLen) + 1, 'G');
	for (int i = 0; i < str.size(); ++i) {
		str[i] = exaction[rand() % exaction.size()];
	}
	return str;
}

vector<int> MyValidator::copyArray(const vector<int>& source) {
	return source; // 直接返回副本
}

bool MyValidator::sameArray(const vector<int>& arr1, const vector<int>& arr2) {
	return arr1 == arr2; // 使用 vector 的比较运算符
}
