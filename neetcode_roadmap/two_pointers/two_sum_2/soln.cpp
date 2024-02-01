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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int l_index = 0, r_index = numbers.size() - 1, sum = 0;
        vector<int> sol_indices(2);
        while (l_index < r_index) // n-1 -> O(n)
        {
            sum = numbers[l_index] + numbers[r_index];
            if (sum > target)
                r_index--;
            else if (sum < target)
                l_index++;
            else
            {
                sol_indices[0] = l_index + 1; // O(1)
                sol_indices[1] = r_index + 1;
                return sol_indices;
            }
        }
        return sol_indices;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> output1 = solution.twoSum(numbers1, target1);
    cout << output1[0] << ", " << output1[1] << endl; // should print: 1, 2

    // Example 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> output2 = solution.twoSum(numbers2, target2);
    cout << output2[0] << ", " << output2[1] << endl; // should print: 1, 3

    // Example 3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> output3 = solution.twoSum(numbers3, target3);
    cout << output3[0] << ", " << output3[1] << endl; // should print: 1, 2

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}