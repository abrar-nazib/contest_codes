#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    stack<int> s;
    s.push(2);
    s.push(3);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }

    return 0;
}