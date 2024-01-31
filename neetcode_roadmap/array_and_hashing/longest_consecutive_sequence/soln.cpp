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

void recursive_update(unordered_map<int, int> &u, int k)
{
    u[k]++;
    if (u[k + 1])
        recursive_update(u, k + 1);
}

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<int> u_s(nums.begin(), nums.end());
        int longest = 0;
        int seq;
        for (const auto &val : u_s)
        {

            int temp_val = val;
            seq = 1;
            if (u_s.find(temp_val - 1) == u_s.end())
            {
                // cout << "Start of sequence " << temp_val << endl;
                while (u_s.find(temp_val + 1) != u_s.end())
                {
                    seq++;
                    temp_val++;
                }
            }
            longest = max(longest, seq);
        }
        return longest;
    }
};

int main()
{
    Solution s;

    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums1) << endl; // Expected output: 4

    // Test case 2
    vector<int> nums2 = {4, 0, -4, -2, 2, 5, 2, 0, -8, -8, -8, -8, -1, 7, 4, 5, 5, -4, 6, 6, -3};
    cout << s.longestConsecutive(nums2) << endl; // Expected output: 9

    return 0;
}
