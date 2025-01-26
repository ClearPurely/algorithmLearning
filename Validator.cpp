#include "Validator.h"

/*
int randomNum(int max)
{
	srand(time(nullptr));  // 使用当前时间作为随机种子
	return (rand() % max + 1);
}

double getFuncExcTime(clock_t start, bool isPrint = true)
{
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	if (isPrint)
		cout << "Function is running in " << duration << "s" << endl;
	return duration;
}

static void printBinary(int num) {
	for (int i = 31; i >= 0; i--) {
		// 下面这句写法，可以改成 :
		// System.out.print((a & (1 << i)) != 0 ? "1" : "0");
		// 但不可以改成 :
		// System.out.print((a & (1 << i)) == 1 ? "1" : "0");
		// 因为a如果第i位有1，那么(a & (1 << i))是2的i次方，而不一定是1
		// 比如，a = 0010011
		// a的第0位是1，第1位是1，第4位是1
		// (a & (1<<4)) == 16（不是1），说明a的第4位是1状态
		cout << ((num & (1 << i)) == 0 ? "0" : "1");
	}
	cout << endl;
}

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void printMatrix(vector<vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
}

vector<int> randomArray(int n, int v) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		// Math.random() -> double -> [0,1)范围山的一个小数，0.37463473126、0.001231231，等概率！
		// Math.random() * v -> double -> [0,v)一个小数，依然等概率
		// (int)(Math.random() * v) -> int -> 0 1 2 3 ... v-1，等概率的！
		// (int) (Math.random() * v) + 1 -> int -> 1 2 3 .... v，等概率的！

		srand(time(nullptr));  // 使用当前时间作为随机种子

		int randomNum = rand() % 100 + 1;
		arr[i] = (int)(rand() % 100) + 1;
	}
	return arr;
}

vector<int> static randomArray1(int maxLen, int max, bool isSorted = true) {
	srand(time(nullptr));  // 使用当前时间作为随机种子
	vector<int> ans((rand() % maxLen) + 1);
	for (int i = 0; i < ans.size(); i++) {
		ans[i] = (int)((rand() % max) + 1);
	}
	if (isSorted)
		sort(ans.begin(), ans.end());
	return ans;
}

vector<int> static randomArray2(int maxLen, int max, bool isSorted) {
	//vector<int> ans((rand() % maxLen) + 1);
	vector<int> ans(maxLen);
	for (int i = 0; i < ans.size(); i++) {
		int temp = (int)((rand() % max) + 1);
		ans[i] = (rand() % (999 + 1) / (float)(999 + 1)) < 0.5 ? temp : -temp;
	}
	if (isSorted)
		sort(ans.begin(), ans.end());
	return ans;
}

string randomString(int maxLen, string exaction = "GB") {
	string str((rand() % maxLen) + 1, 'G');
	for (int i = 0; i < str.size(); i++) {
		str[i] = exaction.at(rand() % exaction.size());
	}
	return str;
}

vector<int> copyArray(const vector<int>& source) {
	vector<int> destination(source);
	return destination;
}

bool sameArray(const vector<int>& arr1, const vector<int>& arr2) {
	if (arr1.size() != arr2.size()) {
		return false;
	}

	for (size_t i = 0; i < arr1.size(); ++i) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}

	return true;
}
*/

int randomNum(int max) {
	return std::rand() % max + 1;
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

