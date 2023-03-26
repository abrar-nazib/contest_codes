#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

class Robot
{
public:
    int c, r;
    string dir = "";

    void set_vars(int cc, int rr, string dir)
    {
        this->c = cc;
        this->r = rr;
        this->dir = dir;
    }
    void flip()
    {
        if (this->dir == "L")
            this->dir = "R";
        else if (this->dir == "R")
            this->dir = "L";
        else if (dir == "U")
            this->dir = "D";
        else if (dir == "D")
            this->dir = "U";
    }
    void update(vector<vector<int>> grid, ui clm, ui row)
    {
        int cc = this->c;
        int rr = this->r;
        string dirx = this->dir;
        if (dirx == "L")
            cc--;
        else if (dirx == "R")
            cc++;
        else if (dirx == "U")
            rr--;
        else if (dirx == "D")
            rr++;
        // cout << this->r << " " << this->c << " " << this->dir << "\n";
        if ((cc > 0 && cc <= clm) && (rr > 0 && rr <= row))
        {
            if (grid[rr - 1][cc - 1])
            {
                this->c = cc;
                this->r = rr;
            }
            else
            {
                this->flip();
                return;
            }
        }
        else
        {
            this->flip();
            return;
        }
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
    int rr, cc;
    string dir;
    cin >> r >> c >> n >> t;
    char ch;
    vector<vector<int>> grid(r, vector<int>(c));
    vector<Robot> robots(n);
    for (ui i = 0; i < r; i++)
    {
        for (ui j = 0; j < c; j++)
        {
            cin >> ch;
            if (ch == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    for (ui i = 0; i < n; i++)
    {
        cin >> rr >> cc >> dir;
        robots[i] = Robot();
        robots[i].set_vars(cc, rr, dir);
    }
    for (ui i = 0; i < t; i++)
    {
        for (ui j = 0; j < n; j++)
        {
            cin >> rr >> cc >> dir;
            robots[j].update(grid, c, r);
        }
    }
    for (ui j = 0; j < n; j++)
    {
        cout << robots[j].r << " " << robots[j].c << " " << robots[j].dir;
        if (j != n - 1)
            cout << "\n";
    }
    return 0;
}