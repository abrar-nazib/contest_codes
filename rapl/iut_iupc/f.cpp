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

    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        set<char> odd_set_1, odd_set_2, even_set_1, even_set_2, all_set_1, all_set_2;
        string str1, str2;
        cin >> str1 >> str2;
        if (str1.length() != str2.length())
        {
            cout << "NO\n";
            break;
        }
        for (int i = 0; i < str1.length(); i++)
        {
            if (i % 2 == 0)
            {
                even_set_1.insert(str1[i]);
                even_set_2.insert(str2[i]);
            }
            else
            {
                odd_set_1.insert(str1[i]);
                odd_set_2.insert(str2[i]);
            }
            all_set_1.insert(str1[i]);
            all_set_2.insert(str2[i]);
        }
        if (odd_set_1 == odd_set_2 && even_set_1 == even_set_2 && all_set_1 == all_set_2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}