#include <iostream>
#include <vector>

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

using namespace std;

struct LShape
{
    int r, c, h, w;
};

bool isValid(int n, int bi, int bj)
{
    // Check if the black cell is at a valid position
    return (bi >= 1 && bi <= n && bj >= 1 && bj <= n);
}

bool isCovered(const vector<vector<bool>> &grid, int r, int c)
{
    // Check if the cell at position (r, c) is covered
    return grid[r][c];
}

bool isValidLShape(const vector<vector<bool>> &grid, int r, int c, int h, int w)
{
    // Check if the L-shape is valid (does not exceed grid boundaries and covers only white cells)
    if (h < 0)
    {
        for (int i = r + h; i <= r; ++i)
        {
            if (isCovered(grid, i, c))
                return false;
        }
    }
    else
    {
        for (int i = r; i <= r + h; ++i)
        {
            if (isCovered(grid, i, c))
                return false;
        }
    }

    if (w < 0)
    {
        for (int j = c + w; j <= c; ++j)
        {
            if (isCovered(grid, r, j))
                return false;
        }
    }
    else
    {
        for (int j = c; j <= c + w; ++j)
        {
            if (isCovered(grid, r, j))
                return false;
        }
    }

    return true;
}

void coverWhiteCells(vector<vector<bool>> &grid, int r, int c, int h, int w)
{
    // Cover the white cells with the L-shape
    if (h < 0)
    {
        for (int i = r + h; i <= r; ++i)
        {
            grid[i][c] = true;
        }
    }
    else
    {
        for (int i = r; i <= r + h; ++i)
        {
            grid[i][c] = true;
        }
    }

    if (w < 0)
    {
        for (int j = c + w; j <= c; ++j)
        {
            grid[r][j] = true;
        }
    }
    else
    {
        for (int j = c; j <= c + w; ++j)
        {
            grid[r][j] = true;
        }
    }
}

void solve(int n, int bi, int bj)
{
    if (!isValid(n, bi, bj))
    {
        cout << "No" << endl;
        return;
    }

    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    grid[bi][bj] = true; // Mark the black cell as covered

    vector<LShape> shapes;

    // Iterate through all cells to cover the white cells with L-shapes
    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= n; ++c)
        {
            if (!isCovered(grid, r, c))
            {
                int h = bi - r;
                int w = bj - c;

                if (isValidLShape(grid, r, c, h, w))
                {
                    coverWhiteCells(grid, r, c, h, w);
                    shapes.push_back({r, c, h, w});
                }
                else
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    // Output the result
    cout << "Yes" << endl;
    cout << shapes.size() << endl;
    for (const auto &shape : shapes)
    {
        cout << shape.r << " " << shape.c << " " << shape.h << " " << shape.w << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, bi, bj;
    cin >> n >> bi >> bj;
    // cout << "hello";

    solve(n, bi, bj);
    return 0;
}
