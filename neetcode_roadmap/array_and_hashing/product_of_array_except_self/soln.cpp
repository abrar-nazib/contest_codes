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

int divide(int dividend, int divisor)
{
    if (divisor == 0)
    {
        return 0;
    }
    int quotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        quotient++;
    }
    return quotient;
}

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int nums_size = nums.size();
        vector<int> pref_mul(nums_size + 1);
        vector<int> suff_mul(nums_size + 1);
        pref_mul[0] = 1;
        suff_mul[nums_size] = 1;
        vector<int> out_mul(nums_size);
        for (int i = 0; i < nums_size; i++)
        {
            pref_mul[i + 1] = pref_mul[i] * nums[i];
            suff_mul[nums_size - i - 1] = suff_mul[nums_size - i] * nums[nums_size - i - 1];
        }
        for (int i = 0; i < nums_size; i++)
        {
            out_mul[i] = pref_mul[i] * suff_mul[i + 1];
        }
        return out_mul;
    }
};

int main()
{
    Solution s;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> output1 = s.productExceptSelf(nums1);
    print_vector_elements(output1); // Expected output: 24 12 8 6

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> output2 = s.productExceptSelf(nums2);
    print_vector_elements(output2); // Expected output: 0 0 9 0 0

    return 0;
}