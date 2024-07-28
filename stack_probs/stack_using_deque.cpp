#include <iostream>
using namespace std;
#include <queue>

class MyStack
{
public:
    deque<int> dq;
    MyStack()
    {
    }

    void push(int x)
    {
        dq.push_back(x);
    }

    int pop()
    {
        int top;
        if (!dq.empty())
        {
            top = dq.back();
            dq.pop_back();
        }
        return top;
    }

    int top()
    {
        int topi;
        if (!dq.empty())
        {
            topi = dq.back();
        }
        return topi;
    }

    bool empty()
    {
        if (dq.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.empty();
    s.top();
    return 0;
}