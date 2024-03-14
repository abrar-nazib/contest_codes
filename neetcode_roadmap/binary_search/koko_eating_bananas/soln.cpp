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
    int minEatingSpeed(const vector<int> &piles, int h)
    {
        int max_k = *std::upper_bound(piles.begin(), piles.end(), h);
        return std::binary_search(piles.begin(), piles.end(), h / max_k) ? max_k : -1;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    int output1 = solution.minEatingSpeed(piles1, h1);
    cout << "Output 1: " << output1 << endl; // Should print 4

    // Example 2
    vector<int> piles2 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    int h2 = 823855818;
    int output2 = solution.minEatingSpeed(piles2, h2);
    cout << "Output 2: " << output2 << endl; // Should print 30

    // Example 3
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    int output3 = solution.minEatingSpeed(piles3, h3);
    cout << "Output 3: " << output3 << endl; // Should print 23

    return 0;
}