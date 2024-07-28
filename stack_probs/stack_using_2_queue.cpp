#include <iostream>
using namespace std;
#include <queue>

class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }
    void push(int x)
    {
        q2.push(x);
        while (q1.size() > 0)
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << "pushed into stack" << endl;
    }
    int pop()
    {
        int result = q1.front();
        q1.pop();
        return result;
    }
    int top()
    {
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
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