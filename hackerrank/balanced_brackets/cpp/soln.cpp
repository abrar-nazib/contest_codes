#define _LOCAL 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    map<char, char> b_pair;
    b_pair.insert({')', '('});
    b_pair.insert({'}', '{'});
    b_pair.insert({']', '['});

    unsigned int t;
    bool flag = 0;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<char> char_stack;
        flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                char_stack.push(s[i]);
            else
            {
                if (char_stack.empty())
                {
                    cout << "NO";
                    flag = 1;
                    break;
                }
                if (char_stack.top() == b_pair[s[i]])
                    char_stack.pop();
                else
                {
                    cout << "NO";
                    flag = 1;
                    break;
                }
            }
        }
        if (!char_stack.empty())
        {
            if (flag == 0)
                cout << "NO";
        }
        else
        {
            if (flag == 0)
                cout << "YES";
        }
        cout << endl;
    }

    return 0;
}