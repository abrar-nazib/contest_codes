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
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0, start = 0, result = 0;
        unordered_set<char> char_set;
        for (int r = 0; r < s.length(); r++)
        {
            if (char_set.find(s[r]) == char_set.end())
            {
                char_set.insert(s[r]);
                max_len = MAX(max_len, char_set.size());
            }
            else
            {
                while (s[start] != s[r])
                {
                    char_set.erase(char_set.find(s[start]));
                    start++;
                }
                start++;
            }
        }
        return max_len;
    }
};

int main()
{
    Solution solution;
    cout << "Begin" << endl;
    // Example 1
    string s1 = "abcabcbb";
    int output1 = solution.lengthOfLongestSubstring(s1);
    cout << "Output 1: " << output1 << endl; // Should print 3

    // Example 2
    string s2 = "bbbbb";
    int output2 = solution.lengthOfLongestSubstring(s2);
    cout << "Output 2: " << output2 << endl; // Should print 1

    // Example 3
    string s3 = "pwwkew";
    int output3 = solution.lengthOfLongestSubstring(s3);
    cout << "Output 3: " << output3 << endl; // Should print 3

    // Example 4
    string s4 = " ";
    int output4 = solution.lengthOfLongestSubstring(s4);
    cout << "Output 4: " << output4 << endl;

    string s5 = "anviaj";
    int output5 = solution.lengthOfLongestSubstring(s5);
    cout << "Output 5: " << output5 << endl;

    string s6 = "jbpnbwwd";
    int output6 = solution.lengthOfLongestSubstring(s6);
    cout << "Output 6: " << output6 << endl;

    return 0;
}