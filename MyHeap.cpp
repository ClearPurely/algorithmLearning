#include "MyHeap.h"

MyHeap::MyHeap() {
	heap = vector<int>();
}

MyHeap::MyHeap(vector<int> arr) {
	heap = arr;
	make_heap(heap.begin(), heap.end(), std::greater<int>());
}

void MyHeap::add(int x) {
	heap.push_back(x);
	int i = (int)heap.size();
	while (heap[i] < heap[(i - 1) / 2]) {
		swap(heap[i], heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void MyHeap::pop() {
	int size = (int)heap.size();
	swap(heap[0], heap[--size]);
	heap.pop_back();
	int i = 0, l = 1;
	while (l < size) {
		int best = l + 1 < heap.size() && heap[l + 1] < heap[l] ? l + 1 : l;
		best = heap[best] < heap[i] ? best : i;
		if (best == i) {
			break;
		}
		swap(heap[i], heap[best]);
		i = best;
		l = i * 2 + 1;
	}
}

int MyHeap::top() {
	return heap[0];
}

int MyHeap::size() {
	return (int)heap.size();
}