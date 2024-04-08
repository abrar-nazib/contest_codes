#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void cin_the_rest(int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        bool flag = 0;
        unordered_set<int> in_matrix;
        vector<int> in_v;
        cin >> n >> c >> d;
        int matrix_len = n * n, min_elem = 0;

        for (int i = 0; i < matrix_len; i++)
        {
            int elem;
            cin >> elem;
            in_matrix.insert(elem);
            min_elem = min(elem, min_elem);
        }
        in_v.push_back(min_elem);
        for (int i = 1; i < n * n; i++)
        {
            if (i % n != 0)
            {
                if (in_matrix.find(in_v[i - 1] + c) != in_matrix.end())
                {
                    in_v.push_back(in_v[i - 1] + c);
                }
                else
                {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (in_matrix.find(in_v[i - n] + d) != in_matrix.end())
                {
                    in_v.push_back(in_v[i - n] + d);
                }
                else
                {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "YES\n";
        }
    }

    return 0;
}