#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector_elements(vector<T> &v)
{
    for (T &e : v)
    {
        cout << e << " ";
    }
    cout << "\n";
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int l = 0, r = matrix.size() * matrix[0].size() - 1;

        while (l <= r)
        {
            int m = (l + r) / 2;
            int i = m / matrix[0].size();

            int j = m % matrix[0].size();
            // matrix[0].size();
            // cout << "L: " << l << " R: " << r << " M: " << m << " -- " << i << " " << j << endl;
            if (target > matrix[i][j])
            {
                l = m + 1;
            }
            else if (target < matrix[i][j])
            {
                r = m - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    Solution solution;

    // Example 1
    vector<vector<int>> matrix1 = {{1}, {3}};
    int target1 = 3;
    bool output1 = solution.searchMatrix(matrix1, target1);
    cout << "Output 1: " << (output1 ? "true" : "false") << endl; // Should print false

    // Example 2
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 3;
    bool output2 = solution.searchMatrix(matrix2, target2);
    cout << "Output 2: " << (output2 ? "true" : "false") << endl; // Should print true

    return 0;
}