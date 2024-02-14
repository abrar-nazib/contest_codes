#include <bits/stdc++.h>
using namespace std;

// 01312885874

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
// Instructions
// https://docs.google.com/document/d/1wCNSONwOLIE-JwWK8ZaRLy6MR_g-vnwf52Bq5X96A-E/edit

// Datasets
// https://drive.google.com/drive/folders/15QI0sD4h7ovdSGIahfKtKQHQBZIyrBCi

// Hard Datasets
// https://drive.google.com/drive/folders/1Df09PKe7TeAGItOm99Q3DK-Jl_6mCirv

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};

        vector<int> output(temperatures.size());
        pair<int, int> temp_element;
        stack<pair<int, int>> temp_stack;
        // temp_stack.push({temperatures[0], 0});
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (temp_stack.size() > 0 && temperatures[i] > temp_stack.top().first)
            {
                output[temp_stack.top().second] = i - temp_stack.top().second;
                temp_stack.pop();
            }
            temp_stack.push({temperatures[i], i});
        }

        return output;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> output1 = solution.dailyTemperatures(temperatures1);
    cout << "Output 1: ";
    for (const auto &num : output1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> temperatures2 = {30, 40, 50, 60};
    vector<int> output2 = solution.dailyTemperatures(temperatures2);
    cout << "Output 2: ";
    for (const auto &num : output2)
    {
        cout << num << " ";
    }
    cout << endl;

    // Example 3
    vector<int> temperatures3 = {30, 60, 90};
    vector<int> output3 = solution.dailyTemperatures(temperatures3);
    cout << "Output 3: ";
    for (const auto &num : output3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}