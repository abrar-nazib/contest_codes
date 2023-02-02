#define _LOCAL 1

// Problem: hackerrank
// Link: https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
// Date: 02-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cur, val;

    cin >> n;
    vector<int> inp_arr;
    unordered_map<int, int> m_arr;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        m_arr.insert({cur, -1});
        inp_arr.push_back(cur);
        while (!st.empty() && cur > st.top())
        {
            val = st.top();
            st.pop();
            m_arr[val] = cur;
            // cout << "D:" << cur << endl;
        }
        st.push(cur);
    }
    for (int i = 0; i < n; i++)
    {
        cout << inp_arr[i] << " " << m_arr[inp_arr[i]] << "\n";
    }

    return 0;
}