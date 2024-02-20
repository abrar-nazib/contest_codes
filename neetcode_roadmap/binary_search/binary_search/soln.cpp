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
    int search(vector<int> &nums, int target)
    {
        int l = 0, mid, r = nums.size() - 1;
        while (l <= r)
        {
            cout << l << " " << r << "\n";
            mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    // Example 1
    std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int output1 = solution.search(nums1, target1);
    std::cout << "Output 1: " << output1 << std::endl; // Should print 4

    // Example 2
    std::vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int output2 = solution.search(nums2, target2);
    std::cout << "Output 2: " << output2 << std::endl; // Should print -1

    vector<int> nums3 = {5};
    int target3 = 5;
    int output3 = solution.search(nums3, target3);
    cout << "Output 3: " << output3 << endl;

    return 0;
}
