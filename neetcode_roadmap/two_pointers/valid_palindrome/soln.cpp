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

class Solution
{
public:
    bool isPalindrome(string s)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        string sanitized_string = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || s[i] >= '0' && s[i] <= '9')
            {
                sanitized_string += tolower(s[i]);
                // cout << tolower(s[i]);
            }
        }
        // cout << sanitized_string << endl;
        if (sanitized_string.length() <= 1)
            return true;
        for (int i = 0, j = sanitized_string.length() - 1; i <= sanitized_string.length() / 2, j >= sanitized_string.length() / 2; i++, j--)
        {
            if (sanitized_string[i] != sanitized_string[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    // Example 1
    string input1 = "A man, a plan, a canal: Panama";
    bool output1 = solution.isPalindrome(input1);
    cout << (output1 ? "true" : "false") << endl; // should print: true

    // Example 2
    string input2 = "race a car";
    bool output2 = solution.isPalindrome(input2);
    cout << (output2 ? "true" : "false") << endl; // should print: false

    // Example 3
    string input3 = " ";
    bool output3 = solution.isPalindrome(input3);
    cout << (output3 ? "true" : "false") << endl; // should print: true

    return 0;
}
