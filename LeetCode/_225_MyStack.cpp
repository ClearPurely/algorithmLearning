#include "_225_MyStack.h"

_225_MyStack::_225_MyStack()
{
	queue1 = new queue<int>();
}

_225_MyStack::~_225_MyStack()
{
	delete queue1;
	queue1 = NULL;
}

void _225_MyStack::push(int x)
{
	queue1->push(x);
	for (int i = 0; i < queue1->size() - 1; i++)
	{
		queue1->push(queue1->front());
		queue1->pop();
	}
}

int _225_MyStack::pop()
{
	int ans = queue1->front();
	queue1->pop();
	return ans;
}

int _225_MyStack::top()
{
	return queue1->front();
}

bool _225_MyStack::empty()
{
	return queue1->empty();
}
