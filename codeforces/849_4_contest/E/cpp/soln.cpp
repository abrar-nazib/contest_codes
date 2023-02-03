// #define _LOCAL 1

// Problem: E. Negatives and Positives
// Link: https://codeforces.com/contest/1791/problem/E
// Date: 03-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int t, n;
    long long num, sum;
    vector<long long> arr;
    map<long long, unsigned int, greater<long long>> maximum_impact;

    bool flag = 0;
    cin >> t;
    while (t--)
    {

        cin >> n;
        arr.clear();
        maximum_impact.clear();
        while (n--)
        {
            cin >> num;
            arr.push_back(num);
        }
        sum = 0;
        while (true)
        {
            int x, y;
            flag = 0;
            for (long long i = 0; i < arr.size() - 1; i++)
            {
                x = arr[i];
                y = arr[i + 1];
                if ((-x) + (-y) > x + y)
                {
                    maximum_impact[(-x) + (-y) - x + y] = i;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
            else
            {
                map<long long, unsigned int>::iterator it = maximum_impact.begin();
                arr[(*it).second] = -arr[(*it).second];
                arr[(*it).second + 1] = -arr[(*it).second + 1];
            }
        }
        for (auto elem : arr)
        {
            sum += elem;
        }
        cout << sum << "\n";
    }

    return 0;
}