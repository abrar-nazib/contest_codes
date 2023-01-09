#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1

long long nth_fibonacchi(long long n)
{
    if (n <= 1)
    {
        return n;
    }
    return nth_fibonacchi(n - 1) + nth_fibonacchi(n - 2);
}

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long x = 2;
    cout << nth_fibonacchi(x) << endl;
    return 0;
}