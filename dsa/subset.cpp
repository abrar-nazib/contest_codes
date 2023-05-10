#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

vector<vector<int>> subsets;

void generate_subsets(vector<int> &subset, int i, vector<int> &inp_arr)
{
    if (i == inp_arr.size())
    {
        subsets.push_back(subset);
        return;
    }
    // not including ith elem
    generate_subsets(subset, i + 1, inp_arr);

    // including ith elem
    subset.push_back(inp_arr[i]);
    generate_subsets(subset, i + 1, inp_arr);
    subset.pop_back(); // eliminate the last push
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
    // Input
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    vector<int> e;
    generate_subsets(e, 0, inp);

    for (int i = 0; i < subsets.size(); i++)
    {
        for (int j = 0; j < subsets[i].size(); j++)
        {
            cout << subsets[i][j] << " ";
        }
        cout << "\n";
    }
    // for (auto subset : subsets)
    // {
    //     for (auto elem : subset)
    //     {
    //         cout << elem << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}