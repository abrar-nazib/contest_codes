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

void print_stack_elements(stack<pair<int, int>> s)
{
    while (s.size() > 0)
    {
        cout << s.top().first << " " << s.top().second << "\n";
        s.pop();
    }
    cout << "\n";
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<pair<int, int>> height_stack;
        int max_area = 0, index, height, area, start;
        for (int i = 0; i < heights.size(); i++)
        {
            // print_stack_elements(height_stack);
            start = i;
            while (height_stack.size() > 0 && heights[i] < height_stack.top().second)
            {
                index = height_stack.top().first, height = height_stack.top().second;
                area = (i - index) * height_stack.top().second;
                max_area = MAX(area, max_area);
                height_stack.pop();
                start = index; // To retain the popped index
            }
            height_stack.push({start, heights[i]});
        }
        while (height_stack.size() > 0)
        {
            area = (heights.size() - height_stack.top().first) * height_stack.top().second;
            max_area = MAX(max_area, area);
            height_stack.pop();
        }
        return max_area;
    }
};

int main()
{
    Solution solution;

    // Example 1
    std::vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    int output1 = solution.largestRectangleArea(heights1);
    std::cout << "Output 1: " << output1 << std::endl; // Should print 10

    // Example 2
    std::vector<int> heights2 = {2, 4};
    int output2 = solution.largestRectangleArea(heights2);
    std::cout << "Output 2: " << output2 << std::endl; // Should print 4

    return 0;
}
