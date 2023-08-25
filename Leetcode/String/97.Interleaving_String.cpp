#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
        {
            return false;
        }

        unordered_map<pair<int, int>, bool, hash_pair> dp;

        return dfs(s1, s2, s3, 0, 0, dp);
    }

private:
    struct hash_pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    bool dfs(const string &s1, const string &s2, const string &s3, int q, int r, unordered_map<pair<int, int>, bool, hash_pair> &dp)
    {
        if (q == s1.length() && r == s2.length())
        {
            return true;
        }
        if (dp.find(make_pair(q, r)) != dp.end())
        {
            return dp[make_pair(q, r)];
        }

        bool result = false;
        if (q < s1.length() && s1[q] == s3[q + r] && dfs(s1, s2, s3, q + 1, r, dp))
        {
            result = true;
        }
        if (r < s2.length() && s2[r] == s3[q + r] && dfs(s1, s2, s3, q, r + 1, dp))
        {
            result = true;
        }
        dp[make_pair(q, r)] = result;
        return result;
    }
};