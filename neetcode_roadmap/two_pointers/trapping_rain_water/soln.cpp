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
    int trap(vector<int> &height)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> l_max(height.size()), r_max(height.size());
        for (int i = 0; i < height.size() - 1; i++)
        {
            if (i != 0)
            {
                l_max[i] = MAX(l_max[i - 1], height[i]);
                r_max[height.size() - i - 1] = MAX(r_max[height.size() - i], height[height.size() - i - 1]);
            }
            else
            {
                l_max[i] = height[i];
                r_max[height.size() - i - 1] = height[height.size() - i - 1];
            }
        }
        // print_vector_elements(l_max);
        // print_vector_elements(r_max);
        int trapped_water = 0, cell_water = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            cell_water = MIN(l_max[i - 1], r_max[i + 1]) - height[i];
            trapped_water += cell_water > 0 ? cell_water : 0;
        }
        return trapped_water;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int output1 = solution.trap(height1);
    cout << "Output 1: " << output1 << endl; // Should print 6

    // Example 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    int output2 = solution.trap(height2);
    cout << "Output 2: " << output2 << endl; // Should print 9

    return 0;
}