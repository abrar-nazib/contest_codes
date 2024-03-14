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
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid, min_val = INT_MAX;
        while (l <= r)
        {
            mid = (l + r) / 2;
            min_val = MIN(min_val, nums[mid]);
            if (nums[l] >= nums[r])
                l = mid;
            else
                r = mid;
            if (l == r)
                break;
        }
        return min_val;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    int output1 = solution.findMin(nums1);
    cout << "Output 1: " << output1 << endl; // Should print 1

    // Example 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int output2 = solution.findMin(nums2);
    cout << "Output 2: " << output2 << endl; // Should print 0

    // Example 3
    vector<int> nums3 = {11, 13, 15, 17};
    int output3 = solution.findMin(nums3);
    cout << "Output 3: " << output3 << endl; // Should print 11

    return 0;
}