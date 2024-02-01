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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int threesum = nums[i] + nums[l] + nums[r];
                if (threesum > 0)
                    r--;
                else if (threesum < 0)
                    l++;
                else
                {
                    out.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output1 = solution.threeSum(nums1);
    for (const auto &triplet : output1)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    // // Example 2
    // vector<int> nums2 = {0, 1, 1};
    // vector<vector<int>> output2 = solution.threeSum(nums2);
    // for (const auto &triplet : output2)
    // {
    //     cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    // }

    // Example 3
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> output3 = solution.threeSum(nums3);
    for (const auto &triplet : output3)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}