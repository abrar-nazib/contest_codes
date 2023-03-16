#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cell;
    cin >> cell;
    cell += 94;
    if (cell == 95)
        cout << "Alas! Farha is bitten by snake. She is now at 75.";

    else if (cell == 98)
        cout << "Alas! Farha is bitten by snake. She is now at 79.";
    else if (cell == 99)
        cout << "Farha is on ladder.";
    else if (cell == 100)
        cout << "Yay! Farha has won the game. She is now at 100.";
    else
        cout << "Nothing happened to her.";

    return 0;
}