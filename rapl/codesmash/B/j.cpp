#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

string num_to_str(int num)
{
    string num_str = "0000";
    // cout << num;
    for (ui i = 0; i < 4; i++)
    {
        num_str[3 - i] = '0' + (num % 10);
        num = num / 10;
    }
    // cout << num_str;
    return num_str;
    // return to_string(num);
}
// int str_to_num(string str)
// {
//     int num = to_integer(str)
//         str_to_num
// }

int check_num(int num)
{
    int div = 10000 / num;
    if (div >= 0 && div < 10)
    {
        num = num;
    }
    else if (div >= 10 && div < 100)
    {
        num *= 10;
    }
    else if (div >= 100 && div < 1000)
    {
        num *= 100;
    }
    else
        num *= 1000;
    return num;
    // return div;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ui test_cases;
    cin >> test_cases;
    // string num_str, k;
    int num, k, div;
    string num_str;
    while (test_cases--)
    {
        cin >> num >> k;
        num = check_num(num);
        num_str = num_to_str(num);
        num_str = num_str.c_str();
        cout << sort(num_str, num_str + 4) << "\n";
    }

    return 0;
}