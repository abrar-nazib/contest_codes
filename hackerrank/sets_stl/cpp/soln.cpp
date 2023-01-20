
// Problem: hackerrank
// Link: https://www.hackerrank.com/challenges/cpp-sets/problem
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

    unsigned long long test_cases, operation_type, num;
    cin >> test_cases;
    set<unsigned long long> nums;
    while (test_cases--)
    {
        cin >> operation_type >> num;
        if (operation_type == 1)
        {
            nums.insert(num);
        }
        if (operation_type == 2)
        {
            if (nums.find(num) != nums.end())
            {
                nums.erase(num);
            }
        }
        if (operation_type == 3)
        {
            if (nums.find(num) != nums.end())
            {
                cout << "Yes\n";
            }
            else
                cout << "No\n";
        }
    }

    return 0;
}