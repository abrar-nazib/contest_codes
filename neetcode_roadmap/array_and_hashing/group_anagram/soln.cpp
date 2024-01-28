#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void show_vector_string(vector<string> &vect)
{
    for (auto elem : vect)
    {
        cout << elem << " ";
    }
    cout << "\n";
}

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> out;
        map<string, vector<string>> m;
        for (string &str : strs) // vectlen->N, O(N)
        {
            string tmp = str;             // tmp is a copy of str
            sort(tmp.begin(), tmp.end()); // strlen->M, O(MlogM)
            m[tmp].push_back(str);        // O(PlogP)
        }                                 // O(N) * O(MlogM) = O(NMlogM)

        for (auto &[_, x] : m)
        {
            out.push_back(x); // O(1)
        }                     // O(N)
        return out;
    }
};

int main()
{
    Solution s;
    vector<string> in1({"eat", "tea", "tan", "ate", "nat", "bat"}), in2({""}), in3({"a"});
    vector<vector<string>> out1, out2, out3;
    s.groupAnagrams(in1);
    s.groupAnagrams(in2);
    s.groupAnagrams(in3);
}