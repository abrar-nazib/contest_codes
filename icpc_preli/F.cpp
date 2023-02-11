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

    unsigned long long test_cases;
    cin >> test_cases;
    string word;
    // vector<vector<string>> lines(test_cases, vector<string>(4));
    vector<string> line(4);
    map<string, unsigned int> bgc = {
        {"A+", 0},
        {"A-", 0},
        {"AB+", 0},
        {"AB-", 0},
        {"B+", 0},
        {"B-", 0},
        {"O+", 0},
        {"O-", 0}};
    map<string, unsigned int> year_count;
    // map<string, string> mail;
    map<string, string> years;
    map<string, string> time;
    map<string, string> blood_group;
    for (ui i = 0; i < test_cases; i++)
    {
        for (ui j = 0; j < 4; j++)
        {
            cin >> word;
            if (j == 2)
            {
                word = word.substr(6, word.length());
                line[j] = word;
            }
            else
                line[j] = word;
        }
        if (time.find(line[1]) == time.end())
        {
            years.insert({line[1], line[2]});
            blood_group.insert({line[1], line[3]});
            time.insert({line[1], line[0]});
        }

        else
        {
            if (time[line[2]] < line[0])
            {
                years[line[1]] = line[2];
                blood_group[line[1]] = line[3];
                time[line[1]] = line[0];
            }
        }
    }

    for (auto elema : time)
    {
        if (year_count.find(elema.first) != year_count.end())
        {
            year_count.insert({years[elema.first], 1});
        }
        else
        {
            year_count[years[elema.first]] += 1;
        }
        bgc[blood_group[elema.first]] += 1;
    }
    for (auto elemb : bgc)
    {
        if (elemb.first != "")
            cout << elemb.first << " " << elemb.second << "\n";
    }
    for (auto elemc : year_count)
    {
        if (elemc.first != "")
            cout << elemc.first << " " << elemc.second << "\n";
    }
    return 0;
}