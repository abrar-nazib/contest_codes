#include <bits/stdc++.h>
using namespace std;

#define DEBUG 1

void func(int n)
{
    if (n == 0)
        return;

    func(n - 1);
    cout << n << endl;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int fact = factorial(n);
    cout << fact << endl;
    return 0;
}