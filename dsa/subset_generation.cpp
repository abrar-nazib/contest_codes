#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

vector<vector<int>> subsets;

void generate(vector<int> &subset, int index, vector<int> &nums)
{
    if (index == nums.size())
    {
        subsets.push_back(subset);
        return;
    }
    generate(subset, index + 1, nums); // not considering ith element

    // considering ith element
    subset.push_back(nums[index]);
    generate(subset, index + 1, nums);

    // Fixing the array
    subset.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> empty;
    generate(empty, 0, nums);

    for (auto sub : subsets)
    {
        for (auto elem : sub)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }

    return 0;
}