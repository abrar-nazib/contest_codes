#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s != t)
        {
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