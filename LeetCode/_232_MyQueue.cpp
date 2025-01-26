#include "_232_MyQueue.h"

_232_MyQueue::_232_MyQueue()
{
    in = new stack<int>();
    out = new stack<int>();
}

_232_MyQueue::~_232_MyQueue()
{
    delete in;
    delete out;
    in = NULL;
    out = NULL;
}

void _232_MyQueue::inToOut()
{
    if (out->empty())
    {
        while (!in->empty())
        {
            out->push(in->top());
            in->pop();
        }
    }
}

void _232_MyQueue::push(int x)
{
    in->push(x);
    inToOut();
}

int _232_MyQueue::pop()
{
    inToOut();
    int ret = out->top();
    out->pop();
    return ret;
}

int _232_MyQueue::peek()
{
    inToOut();
    return out->top();
}

bool _232_MyQueue::empty()
{
    return in->empty() && out->empty();
}
