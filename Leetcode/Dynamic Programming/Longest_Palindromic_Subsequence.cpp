// Question asked in Amazon Google
// Finding the length of the Longest Palindromic Subsequence (GeeksForGeeks POTD - dated 19 July, 2023)

// Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    int longestPalinSubseq(string S)
    {
        int n = S.length();

        // Create a 2D table to store the lengths of palindromic subsequences
        int **dp = new int *[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = new int[n];
        }

        // All substrings of length 1 are palindromic (base case)
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        // Fill the table for substrings of length 2 and above
        for (int length = 2; length <= n; length++)
        {
            for (int i = 0; i < n - length + 1; i++)
            {
                int j = i + length - 1;
                if (S[i] == S[j] && length == 2)
                {
                    dp[i][j] = 2;
                }
                else if (S[i] == S[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // The value at dp[0][n-1] stores the length of the longest palindromic subsequence
        int result = dp[0][n - 1];

        // Deallocate the memory used for the 2D array
        for (int i = 0; i < n; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;

        return result;
    }
};