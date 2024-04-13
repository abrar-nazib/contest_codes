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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> window;
        vector<int> max_window;
        // Handle the initial set
        for (int i = 0; i < k; i++)
        {
            window.insert(nums[i]);
        }
        max_window.push_back(*window.begin());
        for (int i = 0; i < nums.size() - k; i++)
        {
            window.erase(window.find(nums[i]));
            window.insert(nums[i + k]);
            max_window.push_back(*window.begin());
        }

        return max_window;
    }
};

int main()
{
    Solution s;

    // Test case 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> output1 = s.maxSlidingWindow(nums1, k1);
    for (int i : output1)
    {
        cout << i << " ";
    }
    cout << "\n";

    // Test case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> output2 = s.maxSlidingWindow(nums2, k2);
    for (int i : output2)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
