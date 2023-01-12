#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                // iter_swap(arr.begin() + i, arr.begin() + j);
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int data : arr)
    {
        cout << data << " ";
    }
}