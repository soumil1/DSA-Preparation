// Question asked in
// Find maximum energy required before he starts (GeeksForGeeks Contest 116 - dated 21 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long maximum_energy(int n, vector<int> &heights)
    {
        vector<int> ng(n, -1); // Next greater index
        stack<int> st;         // Stack for maintaining indices

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] > heights[st.top()])
            {
                ng[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> dp(n, 0); // Dynamic programming table
        for (int i = n - 1; i >= 0; i--)
        {
            if (ng[i] == -1)
            {
                dp[i] = heights[i];
            }
            else
            {
                dp[i] = heights[i] ^ dp[ng[i]];
            }
        }

        long long maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, (long long)dp[i]);
        }

        return maxi;
    }
};