#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack
{
private:
    stack<int> S_data;
    stack<int> S_min;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (S_min.empty() || val <= S_min.top())
            S_min.push(val);
        S_data.push(val);
    }

    void pop()
    {
        if (S_data.top() == S_min.top())
            S_min.pop();
        S_data.pop();
    }

    int top()
    {
        return S_data.top();
    }

    int getMin()
    {
        return S_min.top();
    }
};