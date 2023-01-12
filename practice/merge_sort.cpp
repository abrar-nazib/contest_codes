#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

const int N = 1e5 + 10;
int arr[N];

int merge(int l, int r, int mid)
{
    int l_size = mid - l + 1; // left size will include mid
    int l_arr[l_size + 1];    // +1 because last element will store int_max as extra.
    for (int i = 0; i < l_size; i++)
    {
        l_arr[i] = arr[l + i];
    }
    l_arr[l_size] = INT_MAX;

    int r_size = r - mid;  // right array does not include the mid element
    int r_arr[r_size + 1]; // +1 because last element will store int_max as extra.
    for (int i = 0; i < r_size; i++)
    {
        r_arr[i] = arr[mid + i + 1];
    }
    r_arr[r_size] = INT_MAX;

    // actual merging task starts
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i <= r; i++)
    {
    }
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}