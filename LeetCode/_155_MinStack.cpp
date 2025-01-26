#include "_155_MinStack.h"

_155_MinStack::_155_MinStack()
{
	data = new stack<int>();
	minStack = new stack<int>();
}

_155_MinStack::~_155_MinStack()
{
	delete data;
	data = NULL;
	delete minStack;
	minStack = NULL;
}

void _155_MinStack::push(int val)
{
	data->push(val);
	if (minStack->empty())
	{
		minStack->push(val);
	}
	else
	{
		minStack->push(std::min(val, minStack->top()));
	}
}

void _155_MinStack::pop()
{
	data->pop();
	minStack->pop();
}

int _155_MinStack::top()
{
	return data->top();
}

int _155_MinStack::getMin()
{
	return minStack->top();
}
