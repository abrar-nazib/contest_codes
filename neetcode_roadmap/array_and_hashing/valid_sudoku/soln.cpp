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

int get_cell_number(int i, int j)
{
    return (i / 3) * 3 + j / 3;
}

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> freq_cols(9, vector<int>(9));
        vector<vector<int>> freq_rows(9, vector<int>(9));
        vector<vector<int>> x_boxes(9, vector<int>(9));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    freq_rows[i][(int)board[i][j] - '1'] += 1;
                    freq_cols[j][(int)board[i][j] - '1'] += 1;
                    x_boxes[get_cell_number(i, j)][(int)board[i][j] - '1'] += 1;
                    if (freq_rows[i][(int)board[i][j] - '1'] > 1 || freq_cols[j][(int)board[i][j] - '1'] > 1 || x_boxes[get_cell_number(i, j)][(int)board[i][j] - '1'] > 1)
                        return false;
                }
            }
        }
        // for (auto elem : freq_cols)
        // print_vector_elements(elem);

        return true;
    }
};

int main()
{
    Solution s;

    // Test case 1
    vector<vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << (s.isValidSudoku(board1) ? "true" : "false") << endl; // Expected output: true

    // Test case 2
    vector<vector<char>> board2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << (s.isValidSudoku(board2) ? "true" : "false") << endl; // Expected output: false

    return 0;
}