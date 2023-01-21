
// Problem: Monk and his Friends
// Link: https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/
// Date: 20-01-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long test_cases, prev_students, new_students, num_candies;
    unordered_set<unsigned long long> candies_list;

    cin >> test_cases;
    while (test_cases--)
    {
        candies_list.clear();
        cin >> prev_students >> new_students;

        for (unsigned long long i = 0; i < prev_students; i++)
        {
            cin >> num_candies;
            candies_list.insert(num_candies);
        }
        for (unsigned long long i = 0; i < new_students; i++)
        {
            cin >> num_candies;
            if (candies_list.find(num_candies) != candies_list.end())
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
            candies_list.insert(num_candies);
        }
    }

    return 0;
}