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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> output(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    output[i] = j - i;
                    break;
                }
            }
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