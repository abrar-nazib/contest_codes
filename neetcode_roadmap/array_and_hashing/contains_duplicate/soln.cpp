#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (s.find(*it) != s.end())
            {
                return true;
            }
            s.insert(*it);
        }
        return false;
    }
};

int main()
{
    vector<int> nums({1, 2, 3, 1});
    Solution s;
    cout << s.containsDuplicate(nums);
}