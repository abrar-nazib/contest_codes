#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector_elements(vector<T> &v)
{
    for (T &e : v)
    {
        cout << e << " ";
    }
    cout << "\n";
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class MinStack
{
    stack<int> s;
    stack<int> min_val_stack;

public:
    MinStack()
    {
        min_val_stack.push(INT_MAX);
    }

    void push(int val)
    {
        if (val <= min_val_stack.top())
        {
            min_val_stack.push(val);
        }
        s.push(val);
    }

    void pop()
    {
        if (s.top() == min_val_stack.top())
            min_val_stack.pop();
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_val_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int min1 = obj->getMin(); // Should print -3
    cout << "Min1: " << min1 << endl;
    obj->pop();
    int top = obj->top(); // Should print 0
    cout << "Top: " << top << endl;
    int min2 = obj->getMin(); // Should print -2
    cout << "Min2: " << min2 << endl;

    delete obj;
    return 0;
}
