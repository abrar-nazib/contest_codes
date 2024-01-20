#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> mp(26, 0);
        vector<int> mp2(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            mp[(int)'z' - (int)s[i]]++;
            mp[(int)'z' - (int)t[i]]--;
        }
        // for (int i = 0; i < mp.size(); i++)
        // {
        //     if (mp[i] != 0)
        //     {
        //         return false;
        //     }
        // }
        return mp == mp2;
    }
};

int main()
{
    Solution sl;
    string s = "anagram", t = "nagaram";
    cout << sl.isAnagram(s, t) << "\n";
    s = "rat", t = "car";
    cout << sl.isAnagram(s, t) << "\n";
    return 0;
}