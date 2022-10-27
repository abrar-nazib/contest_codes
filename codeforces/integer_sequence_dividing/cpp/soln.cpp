#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n, sum;
    cin >> n;
    sum = (int)n * (n + 1) * 0.5;
    cout << (int)sum % 2;
    return 0;
}