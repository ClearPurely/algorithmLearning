#include "SolutionSort.h"

void SolutionSort::mergeSort(vector<int>& arr, int l, int r) {
	if (l == r) {
		return;
	}
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

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

void SolutionSort::useMergeSort(vector<int>& arr)
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
}


void SolutionSort::useQuickSort(vector<int>& arr) {
	if (arr.size() < 1)
		return;
	sourceArr = arr;
	quickSort(0, sourceArr.size() - 1);
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

void SolutionSort::testDemo(){
	//MyArrayProcessFun func = useMerge(testArr);;
	//processInputArray(func);

	vector<int> testArr = randomArray(10, 100);
	cout << "排序前的数组：" << endl;
	printArray(testArr);

	useMergeSort(testArr);
}