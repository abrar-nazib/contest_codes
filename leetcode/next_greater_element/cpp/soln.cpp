#define _LOCAL 1

// Problem: 496. Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/
// Date: 02-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> out(nums1.size(), -1);

    // conversion of vector to map of the smaller array
    unordered_map<int, int> m_nums1;
    for (int i = 0; i < nums1.size(); i++)
    {
        m_nums1.insert({nums1[i], i});
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        if (m_nums1.find(nums2[i]) != m_nums1.end()) // if ith element exists in smaller array, then try to find next greater. Otherwise not
        {
            for (int j = i + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums2[i])
                {
                    out[m_nums1[nums2[i]]] = nums2[j]; // ith index of first array -> out's ith index -> next greater element
                    break;
                }
            }
        }
    }
    return out;
}

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums1({2, 4});
    vector<int> nums2({1, 2, 3, 4});
    vector<int> out = nextGreaterElement(nums1, nums2);
    for (auto elem : out)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}