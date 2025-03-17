#include "Validator.h"

int randomNum(int max) {
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//return std::rand() % max + 1;
	return randomNum1(0, max);
}

int randomNum1(int min, int max) {
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//srand(static_cast<unsigned int>(time(nullptr)));  // 新增初始化
	//min + std::rand() % (max - min + 1);

	// std::random_device 是一个非确定性的随机数生成器，
	// 通常基于硬件设备（如系统的熵池）来生成随机数。
	// 它的主要作用是为随机数引擎提供一个高质量的随机种子。
	// 这里创建了一个 std::random_device 对象 rd，用于获取随机种子。
	std::random_device rd;

	// std::mt19937 是一个基于梅森旋转算法的伪随机数生成器。
	// 它是一个随机数引擎，能够根据给定的种子生成一系列随机数。
	// 这里使用 std::random_device 对象 rd 生成的随机数作为种子，
	// 初始化 std::mt19937 对象 gen。
	std::mt19937 gen(rd());

	// std::uniform_int_distribution 是一个离散均匀分布类模板，
	// 用于将随机数引擎生成的随机数映射到指定的整数范围内。
	// 这里创建了一个 std::uniform_int_distribution 对象 dis，
	// 并指定了分布的范围为 [min, max]，即生成的随机数会均匀分布在这个区间内。
	std::uniform_int_distribution<> dis(min, max);

	// 调用 std::uniform_int_distribution 对象 dis 的函数调用运算符，
	// 传入随机数引擎 gen 作为参数，生成一个在 [min, max] 范围内的随机整数，
	// 并将其作为函数的返回值。
	return dis(gen);
}

double getFuncExcTime(std::clock_t start, bool isPrint) {
	std::clock_t finish = std::clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	if (isPrint)
		std::cout << "Function is running in " << duration << "s" << std::endl;
	return duration;
}

void printBinary(int num) {
	std::bitset<32> binary(num);
	std::cout << binary << std::endl;
}

void printArray(const std::vector<int>& arr) {
	for (const auto& num : arr) {
		std::cout << num << "  ";
	}
	std::cout << std::endl;
}

void printMatrix(const std::vector<std::vector<int>>& mat) {
	for (const auto& row : mat) {
		for (const auto& num : row) {
			std::cout << num << "  ";
		}
		std::cout << std::endl;
	}
}

std::vector<int> randomArray(int n, int v) {
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = randomNum(v);
	}
	return arr;
}

std::vector<int> randomArray1(int maxLen, int max, bool isSorted) {
	std::vector<int> ans((std::rand() % maxLen) + 1);
	for (int i = 0; i < ans.size(); ++i) {
		ans[i] = (std::rand() % max) + 1;
	}
	if (isSorted)
		std::sort(ans.begin(), ans.end());
	return ans;
}

std::vector<int> randomArray2(int maxLen, int max, bool isSorted) {
	std::vector<int> ans(maxLen);
	for (int i = 0; i < ans.size(); ++i) {
		int temp = (std::rand() % max) + 1;
		ans[i] = (std::rand() % 2 == 0) ? temp : -temp;
	}
	if (isSorted)
		std::sort(ans.begin(), ans.end());
	return ans;
}

std::string randomString(int maxLen, const std::string& exaction) {
	std::string str((std::rand() % maxLen) + 1, 'G');
	for (int i = 0; i < str.size(); ++i) {
		str[i] = exaction[std::rand() % exaction.size()];
	}
	return str;
}

std::vector<int> copyArray(const std::vector<int>& source) {
	return source; // 直接返回副本
}

bool sameArray(const std::vector<int>& arr1, const std::vector<int>& arr2) {
	return arr1 == arr2; // 使用 std::vector 的比较运算符
}