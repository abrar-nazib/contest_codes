#define _LOCAL 1

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> brackets = {{'[', -3}, {'{', -2}, {'(', -1}, {')', 1}, {'}', 2}, {']', 3}};
bool isBalanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (brackets[s[i]] > 0)
        {
            if (st.empty())
            {
                return 0;
            }
            if (brackets[st.top()] + brackets[s[i]] != 0)
                return 0;
            else
                st.pop();
        }
        else
            st.push(s[i]);
    }
    if (st.empty()) // check whether the stack is empty or not
        return 1;
    return 0;
}

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    unsigned int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (isBalanced(s))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}