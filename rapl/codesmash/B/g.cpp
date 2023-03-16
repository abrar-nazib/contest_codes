#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

class Robot
{
    int x, y;
    string dir = "";

public:
    void update(vector<vector<int>> grid, string direct)
    {
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ui r, c, n, t;
    cin >> r, c, n, t;
    char c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (ui i = 0; i < r; i++)
    {
        for (ui j = 0; j < c; j++)
        {
            cin >> c;
            if (c == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    return 0;
}