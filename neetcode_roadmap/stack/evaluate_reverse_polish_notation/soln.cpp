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
    int evalRPN(vector<string> &tokens)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<int> st;
        unordered_map<string, function<int(int, int)>> operators = {
            {"*", [](int a, int b)
             { return a * b; }},
            {"+", [](int a, int b)
             { return a + b; }},
            {"-", [](int a, int b)
             { return a - b; }},
            {"/", [](int a, int b)
             { return a / b; }}};

        for (int i = 0; i < tokens.size(); i++)
        {
            if (operators.find(tokens[i]) == operators.end())
            {
                stringstream strstream;
                int num;
                strstream << tokens[i];
                strstream >> num;
                st.push(num);
                // cout << num << " ";
            }
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int num3 = operators[tokens[i]](num1, num2);
                st.push(num3);
            }
        }
        return st.top();
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    int output1 = solution.evalRPN(tokens1);
    cout << "Output 1: " << output1 << endl; // Should print 9

    // Example 2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    int output2 = solution.evalRPN(tokens2);
    cout << "Output 2: " << output2 << endl; // Should print 6

    // Example 3
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int output3 = solution.evalRPN(tokens3);
    cout << "Output 3: " << output3 << endl; // Should print 22

    return 0;
}
