#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

struct Point
{
    int x, y;
};

// Calculate the area of a triangle given three points
double calculateTriangleArea(const Point &a, const Point &b, const Point &c)
{
    return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

// Calculate the maximum possible area of Q
double calculateMaxArea(const vector<Point> &polygon, int k)
{
    int n = polygon.size();
    double maxArea = 0.0;

    // Iterate over all possible combinations of a, b, and c vertices
    for (int i = 0; i < n; i++)
    {
        int bIndex = i;
        int cIndex = (i + k + 1) % n;

        // Calculate the area of Q using the current combination of vertices
        double area = calculateTriangleArea(polygon[i], polygon[bIndex], polygon[cIndex]);

        // Update the maximum area if the calculated area is larger
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;

        vector<Point> polygon(n);
        for (int i = 0; i < n; i++)
        {
            cin >> polygon[i].x >> polygon[i].y;
        }

        double maxArea = calculateMaxArea(polygon, k);
        cout << fixed << maxArea << endl;
    }

    return 0;
}
