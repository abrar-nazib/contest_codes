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
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if ((*it).second != 0)
                return false;
        }
        return true;
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