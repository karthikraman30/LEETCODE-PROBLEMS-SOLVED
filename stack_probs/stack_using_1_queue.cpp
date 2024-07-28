#include <iostream>
using namespace std;
#include <queue>

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);

        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {

        int res = q.front();
        q.pop();
        return res;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
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