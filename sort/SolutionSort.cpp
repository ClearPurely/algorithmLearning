#include "SolutionSort.h"

void SolutionSort::merge(vector<int>& arr, int l, int m, int r) {
	int i = l;
	int a = l;
	int b = m + 1;
	while (a <= m && b <= r) {
		helpArr->at(i++) = arr[a] <= arr[b] ? arr[a++] : arr[b++];
	}
	while (a <= m) {		//如果最后合并剩一个左边的数
		helpArr->at(i++) = arr[a++];
	}
	while (b <= r) {		//剩右边的数
		helpArr->at(i++) = arr[b++];
	}
	for (i = l; i <= r; i++) {
		arr[i] = helpArr->at(i);
	}
}

void SolutionSort::mergeSort(vector<int>& arr, int l, int r) {
	if (l == r) {
		return;
	}
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

void SolutionSort::mergeSort1(vector<int>& arr) {
	int n = arr.size();
	for (int l, r, m, step = 1; step < n; step <<= 1)
	{
		l = 0;
		while (l <= n)
		{
			m = l + step - 1;
			if (m + 1 > n)
				break;
			r = min(m + step, n - 1);
			merge(arr, l, m, r);
			l = r + 1;
		}
	}
}

void SolutionSort::partition(int l, int r, int x) {
	first = l;
	last = r;
	int i = l;
	while (i <= last) {
		if (sourceArr[i] == x) {
			i++;
		}
		else if (sourceArr[i] < x) {
			swap(sourceArr[first++], sourceArr[i++]);
		}
		else {
			swap(sourceArr[i], sourceArr[last--]);
		}
	}
}

void SolutionSort::quickSort(int l, int r) {
	if (l >= r) {
		return;
	}
	// 随机这一下，常数时间比较大
	// 但只有这一下随机，才能在概率上把快速排序的时间复杂度收敛到O(n * logn)
	int x = sourceArr[(int)randomNum1(l, r)];
	partition(l, r, x);
	// 为了防止底层的递归过程覆盖全局变量
	// 这里用临时变量记录first、last
	int left = first;
	int right = last;
	quickSort(l, left - 1);
	quickSort(right + 1, r);
}

void SolutionSort::useQuickSort(vector<int>& arr) {
	if (arr.size() < 1)
		return;
	sourceArr = arr;
	quickSort(0, sourceArr.size() - 1);
}

int SolutionSort::randomizedSelect(vector<int>& arr, int i) {
	int ans = 0;
	i = i - sourceArr.size();
	sourceArr = arr;
	for (int l = 0, r = sourceArr.size() - 1; l <= r;) {
		// 随机这一下，常数时间比较大
		// 但只有这一下随机，才能在概率上把时间复杂度收敛到O(n)
		srand(static_cast<unsigned int>(time(nullptr)));
		partition(l, r, arr[l + (int)(std::rand() % (r - l + 1))]);
		// 因为左右两侧只需要走一侧
		// 所以不需要临时变量记录全局的first、last
		// 直接用即可
		if (i < first) {
			r = first - 1;
		}
		else if (i > last) {
			l = last + 1;
		}
		else {
			ans = arr[i];
			break;
		}
	}
	return ans;
}

void SolutionSort::heapSort(vector<int>& arr)
{
	make_heap(arr.begin(), arr.end(), less<int>());
	// 依次将堆顶元素（最大元素）移到数组末尾
	for (int i = 0; i < arr.size(); i++)
	{
		// 将堆顶元素移动到当前范围的末尾，并重新调整剩余元素为最大堆
		std::pop_heap(arr.begin(), arr.end() - i, less<int>());
	}
	// 移除末尾元素
	//arr.pop_back();
}

int SolutionSort::bits(int number) {
	int ans = 0;
	while (number > 0) {
		ans++;
		number /= BASE;
	}
	return ans;
}

vector<int> SolutionSort::radixSortArray(vector<int>& arr) {
	if (arr.size() > 1) {
		// 如果会溢出，那么要改用long类型数组来排序
		int n = arr.size();
		// 找到数组中的最小值
		int min = arr[0];
		for (int i = 1; i < n; i++) {
			min = std::min(min, arr[i]);
		}
		int max = 0;
		for (int i = 0; i < n; i++) {
			// 数组中的每个数字，减去数组中的最小值，就把arr转成了非负数组
			arr[i] -= min;
			// 记录数组中的最大值
			max = std::max(max, arr[i]);
		}
		// 根据最大值在BASE进制下的位数，决定基数排序做多少轮
		radixSort(arr, n, bits(max));
		// 数组中所有数都减去了最小值，所以最后不要忘了还原
		for (int i = 0; i < n; i++) {
			arr[i] += min;
		}
	}
	return arr;
}

void SolutionSort::radixSort(vector<int>& arr, int n, int bits) {
	// 理解的时候可以假设BASE = 10
	for (int offset = 1; bits > 0; offset *= BASE, bits--) {
		std::fill(cnts.begin(), cnts.end(), 0);
		for (int i = 0; i < n; i++) {
			// 数字提取某一位的技巧
			cnts[(arr[i] / offset) % BASE]++;
		}
		// 处理成前缀次数累加的形式
		for (int i = 1; i < BASE; i++) {
			cnts[i] = cnts[i] + cnts[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			// 前缀数量分区的技巧
			// 数字提取某一位的技巧
			help[--cnts[(arr[i] / offset) % BASE]] = arr[i];
		}
		for (int i = 0; i < n; i++) {
			arr[i] = help[i];
		}
	}
}

void SolutionSort::useSort(vector<int>& arr)
{
	helpArr = new vector<int>(arr.size(), 1);

	cout << "归并排序的结果：" << endl;
	mergeSort(arr, 0, arr.size() - 1);
	printArray(arr);
	cout << "非递归方式归并排序的结果：" << endl;
	vector<int> arr2 = copyArray(arr);
	mergeSort1(arr2);
	printArray(arr2);

	vector<int> arr3 = copyArray(arr);
	useQuickSort(arr3);
	cout << "快速排序的结果：" << endl;
	printArray(arr3);


	vector<int> arr4 = copyArray(arr);
	heapSort(arr4);
	cout << "归并排序的结果：" << endl;
	printArray(arr4);


	vector<int> arr5 = copyArray(arr);
	radixSortArray(arr5);
	cout << "基数排序的结果：" << endl;
	printArray(arr5);
}

void SolutionSort::testDemo(){
	//MyArrayProcessFun func = useMerge(testArr);;
	//processInputArray(func);

	vector<int> testArr = randomArray(10, 100);
	cout << "排序前的数组：" << endl;
	printArray(testArr);

	useSort(testArr);
}