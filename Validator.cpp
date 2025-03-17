#include "Validator.h"

int randomNum(int max) {
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//return std::rand() % max + 1;
	return randomNum1(0, max);
}

int randomNum1(int min, int max) {
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//srand(static_cast<unsigned int>(time(nullptr)));  // ������ʼ��
	//min + std::rand() % (max - min + 1);

	// std::random_device ��һ����ȷ���Ե��������������
	// ͨ������Ӳ���豸����ϵͳ���سأ��������������
	// ������Ҫ������Ϊ����������ṩһ����������������ӡ�
	// ���ﴴ����һ�� std::random_device ���� rd�����ڻ�ȡ������ӡ�
	std::random_device rd;

	// std::mt19937 ��һ������÷ɭ��ת�㷨��α�������������
	// ����һ����������棬�ܹ����ݸ�������������һϵ���������
	// ����ʹ�� std::random_device ���� rd ���ɵ��������Ϊ���ӣ�
	// ��ʼ�� std::mt19937 ���� gen��
	std::mt19937 gen(rd());

	// std::uniform_int_distribution ��һ����ɢ���ȷֲ���ģ�壬
	// ���ڽ�������������ɵ������ӳ�䵽ָ����������Χ�ڡ�
	// ���ﴴ����һ�� std::uniform_int_distribution ���� dis��
	// ��ָ���˷ֲ��ķ�ΧΪ [min, max]�������ɵ����������ȷֲ�����������ڡ�
	std::uniform_int_distribution<> dis(min, max);

	// ���� std::uniform_int_distribution ���� dis �ĺ��������������
	// ������������� gen ��Ϊ����������һ���� [min, max] ��Χ�ڵ����������
	// ��������Ϊ�����ķ���ֵ��
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
	return source; // ֱ�ӷ��ظ���
}

bool sameArray(const std::vector<int>& arr1, const std::vector<int>& arr2) {
	return arr1 == arr2; // ʹ�� std::vector �ıȽ������
}