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
    vector<int> topKFrequent(vector<int> &nums, int k) // O(nlogn)
    {
        vector<int> freq_arr;
        unordered_map<int, int> m;
        set<pair<int, int>, greater<pair<int, int>>> s;
        for (int &num : nums) // O(nlogm)
        {
            m[num] += 1; // O(logm)
        }
        for (auto &[m_k, m_v] : m) // O(mlogn)
        {
            s.insert({m_v, m_k}); // O(logm)
        }
        for (auto &s_elem : s) // O(k)
        {
            if (k <= 0)
                break;
            freq_arr.push_back(s_elem.second);
            k--;
        }
        return freq_arr;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> nums2 = {1};
    vector<int> out = s.topKFrequent(nums1, 2);
    print_vector_elements(out);
    // print_vector_elements(s.topKFrequent(nums2));
    // s.topKFrequent(nums1, 2);
    return 0;
}