#include "_622_MyCircularQueue.h"

_622_MyCircularQueue::_622_MyCircularQueue(int k)
{
	//queue = new vector<int>(k);
	this->queue = vector<int>(k);
	l = r = size = 0;
	limit = k;
}

_622_MyCircularQueue::~_622_MyCircularQueue()
{
}

bool _622_MyCircularQueue::enQueue(int value)
{
	if (size == limit) {
		return false;
	}
	else
	{
		queue[r] = value;
		r = r == limit - 1 ? 0 : (r + 1);
		size++;
		return true;
	}
}

bool _622_MyCircularQueue::deQueue()
{
	if (size == 0) {
		return false;
	}
	else
	{
		l = l == limit - 1 ? 0 : (l + 1);
		size--;
		return true;
	}
}

int _622_MyCircularQueue::Front()
{
	if (isEmpty())
	{
		return -1;
	}
	else 
	{
		return queue[l];
	}
}

int _622_MyCircularQueue::Rear()
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		int last = r == 0 ? (limit - 1) : (r - 1);
		return queue[last];
	}
	return 0;
}

bool _622_MyCircularQueue::isEmpty()
{
	return size == 0;
}

bool _622_MyCircularQueue::isFull()
{
	return size == limit;
}
