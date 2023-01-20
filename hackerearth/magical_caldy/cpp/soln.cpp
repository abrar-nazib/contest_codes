
// Problem: Monk and the Magical Candy Bags
// Link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4
// Date: 20-01-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

// typedef unsigned int ui;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    unsigned long long t, n, k, x, out, temp;
    multiset<unsigned long long> candy_bags;
    cin >> t;
    // cout << t << endl;
    while (t--)
    {
        candy_bags.clear();

        out = 0;
        cin >> n >> k;
        // cout << n << " " << k << endl;
        for (unsigned int i = 0; i < n; i++)
        {
            cin >> x;
            // cout << x << endl;
            candy_bags.insert(x);
        }
        for (unsigned int i = 0; i < k; i++)
        {
            temp = *prev(candy_bags.end());

            // cout << temp << endl;
            out += temp;
            auto it = candy_bags.find(temp);
            candy_bags.erase(it);
            candy_bags.insert(temp / 2);
        }
        cout << out << endl;
    }

    return 0;
}