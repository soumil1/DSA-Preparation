// Question asked in  Amazon Google SAP Labs
// Find the length of the longest substring with exactly K distinct characters [GeeksForGeeks POTD - dated 26 August, 2023]

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<char, int> map;
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = -1;

        while (j < n)
        {
            map[s[j]] = map[s[j]] + 1;

            if (map.size() < k)
            {
                j++;
            }
            else if (map.size() == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                while (map.size() > k)
                {
                    map[s[i]] = map[s[i]] - 1;
                    if (map[s[i]] == 0)
                    {
                        map.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};