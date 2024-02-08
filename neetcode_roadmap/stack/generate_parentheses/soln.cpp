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

class Solution
{
public:
    vector<string> sv;
    void backtrack(int n, string str, int opening, int closing)
    {
        if (opening == closing && closing == n)
        {
            sv.push_back(str);
            return;
        }
        if (opening < n)
        {
            str += "(";
            backtrack(n, str, opening + 1, closing);
            str.pop_back();
        }
        if (opening > closing)
        {
            str += ")";
            backtrack(n, str, opening, closing + 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        sv.clear();
        backtrack(n, "(", 1, 0);
        return sv;
    }
};

int main()
{
    Solution solution;

    // Example 1
    int n1 = 3;
    vector<string> output1 = solution.generateParenthesis(n1);
    cout << "Output 1: ";
    for (const auto &str : output1)
    {
        cout << str << " ";
    }
    cout << endl;

    // Example 2
    int n2 = 1;
    vector<string> output2 = solution.generateParenthesis(n2);
    cout << "Output 2: ";
    for (const auto &str : output2)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}