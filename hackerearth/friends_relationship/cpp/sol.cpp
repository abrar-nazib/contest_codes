#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, n;
    cin >> cases;
    while (cases--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n * 2; j++)
            {
                if (j > i && j < (n * 2) - (i + 1))
                    cout << "#";
                else
                    cout << "*";
            }
            cout << "\n";
        }
    }
}