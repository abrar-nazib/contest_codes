// Min Heap or Max Heap?
// Data coming always to a data store. Sometimes I need the maximum of the data or minimum of the data
// Retrieve min/max value in O(1) time complexity
// Container adaptor that provides constant time lookup for the largest or smallest element
// Cost of insertion and extraction is logarithmic
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> v = {23, 1, 17, 8, 15, 2, 14, 21, 13, 6, 20, 9, 4, 19, 7, 10, 3, 16, 12, 5};
    for (int &elem : v)
    {
        q.push(elem);
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
}