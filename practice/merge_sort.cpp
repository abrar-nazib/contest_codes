#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

const int N = 1e5 + 10;
int arr[N];

void merge(int l, int r, int mid)
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
        if (l_arr[l_i] <= r_arr[r_i])
        {
            arr[i] = l_arr[l_i];
            l_i++;
        }
        else
        {
            arr[i] = r_arr[r_i];
            r_i++;
        }
    }
}

void merge_sort(int l, int r)
{
    if (l == r) // if the array size is 1 -> array with single element
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n;
    int l = 0;
    int r = n - 1;
    while (n--)
    {
        cin >> x;
        arr[n] = x;
    }
    for (int i = 0; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    merge_sort(l, r);
    for (int i = 0; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}