#include <bits/stdc++.h>
using namespace std;

#define DEBUG 1

vector<long long> printFibb(int n)
{
    // code here
    vector<long long> fibs;
    fibs.push_back(1);
    if (n <= 1)
        return fibs;
    fibs.push_back(1);
    for (int i = 2; i < n; i++)
    {
        fibs.push_back(fibs[i - 1] + fibs[i - 2]);
    }
    return fibs;
}

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<long long> fibs = printFibb(5);
    for (long long i : fibs)
    {
        cout << i << " ";
    }
    return 0;
}