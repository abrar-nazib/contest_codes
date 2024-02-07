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

template <typename T>
void print_stack_elements(stack<T> &s)
{
    while (s.size() > 0)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution
{
public:
    bool isValid(string s)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        stack<char> brackets;
        unordered_map<char, char> closing, opening;
        closing['}'] = '{';
        closing[']'] = '[';
        closing[')'] = '(';
        opening['('] = ')';
        opening['{'] = '}';
        opening['['] = ']';

        for (int i = 0; i < s.length(); i++)
        {
            if (opening.find(s[i]) != opening.end())
                brackets.push(s[i]);
            else
            {
                if (brackets.size() == 0 || closing[s[i]] != brackets.top())
                    return false;
                brackets.pop();
            }
        }
        if (brackets.size() > 0)
            return false;
        return true;
    }
};

int main()
{
    Solution solution;

    // Example 1
    string s1 = "()";
    bool output1 = solution.isValid(s1);
    cout << "Output 1: " << (output1 ? "true" : "false") << endl; // Should print true

    // Example 2
    string s2 = "()[]{}";
    bool output2 = solution.isValid(s2);
    cout << "Output 2: " << (output2 ? "true" : "false") << endl; // Should print true

    // Example 3
    string s3 = "]";
    bool output3 = solution.isValid(s3);
    cout << "Output 3: " << (output3 ? "true" : "false") << endl; // Should print false

    return 0;
}