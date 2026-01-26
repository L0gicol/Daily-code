#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> s_in;
    stack<int> s_out;

public:
    MyQueue() {}

    void push(int x)
    {
        s_in.push(x);
    }

    int pop()
    {
        int result;
        if (s_out.empty())
        {
            while (!s_in.empty())
            {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        result = s_out.top();
        s_out.pop();
        return result;
    }

    int peek()
    {
        int result;
        if (s_out.empty())
        {
            while (!s_in.empty())
            {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        return s_out.top();
    }

    bool empty()
    {
        if (s_in.empty() && s_out.empty())
            return true;
        else
            return false;
    }
};
