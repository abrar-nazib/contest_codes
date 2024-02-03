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
    int maxArea(vector<int> &height)
    {
        // ios::sync_with_stdio(0);
        // cin.tie(0);
        int l = 0, r = height.size() - 1, max_area = 0;
        while (l < r)
        {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int output1 = solution.maxArea(height1);
    cout << "Output 1: " << output1 << endl; // Should print 49

    // Example 2
    vector<int> height2 = {1, 1};
    int output2 = solution.maxArea(height2);
    cout << "Output 2: " << output2 << endl; // Should print 1

    return 0;
}
