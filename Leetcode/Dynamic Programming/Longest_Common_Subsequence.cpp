// Question asked in Amazon Microsoft Paytm VmWare Citrix MakeMyTrip
// Finde length of longest subsequence present in both of them (GeeksForGeeks POTD - dated 10 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        int L[n + 1][m + 1];
        int i, j;

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    L[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else
                {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
        return L[n][m];
    }
};