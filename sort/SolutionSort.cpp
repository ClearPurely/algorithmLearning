#include "SolutionSort.h"

void SolutionSort::merge(vector<int>& arr, int l, int m, int r) {
	int i = l;
	int a = l;
	int b = m + 1;
	while (a <= m && b <= r) {
		helpArr->at(i++) = arr[a] <= arr[b] ? arr[a++] : arr[b++];
	}
	while (a <= m) {		//������ϲ�ʣһ����ߵ���
		helpArr->at(i++) = arr[a++];
	}
	while (b <= r) {		//ʣ�ұߵ���
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
	// �����һ�£�����ʱ��Ƚϴ�
	// ��ֻ����һ������������ڸ����ϰѿ��������ʱ�临�Ӷ�������O(n * logn)
	int x = sourceArr[(int)randomNum1(l, r)];
	partition(l, r, x);
	// Ϊ�˷�ֹ�ײ�ĵݹ���̸���ȫ�ֱ���
	// ��������ʱ������¼first��last
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
		// �����һ�£�����ʱ��Ƚϴ�
		// ��ֻ����һ������������ڸ����ϰ�ʱ�临�Ӷ�������O(n)
		srand(static_cast<unsigned int>(time(nullptr)));
		partition(l, r, arr[l + (int)(std::rand() % (r - l + 1))]);
		// ��Ϊ��������ֻ��Ҫ��һ��
		// ���Բ���Ҫ��ʱ������¼ȫ�ֵ�first��last
		// ֱ���ü���
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
	// ���ν��Ѷ�Ԫ�أ����Ԫ�أ��Ƶ�����ĩβ
	for (int i = 0; i < arr.size(); i++)
	{
		// ���Ѷ�Ԫ���ƶ�����ǰ��Χ��ĩβ�������µ���ʣ��Ԫ��Ϊ����
		std::pop_heap(arr.begin(), arr.end() - i, less<int>());
	}
	// �Ƴ�ĩβԪ��
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
		// ������������ôҪ����long��������������
		int n = arr.size();
		// �ҵ������е���Сֵ
		int min = arr[0];
		for (int i = 1; i < n; i++) {
			min = std::min(min, arr[i]);
		}
		int max = 0;
		for (int i = 0; i < n; i++) {
			// �����е�ÿ�����֣���ȥ�����е���Сֵ���Ͱ�arrת���˷Ǹ�����
			arr[i] -= min;
			// ��¼�����е����ֵ
			max = std::max(max, arr[i]);
		}
		// �������ֵ��BASE�����µ�λ������������������������
		radixSort(arr, n, bits(max));
		// ����������������ȥ����Сֵ���������Ҫ���˻�ԭ
		for (int i = 0; i < n; i++) {
			arr[i] += min;
		}
	}
	return arr;
}

void SolutionSort::radixSort(vector<int>& arr, int n, int bits) {
	// ����ʱ����Լ���BASE = 10
	for (int offset = 1; bits > 0; offset *= BASE, bits--) {
		std::fill(cnts.begin(), cnts.end(), 0);
		for (int i = 0; i < n; i++) {
			// ������ȡĳһλ�ļ���
			cnts[(arr[i] / offset) % BASE]++;
		}
		// �����ǰ׺�����ۼӵ���ʽ
		for (int i = 1; i < BASE; i++) {
			cnts[i] = cnts[i] + cnts[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			// ǰ׺���������ļ���
			// ������ȡĳһλ�ļ���
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

	cout << "�鲢����Ľ����" << endl;
	mergeSort(arr, 0, arr.size() - 1);
	printArray(arr);
	cout << "�ǵݹ鷽ʽ�鲢����Ľ����" << endl;
	vector<int> arr2 = copyArray(arr);
	mergeSort1(arr2);
	printArray(arr2);

	vector<int> arr3 = copyArray(arr);
	useQuickSort(arr3);
	cout << "��������Ľ����" << endl;
	printArray(arr3);


	vector<int> arr4 = copyArray(arr);
	heapSort(arr4);
	cout << "�鲢����Ľ����" << endl;
	printArray(arr4);


	vector<int> arr5 = copyArray(arr);
	radixSortArray(arr5);
	cout << "��������Ľ����" << endl;
	printArray(arr5);
}

void SolutionSort::testDemo(){
	//MyArrayProcessFun func = useMerge(testArr);;
	//processInputArray(func);

	vector<int> testArr = randomArray(10, 100);
	cout << "����ǰ�����飺" << endl;
	printArray(testArr);

	useSort(testArr);
}