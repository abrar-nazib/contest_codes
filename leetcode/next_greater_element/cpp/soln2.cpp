#define _LOCAL 1

// Problem: 496. Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/
// Date: 02-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<int> st)
{
    int val;
    cout << "stack: ";
    while (!st.empty())
    {
        val = st.top();
        st.pop();
        cout << val << " ";
    }
    cout << endl;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> out(nums1.size(), -1);
    stack<int> st;

    // conversion of vector to map of the smaller array
    unordered_map<int, int> m_nums1;
    for (int i = 0; i < nums1.size(); i++)
    {
        m_nums1.insert({nums1[i], i});
    }

    int val;
    int cur;
    for (int i = 0; i < nums2.size(); i++)
    {

        /**
         * put element in the stack if its less than the top element of the stack
         * ----> twist: check first array before pushing into stack.
         * if any element is greater than the top element of the stack, pop the elements until greater element is found or stack becomes empty
         */
        cur = nums2[i];
        if (!st.empty() && cur > st.top())
        {
            while (!st.empty() && cur > st.top())
            {
                val = st.top();
                st.pop();
                out[m_nums1[val]] = cur;
            }
            if (m_nums1.find(cur) != m_nums1.end())
            {
                st.push(cur);
            }
        }

        else
        {
            if (m_nums1.find(cur) != m_nums1.end())
            {
                st.push(cur);
            }
        }
        // print_stack(st);
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
    // vector<int> nums1({4, 1, 2});
    // vector<int> nums2({2, 1, 3, 4});
    // vector<int> nums1({2, 4});
    // vector<int> nums2({1, 2, 3, 4});
    vector<int> nums1({4, 1, 2});
    vector<int> nums2({1, 2, 3, 4});
    vector<int> out = nextGreaterElement(nums1, nums2);
    for (auto elem : out)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}