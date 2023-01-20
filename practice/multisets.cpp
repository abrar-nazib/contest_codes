#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // multiset<string> s;
    // s.insert("hello");
    // s.insert("world");
    // s.insert("ki");
    // s.insert("khobor");
    // s.insert("hello");
    // s.insert("ki");
    multiset<int> n;

    n.insert(1);
    n.insert(2);
    n.insert(4);
    n.insert(3);
    for (auto elem : n)
    {
        cout << elem << endl;
    }
    cout << endl;
    auto it = n.find(4);
    n.erase(it);
    n.insert(2);
    for (auto elem : n)
    {
        cout << elem << endl;
    }
    // cout << endl;
    // // auto it = s.find("hello");
    // // s.erase(it);
    // s.erase("hello");
    // for (auto elem : s)
    // {
    //     cout << elem << endl;
    // }
    // cout << *max_element(n.begin(), n.end()) << endl;
    // cout << *n.end() << endl;

    return 0;
}