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

std::vector<std::string> split(const std::string &s, const std::string &delimiter)
{
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);
    while (end != std::string::npos)
    {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    tokens.push_back(s.substr(start));
    tokens.pop_back();
    return tokens;
}
class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string out_str = "";
        for (string &str : strs)
        {
            out_str += (str + "willywonka");
        }
        // cout << out_str;
        return out_str;
    }

    vector<string> decode(string s)
    {
        vector<string> out_strs;
        const string sx = "willywonka";
        return split(s, sx);
    }
};
int main()
{
    Solution s;
    vector<string> test1 = {"neet", "code", "love", "you"};
    vector<string> test2 = {"we", "say", ":", "yes"};

    // Test encode function
    string encoded1 = s.encode(test1);
    string encoded2 = s.encode(test2);

    // Test decode function
    vector<string> decoded1 = s.decode(encoded1);
    vector<string> decoded2 = s.decode(encoded2);

    // Print results
    print_vector_elements(decoded1);
    print_vector_elements(decoded2);

    return 0;
}