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
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0, l = 0, r = 1;
        while (r < prices.size())
        {
            if (prices[r] > prices[l])
            {
                int profit = prices[r] - prices[l];
                max_profit = MAX(profit, max_profit);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int output1 = solution.maxProfit(prices1);
    cout << "Output 1: " << output1 << endl; // Should print 5

    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int output2 = solution.maxProfit(prices2);
    cout << "Output 2: " << output2 << endl; // Should print 0

    return 0;
}
